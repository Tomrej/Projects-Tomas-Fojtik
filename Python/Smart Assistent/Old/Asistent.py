# imports libraries
import speech_recognition as sr
import subprocess
import webbrowser
import requests
from bs4 import BeautifulSoup
import pyttsx3
import pywhatkit
import datetime
import wikipedia
import pyjokes
import random
from PyQt5 import QtCore, QtGui, QtWidgets 

listener = sr.Recognizer()  # listen
engine = pyttsx3.init()     # pronounces the text

Y = "\t \t \t \t \t \t \t \t \t"
A = ""
hello = ["Hi", "Hello", "See you", "Cheerio", "Ahoy"]
functionsList= ["Hi!", "Hello!", "what can you do?", "How are you?", "Play MrBeast on Youtube.", "nothing", "stop", "time", "what's the time?", "time", "What's the date?", "date", "What is python?", "who is MrBeast?", "joke", "Tell me a joke", "how old are you?"]
mood = ["I am fine.", "I'm good.", "I'm happy!", "OK", "Good"]

import Asistent_CZ

# pronounce the text (function)
def talk(text):
  engine.say(text)
  engine.runAndWait()

#Main window
class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(1002, 664)
        MainWindow.setStyleSheet("background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(7, 11, 34, 255), stop:0.9801 rgba(0, 22, 76, 255));\n"
"border-color: rgb(255, 255, 255);\n"
"color: rgb(255, 255, 255);")
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.gridLayout = QtWidgets.QGridLayout(self.centralwidget)
        self.gridLayout.setObjectName("gridLayout")
        self.labelA = QtWidgets.QLabel(self.centralwidget)
        font = QtGui.QFont()
        font.setPointSize(18)
        self.labelA.setFont(font)
        self.labelA.setStyleSheet("background-color: rgba(255, 255, 255, 0);")
        self.labelA.setAlignment(QtCore.Qt.AlignLeading|QtCore.Qt.AlignLeft|QtCore.Qt.AlignVCenter)
        self.labelA.setObjectName("labelA")
        self.gridLayout.addWidget(self.labelA, 0, 0, 1, 1)
        self.AUText = QtWidgets.QTextBrowser(self.centralwidget)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.AUText.setFont(font)
        self.AUText.setStyleSheet("QScrollBar:Vertical{\n"
"    border: none;\n"
"    background-color: rgb(34, 6, 64);\n"
"}\n"
"QScrollBar::handle:vertical{\n"
"    \n"
"    background-color: rgb(75, 14, 149);\n"
"}\n"
"QScrollBar::handle:vertical:hover{\n"
"    \n"
"    background-color: rgb(165, 0, 83);\n"
"}")
        self.AUText.setVerticalScrollBarPolicy(QtCore.Qt.ScrollBarAlwaysOn)
        self.AUText.setHorizontalScrollBarPolicy(QtCore.Qt.ScrollBarAlwaysOff)
        self.AUText.setSizeAdjustPolicy(QtWidgets.QAbstractScrollArea.AdjustIgnored)
        self.AUText.setObjectName("AUText") 
        self.gridLayout.addWidget(self.AUText, 1, 0, 1, 4)
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        font = QtGui.QFont()
        font.setPointSize(18)
        self.label_3.setFont(font)
        self.label_3.setStyleSheet("background-color: rgba(255, 255, 255, 0);")
        self.label_3.setAlignment(QtCore.Qt.AlignRight|QtCore.Qt.AlignTrailing|QtCore.Qt.AlignVCenter)
        self.label_3.setObjectName("label_3")
        self.gridLayout.addWidget(self.label_3, 0, 3, 1, 1)
        spacerItem = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout.addItem(spacerItem, 2, 0, 1, 1)
        spacerItem1 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout.addItem(spacerItem1, 2, 2, 1, 1)
        self.pushButton = QtWidgets.QPushButton(self.centralwidget)
        self.pushButton.setEnabled(True)
        font = QtGui.QFont()
        font.setPointSize(12)
        font.setBold(False)
        font.setWeight(50)
        font.setKerning(True)
        self.pushButton.setFont(font)
        self.pushButton.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.pushButton.setStyleSheet("")
        self.pushButton.setObjectName("start")
        self.pushButton.clicked.connect(self.talkAndStart)
        self.gridLayout.addWidget(self.pushButton, 2, 1, 2, 1)
        self.AUText.raise_()
        self.labelA.raise_()
        self.label_3.raise_()
        self.pushButton.raise_()
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 1002, 26))
        self.menubar.setObjectName("menubar")
        self.menuSettings = QtWidgets.QMenu(self.menubar)
        self.menuSettings.setObjectName("menuSettings")
        self.menuHelp = QtWidgets.QMenu(self.menubar)
        self.menuHelp.setObjectName("menuHelp")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.menubar.addAction(self.menuSettings.menuAction())
        self.menubar.addAction(self.menuHelp.menuAction())

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)
    def run(self):
      stop = False
      while stop == False:
          try:   
            # Microphone
            with sr.Microphone() as source:
              voice = listener.listen(source)
              command = listener.recognize_google(voice)  #google speech recognizer
              command = command.lower()
              if "on youtube" in command:     #open on youtube
                ytthink = command.replace('on youtube', '')
                ytthink = command.replace('play', '')
                ytthink = command.replace('search', '')
                self.AUText.append(Y + command)
                talk("Opening " + ytthink + " on youtube")
                self.AUText.append("Opening " + ytthink + " on youtube")
                pywhatkit.playonyt(ytthink)
                talk("do you want anything else?")
                self.AUText.append("do you want anything else?")
              elif "hello" in command or "hi" in command:               #if "something" in command then...
                hi = random.choice(hello)
                self.AUText.append(Y + command)
                talk(hi)
                self.AUText.append(hi)
                talk("what do you want")
                self.AUText.append("what do you want?")
              elif "what can you do" in command:
                functions = random.choice(functionsList)
                functionTalk = functions.replace("!", "")
                self.AUText.append(Y + command)
                self.AUText.append("You can say for example: " + functions)
                talk("You can say for example" + functionTalk)
                talk("do you want anything else")
                self.AUText.append("Do you wan't anything else?")
              elif "how are you" in command: 
                self.AUText.append(Y + command)
                moods = random.choice(mood)
                talk(moods)
                talk("Thanks")
                self.AUText.append(moods + " Thanks.")
                talk("do you want anything else")
                self.AUText.append("Do you wan't anything else?")
              elif "no" in command and command != "open notepad" or "stop" in command or "end" in command or "nothing" in command:
                self.AUText.append(Y + command)
                talk("Stopping")
                self.AUText.append("Stopping")
                stop = True
              elif "quit" in command or "turn off" in command:
                self.AUText.append(Y + command)
                talk("bye sir")
                self.AUText.append("Bye sir!")
                break
              elif "time" in command:
                self.AUText.append(Y + command)
                time =  datetime.datetime.now().strftime('%H:%M')
                talk("Current time is" + time)
                self.AUText.append("Current time is" + time) 
                talk("do you want anything else")
                self.AUText.append("Do you wan't anything else?")
              elif "date" in command or "day" in command:          
                self.AUText.append(Y + command)
                date = datetime.datetime.now().strftime("%D")
                talk("today is " + date)
                self.AUText.append("Today is " + date)
                talk("do you want anything else")
                self.AUText.append("Do you wan't anything else?")
              elif "what is" in command or "who" in command:       #what is, or who is ...
                self.AUText.append(Y + command)
                person = command.replace("what is", "")
                something = wikipedia.summary(person, 1)
                talk("Finding")
                self.AUText.append("Finding...")
                talk(something)
                self.AUText.append(something)
                talk("do you want anything else")
                self.AUText.append("Do you wan't anything else?")
              elif "open" in command:
                self.AUText.append(Y + command)
                if "google" in command:
                  talk("opening google chrome")
                  self.AUText.append("Opening google chrome")
                  subprocess.call(['C:\Program Files\Google\Chrome\Application\\chrome.exe'])
                elif "notepad" in command:
                  talk("opening notepad")
                  self.AUText.append("opening notepad")
                  subprocess.call(["C:\WINDOWS\system32\\notepad.exe"])
                elif "spotify" in command:
                  talk("opening spotify")
                  self.AUText.append("Opening spotify.")
                  subprocess.call(["C:/Users/42073/AppData/Local/Microsoft/WindowsApps/SpotifyAB.SpotifyMusic_zpdnekdrzrea0//spotify.exe"])
                elif "teams online" in command:
                  talk("opening teams online")
                  self.AUText.append("Openning teams online")
                  mr = "https://teams.microsoft.com/"
                  webbrowser.open_new_tab(mr)
                else:
                  talk("I am beta version I cant do it for now")
                  self.AUText.append("I am beta version. I cant do it for now.")
                talk("do you want anything else")
                self.AUText.append("do you want anything else?")
              elif "on google" in command:
                terms = command.replace("search on google", "")
                search_terms = [terms]
                for term in search_terms:
                  url = "https://www.google.com.tr/search?q={}".format(term)
                  webbrowser.open_new_tab(url)
                talk("do you want anything else")
                self.AUText.append("Do you want anything else?")
              elif "morning" in command:
                time = datetime.datetime.now().strftime('%H:%M')
                date = datetime.datetime.now().strftime("%D")
                talk("good morning sir")
                talk("today its " + date)
                talk("its " + time)
                self.AUText.append("Good morning sir. Today it's " + date + " .It's" + time)
                urlW = "https://weather.com/en-GB/weather/today/l/0db6a61d2e5135219cc8aad728f227b3ba9331c0b00530ad33f4974c8bad66d2"
                page = requests.get(urlW)
                soup = BeautifulSoup(page.content, "html.parser")
                location = soup.find("h1", class_="CurrentConditions--location--1Ayv3").text
                temperature = soup.find("span", class_="CurrentConditions--tempValue--3KcTQ").text
                weatherPrediction = soup.find("div", class_="CurrentConditions--phraseValue--2xXSr").text
                talk("Today its in " + location + temperature + weatherPrediction)
                self.AUText.append("Today its in " + location + temperature + weatherPrediction)
                urlC = "https://www.tiscali.cz/"
                page = requests.get(urlC)
                soup = BeautifulSoup(page.content, "html.parser")
                information = soup.find("p", class_="large").text
                talk("new infected: " + information)
                self.AUText.append("New infected: " + information)
                mr = "https://teams.microsoft.com/_#/calendarv2"
                talk("opening your teams calendar")
                self.AUText.append("opening your teams calendar")
                webbrowser.open_new_tab(mr)
                talk("Here you have news")
                self.AUText.append("Here you have news.")
                seznam = "https://www.seznam.cz/"
                webbrowser.open_new_tab(seznam)
                talk("Do you want anything else")
                self.AUText.append("Do you want anything else?")
              elif "weather" in command:
                urlW = "https://weather.com/en-GB/weather/today/l/0db6a61d2e5135219cc8aad728f227b3ba9331c0b00530ad33f4974c8bad66d2"
                page = requests.get(urlW)
                soup = BeautifulSoup(page.content, "html.parser")
                location = soup.find("h1", class_="CurrentConditions--location--1Ayv3").text
                temperature = soup.find("span", class_="CurrentConditions--tempValue--3KcTQ").text
                weatherPrediction = soup.find("div", class_="CurrentConditions--phraseValue--2xXSr").text
                rain = soup.find("div", class_="CurrentConditions--precipValue--RBVJT").text
                talk("Today its in " + location + temperature + weatherPrediction + " " + rain)
                self.AUText.append("Today its in " + location + temperature + weatherPrediction + " " + rain)
                talk("do you want anything else")
                self.AUText.append("Do you want anything else sir?")
              elif "corona" in command or "covid" in command:
                url = "https://www.tiscali.cz/"
                page = requests.get(url)
                soup = BeautifulSoup(page.content, "html.parser")
                information = soup.find("p", class_="large").text
                talk("new infected: " + information)
                self.AUText.append("New infected: " + information)
                talk("do you want anything else")
                self.AUText.append("Do you want anything else?")
              elif "joke" in command:
                self.AUText.append(Y + command)
                joke = pyjokes.get_joke()
                self.AUText.append(joke)
                talk(joke)
                talk("do you want anything else")
                self.AUText.append("Do you wan't anything else?")
              elif "how old are you" in command:
                self.AUText.append(Y + command)
                talk('I was created at year 2021')
                self.AUText.append("I was created at year 2021")
                talk("do you want anything else")
                self.AUText.append("Do you wan't anything else?")
              elif "yes" in command:
                self.AUText.append("What do you wan't?")
                talk("what do you wan't")
              else:
                self.AUText.append(Y + command)
                talk("I don't know or I can't do this")
                talk("Sorry")
                self.AUText.append("I don't know, or I can't do this. Sorry.")  
                talk("do you want anything else")
                self.AUText.append("Do you wan't anything else?")
          except:
            pass
    def talkAndStart(self):
        self.AUText.append(A + "What do you want?")
        talk("What do you want")
        self.run()    
    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "Asistent"))
        self.labelA.setText(_translate("MainWindow", "Asistent"))
        self.AUText.setHtml(_translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:\'MS Shell Dlg 2\'; font-size:20pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>"))
        self.label_3.setText(_translate("MainWindow", "You"))
        self.pushButton.setText(_translate("MainWindow", " Start"))
        self.menuSettings.setTitle(_translate("MainWindow", "Settings"))
        self.menuHelp.setTitle(_translate("MainWindow", "Help"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())