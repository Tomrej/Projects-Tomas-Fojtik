from distutils import command
import psutil
import wolframalpha

from functions import say, convertTime, recognize

client = wolframalpha.Client("XY24G6-R9PYPL9GYR")


def english():
    while True:
        command = recognize()
        print("You:" + command)
        if "hi" in command:
            say("Hello!")
        elif "how" in command and "you" in command:

            battery = psutil.sensors_battery()
            cpu = psutil.cpu_percent(percpu=False, interval=1)

            if cpu > 90:
                say("My cpu is running " + cpu + ". I had better days")
            elif battery.power_plugged == True or battery.percent >= 25:
                say("I am doing great!")
            elif battery.percent < 25:
                say("I am fine, but the battery level is: " + battery.percent)

        elif "battery" in command:
            battery = psutil.sensors_battery()
            if battery.power_plugged == False:
                say(
                    f"Current battery level is: {battery.percent}%, battery will last {convertTime(battery.secsleft)}")
            else:
                say(
                    f"Current battery level is: {battery.percent}%, but power is plugged. That's great")

        elif "processor" in command:
            cpu = psutil.cpu_percent(percpu=False, interval=1)
            say(f"cpu is running at {cpu}")
        elif "exit" in command or "quit" in command or "stop" in command or "turn off" in command or "off" in command:
            say("Bye")
            break
        else:
            res = client.query(command)
            try:
                say(next(res.results).text)
            except:
                say("I am very sorry. I can't understand you. Do you need something else?")
