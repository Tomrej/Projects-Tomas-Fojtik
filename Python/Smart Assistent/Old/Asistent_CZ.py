# imports libraries
from requests.api import request
import speech_recognition as sr
import subprocess
import webbrowser
import requests
from bs4 import BeautifulSoup
import pyttsx3
import pywhatkit
import datetime
import random
from PyQt5 import QtCore, QtGui, QtWidgets 

listener = sr.Recognizer()  # listen
engine = pyttsx3.init('sapi5')     # pronounces the text
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[1].id)



Y = "\t \t \t \t \t \t \t \t \t"
A = ""
hello = ["Dobrý den", "Ahoj", "Rád vás vidím", "Nazdar"]
functionsList= ["Ahoj!", "Čau!", "Co umíš?", "Jak se máš?", "Přehraj Jaromír Nohavica na Youtube.", "nic nechci", "stop", "vypni se", "čas", "Kolik je hodin?", "Jaký je čas", "Jaké je datum?", "Kolikátého je dnes?", "datum", "co je to python?", "Kdo je Jaromír nohavica?", "vtip", "Řekni mi vtip", "Kolik ti je?"]
mood = ["Mám se dobře", "Jsem v pohodě", "Jsem šťastný", "OK", "Jde to"]

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
              command = listener.recognize_google(voice, language="CS")  #google speech recognizer
              command = command.lower()
              if "na youtube" in command:     #open on youtube
                self.AUText.append(Y + command)
                command.replace("na youtube", "")
                command.replace("vyhledej", "")
                command.replace(" ", "+")
                command.replace("vyhledej", "")
                command.replace("spusť", "")
                url = "https://www.youtube.com/results?search_query={}".format(command)
                talk("Otevírám " + command + " na youtube")
                self.AUText.append("Otevírám " + command + " na youtube")
                webbrowser.open_new_tab(url)
                talk("Chcete ještě něco pane?")
                self.AUText.append("Chcete ještě něco pane??")
              elif "čau" in command or "ahoj" in command or "nazdar" in command:               #if "something" in command then...
                hi = random.choice(hello)
                self.AUText.append(Y + command)
                talk(hi)
                self.AUText.append(hi)
                talk("Chcete ještě něco pane?")
                self.AUText.append("Chcete ještě něco pane?")
              elif "co umíš" in command:
                functions = random.choice(functionsList)
                functionTalk = functions.replace("!", "")
                self.AUText.append(Y + command)
                self.AUText.append("Můžete říct například: " + functions)
                talk("Můžete říct například: " + functionTalk)
                talk("Chcete ještě něco pane?")
                self.AUText.append("Chcete ještě něco pane?")
              elif "jak se máš" in command or "jak se cítíš" in command: 
                self.AUText.append(Y + command)
                moods = random.choice(mood)
                talk(moods)
                talk("Díky za optání pane")
                self.AUText.append(moods + ". Díky za optání pane.")
                talk("Přejete si něco dalšího pane?")
                self.AUText.append("Přejete si něco dalšího, pane?")
              elif "ne" in command and command != "jaké je dnes počasí" or "stop" in command or "konec" in command or "nic" in command:
                self.AUText.append(Y + command)
                talk("Ano pane")
                self.AUText.append("Ano pane")
                stop = True
              elif "vypni se" in command:
                self.AUText.append(Y + command)
                talk("Nashle")
                self.AUText.append("Nashle!")
                break
              elif "počasí zítra" in command:
                urlW = "https://weather.com/cs-CZ/weather/today/l/0db6a61d2e5135219cc8aad728f227b3ba9331c0b00530ad33f4974c8bad66d2"
                page = requests.get(urlW)
                soup = BeautifulSoup(page.content, "html.parser")
                location = soup.find("h1", class_="CurrentConditions--location--1Ayv3").text
                nextDay = soup.find("div", class_="Column--temp--2v_go").text
                rainNextDay = soup.find("div", class_="SegmentPrecipPercentage").text
                talk("zítra bude" + " " + nextDay + " " + ". Šance, že bude pršet je:" + " " + rain)
              elif "počasí" in command:
                urlW = "https://weather.com/cs-CZ/weather/today/l/0db6a61d2e5135219cc8aad728f227b3ba9331c0b00530ad33f4974c8bad66d2"
                page = requests.get(urlW)
                soup = BeautifulSoup(page.content, "html.parser")
                location = soup.find("h1", class_="CurrentConditions--location--1Ayv3").text
                temperature = soup.find("span", class_="CurrentConditions--tempValue--3KcTQ").text
                weatherPrediction = soup.find("div", class_="CurrentConditions--phraseValue--2xXSr").text
                rain = soup.find("div", class_="CurrentConditions--precipValue--RBVJT").text
                rainNextDay = soup.find("div", class_="SegmentPrecipPercentage").text
                if "zítra" in command:
                  talk("zítra bude" + " " + nextDay + " " + ". Šance, že bude pršet je:" + " " + rain)
                  self.AUText.append("zítra bude" + " " + nextDay + " " + ". Šance, že bude pršet je:" + " " + rainNextDay)
                else:  
                  talk("Dnes je v " + location + " " + temperature + " " + weatherPrediction + " " + rain)
                  self.AUText.append("Dnes je v " + location + " " + temperature + " " + weatherPrediction + " " + rain)
                talk("Přejete si ještě něco, pane?")
                self.AUText.append("Přejete si ještě něco, pane?")
              elif "čas" in command or "hodin" in command:
                self.AUText.append(Y + command)
                time =  datetime.datetime.now().strftime('%H:%M')
                talk("Aktuální čas je" + time)
                self.AUText.append("Aktuální čas je" + time) 
                talk("Potřebujete ještě něco?")
                self.AUText.append("Potřebujete ještě něco?")
              elif "datum" in command or "den" in command:          
                self.AUText.append(Y + command)
                date = datetime.datetime.now().strftime("%D")
                talk("Dnes je " + date)
                self.AUText.append("Dnes je: " + date + ", pane")
                talk("do you want anything else")
                self.AUText.append("Do you wan't anything else?")
              elif "kdo je" in command or "co je" in command:       #what is, or who is ...
                self.AUText.append(Y + command)
                person = command.replace("kdo je", "")
                person = command.replace("co je", "")
                person = command.replace(" ", "+")
                url = "https://cs.wikipedia.org/w/index.php?title=Speci%C3%A1ln%C3%AD:Hled%C3%A1n%C3%AD&search={}&go=Go&ns0=1&ns100=1&ns102=1".format(person)
                page = requests.get(url)
                soup = BeautifulSoup(page.content, "html.parser")
                search_terms = soup.find("div", class_="searchresult").text
                talk("Hledám")
                self.AUText.append("Hledám...")
                talk(search_terms)
                self.AUText.append(search_terms)
                talk("Přejete si něco dalšího?")
                self.AUText.append("Přejete si něco dalšího?")
              elif "otevři" in command:
                self.AUText.append(Y + command)
                if "google" in command or "chrome" in command:
                  talk("otevírám google chrome")
                  self.AUText.append("Otevírám google chrome.")
                  subprocess.call(['C:\Program Files\Google\Chrome\Application\\chrome.exe'])
                elif "notepad" in command or "poznámkový blok" in command:
                  talk("Otevírám notepad")
                  self.AUText.append("Otevírám notepad")
                  subprocess.call(["C:\WINDOWS\system32\\notepad.exe"])
                elif "spotify" in command:
                  talk("Otevírám spotify")
                  self.AUText.append("Otevírám spotify.")
                  subprocess.call(["C:/Users/42073/AppData/Local/Microsoft/WindowsApps/SpotifyAB.SpotifyMusic_zpdnekdrzrea0//spotify.exe"])
                elif "teams online" in command:
                  talk("Otevírám teams online")
                  self.AUText.append("Otevírám teams online")
                  mr = "https://teams.microsoft.com/"
                  webbrowser.open_new_tab(mr)
                else:
                  talk("Omlovám se ale tohle otevřít neumím, do příště se to doučím")
                  self.AUText.append("Omlovám se ale tohle otevřít neumím, do příště se to doučím!")
                talk("Máte ještě nějaký požadavek")
                self.AUText.append("Máte ještě nějaký požadavek?")
              elif "na googlu" in command:
                terms = command.replace("vyhledej na googlu", "")
                search_terms = [terms]
                for term in search_terms:
                  url = "https://www.google.com.tr/search?q={}".format(term)
                  webbrowser.open_new_tab(url)
                talk("Přejete si ještě něco?")
                self.AUText.append("Přejete si ještě nečo?")
              elif "dobré ráno" in command or "dobrý večer":
                time = datetime.datetime.now().strftime('%H:%M')
                date = datetime.datetime.now().strftime("%D")
                talk("Dobré ráno, pane")
                talk("Dnes je " + date)
                talk("Aktuálně je: " + time)
                self.AUText.append("Dobré ráno pane, dnes je: " + date + " . Aktuálně je: " + time)
                urlW = "https://weather.com/cs-CZ/weather/today/l/0db6a61d2e5135219cc8aad728f227b3ba9331c0b00530ad33f4974c8bad66d2"
                page = requests.get(urlW)
                soup = BeautifulSoup(page.content, "html.parser")
                location = soup.find("h1", class_="CurrentConditions--location--1Ayv3").text
                temperature = soup.find("span", class_="CurrentConditions--tempValue--3KcTQ").text
                weatherPrediction = soup.find("div", class_="CurrentConditions--phraseValue--2xXSr").text
                talk("Dnes je v " + location + " " + temperature + " " + weatherPrediction)
                self.AUText.append("Dnes je v " + location + temperature + weatherPrediction)
                urlC = "https://www.tiscali.cz/"
                page = requests.get(urlC)
                soup = BeautifulSoup(page.content, "html.parser")
                information = soup.find("p", class_="large").text
                talk("nových nakažených je: " + information)
                self.AUText.append("nových nakažených je: " + information)
                mr = "https://teams.microsoft.com/_#/calendarv2"
                talk("Otevírám vám váš kalendář online hodin")
                self.AUText.append("Otevírám vám váš kalendář online hodin")
                webbrowser.open_new_tab(mr)
                talk("Tady máte novinky")
                self.AUText.append("Tady máte novinky.")
                seznam = "https://www.seznam.cz/"
                webbrowser.open_new_tab(seznam)
                talk("Přejete si ode mne ještě něco?")
                self.AUText.append("Přejete si ode mne ještě něco?")
              elif "korona" in command or "kovid" in command:
                url = "https://www.tiscali.cz/"
                page = requests.get(url)
                soup = BeautifulSoup(page.content, "html.parser")
                information = soup.find("p", class_="large").text
                talk("Nový nakažení: " + information)
                self.AUText.append("Nový nakažení: " + information)
                talk("Přejete si ještě něco?")
                self.AUText.append("Přejete si ještě něco?")
              elif "vtip" in command:
                self.AUText.append(Y + command)
                talk('vtipy nejsou aktuálně funkční')
                self.AUText.append('Vtipy nejsou aktuálně funkční')
                talk("Přejete si ještě něco?")
                self.AUText.append("Přejete si ještě něco?")
              elif "jak si starý" in command or "kolik ti je" in  command:
                self.AUText.append(Y + command)
                talk('Moje anglická verze byla vytvořena roku 2021. Já byl vytvořen o pár měsíců později')
                self.AUText.append("Moje anglická verze byla vytvořena roku 2021. Já byl vytvořen o pár měsíců později.")
                talk("Přejete si ještě něco?")
                self.AUText.append("Přejete si ještě něco?")
              elif "ano" in command:
                self.AUText.append("Co si přejete?")
                talk("Co si přejete?")
              else:
                self.AUText.append(Y + command)
                talk("Nerozuměl jsem, omlouvám se.")
                self.AUText.append("Nerozuměl jsem, omlouvám se.")  
                talk("Přejete si ještě něco?")
                self.AUText.append("Přejete si ještě něco?")
          except:
            pass
    def talkAndStart(self):
        self.AUText.append("Co si přejete pane?")
        talk("Co si přejete pane")
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