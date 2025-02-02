from functions import recognize, say
from Main import english

import random
from datetime import datetime

time = datetime.now().strftime("%H")

WAKE_UP = ["brain", "brian", "bring"]
greetings = ["Hello sir, pleasure to see you", "Need anything? I am ready",
             "How do you do? Can I do something for you?", f"Hi, current time is {time}. How can I help?", "System is running", "TIME", "TIME"]

while True:
    command = ""
    command = recognize()
    for word in WAKE_UP:
        if word in command:
            time = datetime.now().strftime("%H")
            fullTime = datetime.now().strftime("%H,%M")
            greeting = random.choice(greetings)
            if greeting == "TIME":
                time = int(time)
                if time <= 10:
                    say(
                        f"Wish you great morning sir. Currently is {fullTime}. How can I help you?")
                elif time <= 13 and time > 10:
                    say(
                        f"What a great noon. Currently is {fullTime}. What can I do for you?")
                elif time <= 20 and time > 13:
                    say(
                        f"Have a nice afternoon. It's {fullTime}. How can I serve you?")
                elif time > 20:
                    say(
                        f"Tonight is a wonderful evening. The time is: {fullTime}. What you need?")
                else:
                    say(
                        f"Weird. I can't access current time, or I have some problem. The time I got is: {fullTime}. How can I help you?")
            else:
                say(greeting)
            english()
