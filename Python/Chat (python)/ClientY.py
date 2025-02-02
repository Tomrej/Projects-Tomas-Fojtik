import threading
import socket
import datetime
from rich import print
import json

#client class for handling information and all the functions.
class client():
    def __init__(self, host, port):
        self.host = host
        self.port = port
        self.username = None
        self.connected = False
    
    #trys to connect to server until succesful
    def connect(self, client):
        while self.connected == False:
            if client.connect_ex((self.host, self.port)) == 0:               
                #once it is able to connect it will start the login process
                print('Connected!')
                self.connected = True
                self.login(client)

    #takes in user login data and sends it to the server for 'sign in' / identifacation
    def login(self, client):
        while True:
            self.username = input('Username: ')
            _password = input('Password: ')
            if len(self.username) >= 20 or len(_password) >= 20:
                print("You have exceeded the maximum input size")                
                continue
            break
        data = json.dumps({'username':self.username, 'password':_password})
        client.send(data.encode())
    
    #gets the current time on the user machine and formats it for the message
    @staticmethod
    def get_time():
        time = datetime.datetime.now()
        format = '%m/%d/%Y %I:%M %p'
        return (time.strftime(format))
    
    #sends the message to the server in JSON format for handling
    def send_message(self, client):
        while True:
            message = input()

            if len(message) > 200:
                print('Too Long!')
            else:
                #issue if the user were to change length cap and send more than 1024 bytes of data
                data = json.dumps({'username':self.username, 'message':message})
                client.send((str(len(data)).zfill(4) + data).encode())

    #recieves data from the server and formats / colors usernames and messages according to sender username
    def recv_message(self, client):
        while True:
            message_data = json.loads(client.recv(1024))
            message = f"{message_data['username']}: {message_data['message']}"

            if message_data['username'] == self.username: #Blue for your username
                print(f"[blue]{message[:len(self.username)]} [white]{message[len(self.username):]}[/white] [grey37]{self.get_time()}")
            elif message_data['username'] == 'Server':
                print(f"[yellow]{message[:6]} [white]{message[6:]}[/white] [grey37]{self.get_time()}")
            else:
                print(f"[red]{message[:len(message_data['username'])]} [white]{message[len(message_data['username']):]} [grey37]{self.get_time()}")
    
    #runs the client and starts both recieve and send threads
    def run_client(self):
        client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        self.connect(client)
        recv_thread = threading.Thread(target=self.recv_message, args=(client,))
        recv_thread.start()
        message_thread = threading.Thread(target=self.send_message, args=(client,))
        message_thread.start()

Client = client('127.0.0.1', 9090)
Client.run_client()