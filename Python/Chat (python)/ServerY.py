import asyncio
import json
import socket

clients = []
ip_banned = []
banned_usernames = []

#broadcasts the message to all users.
async def broadcast(message):
    for client in clients:
        loop = asyncio.get_event_loop()
        await loop.sock_sendall(client, message)

#client function task for each client that connects.
async def handle_client(client):
    loop = asyncio.get_event_loop()
    
    while True:
        try:
            data = ((await loop.sock_recv(client, 1024)).decode())
        except ConnectionResetError()():
            client.close()
            clients.remove(client)
            return

        for client in clients:
            print(client)
        
        if len(data) >= 4:
            message_length = data[:4]
            #checks if the message header is eqaul to the message length
            if message_length.isnumeric():
                if int(message_length) == len(data[4:]):
                    try:
                        #trys to load message as json to convert to dict
                        data = json.loads(data[4:]) 

                        if len(data['message']) > 200:
                            message = json.dumps({'username':'Server', 'message':'Message too large'}).encode()
                            await loop.sock_sendall(client, message)
                        else:
                            data = json.dumps({'username':data['username'], 'message':data['message']}).encode()                        
                            await broadcast(data)
                    #This is if the message isnt a JSON sent by a 3rd party client
                    except json.JSONDecodeError:
                        pass
                    #If a JSON was sent by a third party client and there is no such key in the dict
                    except KeyError:
                        pass
                else:
                    message = json.dumps({'username':'Server', 'message':'Message too large'}).encode()
                    await loop.sock_sendall(client, message)

#runs server accepting connnections and setting up clients.
async def run_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(('localhost', 9090))
    server.listen(5)
    server.setblocking(False)

    loop = asyncio.get_event_loop()
    while True:
        client, addr = await loop.sock_accept(server)
        clients.append(client)
        login_data = json.loads((await loop.sock_recv(client, 1024)).decode())
        print(login_data)
        print(addr)
        
        loop.create_task(handle_client(client))

asyncio.run(run_server())