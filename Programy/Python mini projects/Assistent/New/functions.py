import pyttsx3
import speech_recognition as sr

engine = pyttsx3.init()


def recognize():
    recognizer = sr.Recognizer()
    with sr.Microphone() as source:
        recognizer.adjust_for_ambient_noise(source, duration=0.2)
        print("Talk")

        audio = recognizer.listen(source)

        command = ""

        # If user is offline uses sphinx, else uses google speech recognition
        try:
            try:
                command = recognizer.recognize_google(audio)
            except:
                print("offline mode")
                command = recognizer.recognize_sphinx(audio)
            command.lower()
            return command
        except:
            print("Command was not recognized")
        print(command)


def say(text):
    # this will say sentence
    engine.say(text)
    engine.runAndWait()
    print(text)


def convertTime(seconds):
    minutes, seconds = divmod(seconds, 60)
    hours, minutes = divmod(minutes, 60)
    return "%d:%02d:%02d" % (hours, minutes, seconds)
