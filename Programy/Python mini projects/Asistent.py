#importuje knihovny
import speech_recognition as sr
import pyttsx3
import pywhatkit
import datetime
import wikipedia
import pyjokes

listener = sr.Recognizer()  #poslouchá
engine = pyttsx3.init()     #vyslovuje text

#vysloví text (funkce)
def talk(text):
  engine.say(text)
  engine.runAndWait()

talk("What do you want")

def run():
  try:
    #Funkce mikrofonu
    with sr.Microphone() as source:
      print('listening...') #oznamuje že poslouchá
      voice = listener.listen(source)
      command = listener.recognize_google(voice)  #google rozpoznávač řeči
      command = command.lower()

      if "hello" in command:               #pokud uslyší "příklad" udělá...
        print(command)
        talk("Hi")
        print("Hi!")
        talk("what do you want")
        print("what do you want?")
        run()
      elif "how are you" in command:    #jak se máš
        print(command)
        talk("I am fine")
        talk("Thanks")
        print("I am fine. Thanks.")
        talk("do you want anything else")
        print("Do you wan't anything else?")
        run()
      elif "on youtube" in command:     #vyhledej na YT
        ytthink = command.replace('on youtube', '')
        ytthink = command.replace('play', '')
        ytthink = command.replace('search', '')
        talk("opening" + ytthink)
        print("opening youtube")
        pywhatkit.playonyt(ytthink)
      elif "nothing" in command:        #nedělej nic
        print(command)
        talk("Stopping")
        print("Stopping")
      elif "end" in command:        #nedělej nic
        print(command)
        talk("Stopping")
        print("Stopping")
      elif "stop" in command:        #nedělej nic
        print(command)
        talk("Stopping")
        print("Stopping")
      elif "no" in command:        #nedělej nic
        print(command)
        talk("Stopping")
        print("Stopping")
      elif "time" in command:           #co je za čas?
        print(command)
        time =  datetime.datetime.now().strftime('%H:%M')
        talk("Current time is" + time)
        print("Current time is" + time) 
        talk("do you want anything else")
        print("Do you wan't anything else?")
        run()
      elif "date" in command:          #co je za datum?
        print(command)
        date = datetime.datetime.now().strftime("%D")
        talk("today is " + date)
        print("Today is " + date)
        talk("do you want anything else")
        print("Do you wan't anything else?")
        run()
      elif "day" in command:           #co je za datum?
        print(command)
        date = datetime.datetime.now().strftime("%D")
        talk("today is " + date)
        print("Today is " + date)
        talk("do you want anything else")
        print("Do you wan't anything else?")
        run()
      elif "what is" in command:       #kdo je, nebo co je
        print(command)
        person = command.replace("what is", "")
        something = wikipedia.summary(person, 1)
        talk("Finding")
        print("Finding")
        talk(something)
        print(something)
        talk("do you want anything else")
        print("Do you wan't anything else?")
        run()
      elif "who is" in command:       #kdo je, nebo co je
        print(command)
        person = command.replace("who is", "")
        something = wikipedia.summary(person, 1)
        talk("Finding")
        print("Finding")
        talk(something)
        print(something)
        talk("do you want anything else")
        print("Do you wan't anything else?")
        run()
      elif "joke" in command:
        print(command)
        joke = pyjokes.get_joke()
        print(joke)
        talk(joke)
        talk("do you want anything else")
        print("Do you wan't anything else?")
        run()
      elif "how old are you" in command:
        print(command)
        talk('I am 9999924856764239955412139 years old')
        print("I am 9999924856764239955412139 years old")
        talk("do you want anything else")
        print("Do you wan't anything else?")
        run()
      elif "yes" in command:
        print("What do you wan't?")
        talk("what do you wan't")
        run()
      else:                             #něco jiného
        print(command)
        talk("I don't know or I can't do this")
        talk("Sorry")
        print("I don't know, or I can't do this. Sorry.")  
        talk("do you want anything else")
        print("Do you wan't anything else?")
        run()
  except:
    pass
run()