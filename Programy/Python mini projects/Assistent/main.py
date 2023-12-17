# imports libraries
from json import decoder
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
from wikipedia.wikipedia import languages

hello = ["Hi", "Hello", "See you", "Cheerio", "Ahoy"]
functionsList= ["Hi!", "Hello!", "what can you do?", "How are you?", "Play MrBeast on Youtube.", "nothing", "stop", "time", "what's the time?", "time", "What's the date?", "date", "What is python?", "who is MrBeast?", "joke", "Tell me a joke", "how old are you?"]
mood = ["I am fine.", "I'm good.", "I'm happy!", "OK", "Good"]
language = "EN"
Y = ""

listener = sr.Recognizer()
engine = pyttsx3.init()
# Functions

# pronounce the text
def talk(text):
  voices = engine.getProperty('voices')
  if language == "CZ":
    engine.setProperty('voice', voices[1].id)
  else:
    pass
  engine.say(text)
  engine.runAndWait()
  

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(965, 696)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.verticalLayout = QtWidgets.QVBoxLayout(self.centralwidget)
        self.verticalLayout.setContentsMargins(0, 0, 0, 0)
        self.verticalLayout.setObjectName("verticalLayout")
        self.scrollArea = QtWidgets.QScrollArea(self.centralwidget)
        self.scrollArea.setStyleSheet("setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );")
        self.scrollArea.setWidgetResizable(True)
        self.scrollArea.setObjectName("scrollArea")
        self.scrollAreaWidgetContents = QtWidgets.QWidget()
        self.scrollAreaWidgetContents.setGeometry(QtCore.QRect(0, 0, 963, 604))
        self.scrollAreaWidgetContents.setStyleSheet("setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );")
        self.scrollAreaWidgetContents.setObjectName("scrollAreaWidgetContents")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout(self.scrollAreaWidgetContents)
        self.verticalLayout_2.setObjectName("verticalLayout_2")
        def addTextY(text):
            self.you = QtWidgets.QHBoxLayout()
            self.you.setContentsMargins(9, 9, 9, 9)
            self.you.setSpacing(9)
            self.you.setObjectName("you")
            spacerItem = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
            self.you.addItem(spacerItem)
            self.label = QtWidgets.QLabel(self.scrollAreaWidgetContents)
            self.label.setEnabled(True)
            font = QtGui.QFont()
            font.setFamily("MS Shell Dlg 2")
            font.setPointSize(12)
            font.setBold(False)
            font.setWeight(50)
            self.label.setFont(font)
            self.label.setCursor(QtGui.QCursor(QtCore.Qt.ArrowCursor))
            self.label.setLayoutDirection(QtCore.Qt.RightToLeft)
            self.label.setAutoFillBackground(False)
            self.label.setStyleSheet("background-color: rgb(0, 252, 189);")
            self.label.setLineWidth(1)
            self.label.setAlignment(QtCore.Qt.AlignLeading|QtCore.Qt.AlignLeft|QtCore.Qt.AlignVCenter)
            self.label.setWordWrap(False)
            self.label.setObjectName("label")
            self.you.addWidget(self.label)
            self.verticalLayout_2.addLayout(self.you)
            self.label.setText(text)
        def addTextA(text):
            self.assistent = QtWidgets.QHBoxLayout()
            self.assistent.setObjectName("assistent")
            self.label_2 = QtWidgets.QLabel(self.scrollAreaWidgetContents)
            font = QtGui.QFont()
            font.setPointSize(12)
            self.label_2.setFont(font)
            self.label_2.setStyleSheet("background-color: rgb(208, 208, 208);")
            self.label_2.setObjectName("label_2")
            self.assistent.addWidget(self.label_2)
            spacerItem1 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
            self.assistent.addItem(spacerItem1)
            self.verticalLayout_2.addLayout(self.assistent)
            self.label_2.setText(text)
        def TalkAndTextA(text):
            talk(text)
            addTextA(text)
        def runEN(self):
            listener = sr.Recognizer()  # listen
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
                      addTextY(command)
                      TalkAndTextA("Opening " + ytthink + " on youtube")
                      pywhatkit.playonyt(ytthink)
                      TalkAndTextA("do you want anything else?")
                    elif "hello" in command or "hi" in command:               #if "something" in command then...
                      hi = random.choice(hello)
                      addTextY(command)
                      TalkAndTextA(hi)
                      TalkAndTextA("what do you want?")
                    elif "what can you do" in command:
                      functions = random.choice(functionsList)
                      functionTalk = functions.replace("!", "")
                      addTextY(command)
                      TalkAndTextA("You can say for example" + functionTalk)
                      TalkAndTextA("do you want anything else")
                    elif "how are you" in command: 
                      addTextY(command)
                      moods = random.choice(mood)
                      TalkAndTextA(moods + " Thanks")
                      TalkAndTextA("Do you want anything else?")
                    elif "no" in command and command != "open notepad" or "stop" in command or "end" in command or "nothing" in command:
                      addTextY(command)
                      TalkAndTextA("Stopping")
                      stop = True
                    elif "quit" in command or "turn off" in command:
                      addTextY(command)
                      TalkAndTextA("Bye sir!")
                      break
                    elif "time" in command:
                      addTextY(command)
                      time =  datetime.datetime.now().strftime('%H:%M')
                      TalkAndTextA("Current time is" + time) 
                      TalkAndTextA("Do you wan't anything else?")
                    elif "date" in command or "day" in command:          
                      addTextY(command)
                      date = datetime.datetime.now().strftime("%D")
                      TalkAndTextA("Today is " + date)
                      TalkAndTextA("Do you wan't anything else?")
                    elif "what is" in command or "who" in command:       #what is, or who is ...
                      addTextY(command)
                      person = command.replace("what is", "")
                      something = wikipedia.summary(person, 1)
                      TalkAndTextA("Finding")
                      TalkAndTextA(something)
                      TalkAndTextA("Do you wan't anything else?")
                    elif "open" in command:
                      addTextY(command)
                      if "google" in command:
                        TalkAndTextA("Opening google chrome")
                        subprocess.call(['C:\Program Files\Google\Chrome\Application\\chrome.exe'])
                      elif "notepad" in command:
                        TalkAndTextA("opening notepad")
                        subprocess.call(["C:\WINDOWS\system32\\notepad.exe"])
                      elif "spotify" in command:
                        TalkAndTextA("Opening spotify.")
                        subprocess.call(["C:/Users/42073/AppData/Local/Microsoft/WindowsApps/SpotifyAB.SpotifyMusic_zpdnekdrzrea0//spotify.exe"])
                      elif "teams online" in command:
                        TalkAndTextA("Openning teams online")
                        mr = "https://teams.microsoft.com/"
                        webbrowser.open_new_tab(mr)
                      else:
                        TalkAndTextA("I am beta version. I cant do it for now.")
                      TalkAndTextA("do you want anything else?")
                    elif "on google" in command:
                      addTextY(command)
                      terms = command.replace("search on google", "")
                      search_terms = [terms]
                      for term in search_terms:
                        url = "https://www.google.com.tr/search?q={}".format(term)
                        webbrowser.open_new_tab(url)
                      TalkAndTextA("Here you are")
                      TalkAndTextA("Do you want anything else?")
                    elif "morning" in command:
                      addTextY(command)  
                      time = datetime.datetime.now().strftime('%H:%M')
                      date = datetime.datetime.now().strftime("%D")
                      TalkAndTextA("Good morning sir. Today it's " + date + " .It's" + time)
                      urlW = "https://weather.com/en-GB/weather/today/l/0db6a61d2e5135219cc8aad728f227b3ba9331c0b00530ad33f4974c8bad66d2"
                      page = requests.get(urlW)
                      soup = BeautifulSoup(page.content, "html.parser")
                      location = soup.find("h1", class_="CurrentConditions--location--1Ayv3").text
                      temperature = soup.find("span", class_="CurrentConditions--tempValue--3KcTQ").text
                      weatherPrediction = soup.find("div", class_="CurrentConditions--phraseValue--2xXSr").text
                      TalkAndTextA("Today its in " + location + temperature + weatherPrediction)
                      urlC = "https://www.tiscali.cz/"
                      page = requests.get(urlC)
                      soup = BeautifulSoup(page.content, "html.parser")
                      information = soup.find("p", class_="large").text
                      TalkAndTextA("New infected: " + information)
                      mr = "https://teams.microsoft.com/_#/calendarv2"
                      TalkAndTextA("opening your teams calendar")
                      webbrowser.open_new_tab(mr)
                      TalkAndTextA("Here you have news.")
                      seznam = "https://www.seznam.cz/"
                      webbrowser.open_new_tab(seznam)
                      TalkAndTextA("Do you want anything else?")
                    elif "weather" in command:
                      urlW = "https://weather.com/en-GB/weather/today/l/0db6a61d2e5135219cc8aad728f227b3ba9331c0b00530ad33f4974c8bad66d2"
                      page = requests.get(urlW)
                      soup = BeautifulSoup(page.content, "html.parser")
                      location = soup.find("h1", class_="CurrentConditions--location--1Ayv3").text
                      temperature = soup.find("span", class_="CurrentConditions--tempValue--3KcTQ").text
                      weatherPrediction = soup.find("div", class_="CurrentConditions--phraseValue--2xXSr").text
                      rain = soup.find("div", class_="CurrentConditions--precipValue--RBVJT").text
                      addTextY(command)
                      TalkAndTextA("Today its in " + location + temperature + weatherPrediction + " " + rain)
                      TalkAndTextA("Do you want anything else sir?")
                    elif "corona" in command or "covid" in command:
                      url = "https://www.tiscali.cz/"
                      page = requests.get(url)
                      soup = BeautifulSoup(page.content, "html.parser")
                      information = soup.find("p", class_="large").text
                      addTextY(command)
                      TalkAndTextA("New infected: " + information)
                      TalkAndTextA("Do you want anything else?")
                    elif "joke" in command:
                      addTextY(command)
                      joke = pyjokes.get_joke()
                      TalkAndTextA(joke)
                      TalkAndTextA("Do you wan't anything else?")
                    elif "how old are you" in command:
                      addTextY(command)
                      TalkAndTextA("I was created at year 2021")
                      TalkAndTextA("Do you wan't anything else?")
                    elif "yes" in command:
                      TalkAndTextA("What do you wan't?")
                    else:
                      addTextY(command)
                      TalkAndTextA("I don't know, or I can't do this. Sorry.")  
                      TalkAndTextA("Do you wan't anything else?")
                except:
                  pass
        def TalkAndStart(self):
            TalkAndTextA("What do you want sir?")
            runEN(self)

        spacerItem2 = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.verticalLayout_2.addItem(spacerItem2)
        self.scrollArea.setWidget(self.scrollAreaWidgetContents)
        self.verticalLayout.addWidget(self.scrollArea)
        self.gridLayout = QtWidgets.QGridLayout()
        self.gridLayout.setObjectName("gridLayout")
        self.pushButton = QtWidgets.QPushButton(self.centralwidget)
        font = QtGui.QFont()
        font.setPointSize(10)
        self.pushButton.setFont(font)
        self.pushButton.setStyleSheet("gridline-color: rgb(217, 217, 217);")
        self.pushButton.setObjectName("pushButton")
        self.pushButton.clicked.connect(TalkAndStart)
        self.gridLayout.addWidget(self.pushButton, 0, 1, 1, 1)
        spacerItem3 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout.addItem(spacerItem3, 0, 0, 1, 1)
        spacerItem4 = QtWidgets.QSpacerItem(40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout.addItem(spacerItem4, 0, 2, 1, 1)
        self.verticalLayout.addLayout(self.gridLayout)
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 965, 26))
        self.menubar.setObjectName("menubar")
        self.menu = QtWidgets.QMenu(self.menubar)
        self.menu.setObjectName("menu")
        self.menuHelp = QtWidgets.QMenu(self.menubar)
        self.menuHelp.setObjectName("menuHelp")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)
        self.actionSettings = QtWidgets.QAction(MainWindow)
        self.actionSettings.setObjectName("actionSettings")
        self.actionExit = QtWidgets.QAction(MainWindow)
        self.actionExit.setObjectName("actionExit")
        self.actionReport_crash = QtWidgets.QAction(MainWindow)
        self.actionReport_crash.setObjectName("actionReport_crash")
        self.actionVisit_Discord = QtWidgets.QAction(MainWindow)
        self.actionVisit_Discord.setObjectName("actionVisit_Discord")
        self.actionAbout = QtWidgets.QAction(MainWindow)
        self.actionAbout.setObjectName("actionAbout")
        self.actionAlways_on_top = QtWidgets.QAction(MainWindow)
        self.actionAlways_on_top.setObjectName("actionAlways_on_top")
        self.menu.addAction(self.actionSettings)
        self.menu.addAction(self.actionExit)
        self.menuHelp.addAction(self.actionAbout)
        self.menuHelp.addSeparator()
        self.menuHelp.addAction(self.actionReport_crash)
        self.menuHelp.addAction(self.actionVisit_Discord)
        self.menubar.addAction(self.menu.menuAction())
        self.menubar.addAction(self.menuHelp.menuAction())
        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)
    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "Assistent Brain"))
        MainWindow.setWindowIcon(QtGui.QIcon("pictures/logo.png"))
        self.pushButton.setText(_translate("MainWindow", "Turn on"))
        self.menu.setTitle(_translate("MainWindow", "File"))
        self.menuHelp.setTitle(_translate("MainWindow", "Help"))
        self.actionSettings.setText(_translate("MainWindow", "Settings"))
        self.actionExit.setText(_translate("MainWindow", "Exit"))
        self.actionReport_crash.setText(_translate("MainWindow", "Report crash"))
        self.actionVisit_Discord.setText(_translate("MainWindow", "Visit Discord"))
        self.actionAbout.setText(_translate("MainWindow", "About"))
        self.actionAlways_on_top.setText(_translate("MainWindow", "Always on top"))
        

if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())