# imports libraries
import speech_recognition as sr
import subprocess
import webbrowser
import requests
from bs4 import BeautifulSoup
import pyttsx3
import datetime
import random
from PyQt5 import QtCore, QtGui, QtWidgets


engine = pyttsx3.init()
listener = sr.Recognizer()

Y = ""
hello = ["Dobrý den", "Ahoj", "Rád vás vidím", "Nazdar"]
functionsList = ["Ahoj!", "Čau!", "Co umíš?", "Jak se máš?", "Přehraj Jaromír Nohavica na Youtube.", "nic nechci", "stop", "vypni se", "čas", "Kolik je hodin?",
                 "Jaký je čas", "Jaké je datum?", "Kolikátého je dnes?", "datum", "co je to python?", "Kdo je Jaromír nohavica?", "vtip", "Řekni mi vtip", "Kolik ti je?"]
mood = ["Mám se dobře", "Jsem v pohodě", "Jsem šťastný", "Jde to"]
language = "CZ"
whatDoYouWant = ["Co si přejete?", "Jaké máte přání?",
                 "Co potřebujete", "Potřebujete něco?", "Přejete si něco"]


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
        self.scrollArea.setStyleSheet(
            "setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );")
        self.scrollArea.setWidgetResizable(True)
        self.scrollArea.setObjectName("scrollArea")
        self.scrollAreaWidgetContents = QtWidgets.QWidget()
        self.scrollAreaWidgetContents.setGeometry(QtCore.QRect(0, 0, 963, 604))
        self.scrollAreaWidgetContents.setStyleSheet(
            "setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );")
        self.scrollAreaWidgetContents.setObjectName("scrollAreaWidgetContents")
        self.verticalLayout_2 = QtWidgets.QVBoxLayout(
            self.scrollAreaWidgetContents)
        self.verticalLayout_2.setObjectName("verticalLayout_2")

        def addTextY(text):
            self.you = QtWidgets.QHBoxLayout()
            self.you.setContentsMargins(9, 9, 9, 9)
            self.you.setSpacing(9)
            self.you.setObjectName("you")
            spacerItem = QtWidgets.QSpacerItem(
                40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
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
            self.label.setAlignment(
                QtCore.Qt.AlignLeading | QtCore.Qt.AlignLeft | QtCore.Qt.AlignVCenter)
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
            spacerItem1 = QtWidgets.QSpacerItem(
                40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
            self.assistent.addItem(spacerItem1)
            self.verticalLayout_2.addLayout(self.assistent)
            self.label_2.setText(text)

        def TalkAndTextA(text):
            talk(text)
            addTextA(text)

        def runCZ(self):
            stop = False
            while stop == False:
                try:
                    # Microphone
                    with sr.Microphone() as source:
                        voice = listener.listen(source)
                        command = listener.recognize_google(
                            voice, language="CS")  # google speech recognizer
                        command = command.lower()
                        if "na youtube" in command:  # open on youtube
                            addTextY(command)
                            command.replace("na youtube", "")
                            command.replace("vyhledej", "")
                            command.replace(" ", "+")
                            command.replace("vyhledej", "")
                            command.replace("spusť", "")
                            url = "https://www.youtube.com/results?search_query={}".format(
                                command)
                            TalkAndTextA("Otevírám " + command + " na youtube")
                            webbrowser.open_new_tab(url)
                            TalkAndTextA("Chcete ještě něco pane??")
                        # if "something" in command then...
                        elif "čau" in command or "ahoj" in command or "nazdar" in command:
                            hi = random.choice(hello)
                            addTextY(command)
                            TalkAndTextA(hi)
                            TalkAndTextA("Chcete ještě něco pane?")
                        elif "co umíš" in command:
                            functions = random.choice(functionsList)
                            functionTalk = functions.replace("!", "")
                            addTextY(command)
                            TalkAndTextA(
                                "Můžete říct například: " + functionTalk)
                            TalkAndTextA("Chcete ještě něco pane?")
                        elif "jak se máš" in command or "jak se cítíš" in command:
                            addTextY(command)
                            moods = random.choice(mood)
                            TalkAndTextA(moods + ". Díky za optání pane.")
                            TalkAndTextA("Přejete si něco dalšího, pane?")
                        elif "ne" in command and command != "jaké je dnes počasí" or "stop" in command or "konec" in command or "nic" in command:
                            addTextY(command)
                            TalkAndTextA("Ano pane")
                            stop = True
                        elif "vypni se" in command:
                            addTextY(command)
                            TalkAndTextA("Nashle")
                            quit()
                        elif "počasí zítra" in command:
                            addTextY(command)
                            urlW = "https://www.google.com/search?q=po%C4%8Das%C3%AD+z%C3%ADtra&oq=po%C4%8Das%C3%AD+z%C3%ADtra&aqs=chrome..69i57.5354j0j1&sourceid=chrome&ie=UTF-8"
                            page = requests.get(urlW)
                            soup = BeautifulSoup(page.content, "html.parser")
                            location = soup.find(
                                "div", class_="wob_loc mfMhoc").text
                            nextDay = soup.find(
                                "span", class_="wob_t TVtOme").text
                            rainNextDay = soup.find(
                                "div", class_="wtsRwe").text
                            TalkAndTextA("zítra bude v" + " " + location + " " + nextDay +
                                         " °C " + ". Šance, že bude pršet je:" + " " + rainNextDay)
                        elif "počasí" in command:
                            addTextY(command)
                            urlW = "https://weather.com/cs-CZ/weather/today/l/0db6a61d2e5135219cc8aad728f227b3ba9331c0b00530ad33f4974c8bad66d2"
                            page = requests.get(urlW)
                            soup = BeautifulSoup(page.content, "html.parser")
                            location = soup.find(
                                "h1", class_="CurrentConditions--location--1Ayv3").text
                            temperature = soup.find(
                                "span", class_="wob_t TVtOme").text
                            weatherPrediction = soup.find(
                                "div", class_="CurrentConditions--phraseValue--2xXSr").text
                            rain = soup.find(
                                "div", class_="CurrentConditions--precipValue--RBVJT").text
                            TalkAndTextA(
                                "Dnes je v " + location + " " + temperature + " " + weatherPrediction + " " + rain)
                            TalkAndTextA("Přejete si ještě něco, pane?")
                        elif "čas" in command or "hodin" in command:
                            addTextY(command)
                            time = datetime.datetime.now().strftime('%H:%M')
                            TalkAndTextA("Aktuální čas je" + time)
                            TalkAndTextA("Potřebujete ještě něco?")
                        elif "datum" in command or "den" in command:
                            addTextY(command)
                            date = datetime.datetime.now().strftime("%D")
                            TalkAndTextA("Dnes je: " + date + ", pane")
                            TalkAndTextA("Do you wan't anything else?")
                        elif "kdo je" in command or "co je" in command:  # what is, or who is ...
                            addTextY(command)
                            person = command.replace("kdo je", "")
                            person = command.replace("co je", "")
                            person = command.replace(" ", "+")
                            url = "https://cs.wikipedia.org/w/index.php?title=Speci%C3%A1ln%C3%AD:Hled%C3%A1n%C3%AD&search={}&go=Go&ns0=1&ns100=1&ns102=1".format(
                                person)
                            page = requests.get(url)
                            soup = BeautifulSoup(page.content, "html.parser")
                            search_terms = soup.find(
                                "div", class_="searchresult").text
                            TalkAndTextA("Hledám")
                            TalkAndTextA(search_terms)
                            TalkAndTextA("Přejete si něco dalšího?")
                        elif "otevři" in command:
                            addTextY(command)
                            if "google" in command or "chrome" in command:
                                TalkAndTextA("Otevírám google chrome.")
                                subprocess.call(
                                    ['C:\Program Files\Google\Chrome\Application\\chrome.exe'])
                            elif "notepad" in command or "poznámkový blok" in command:
                                TalkAndTextA("Otevírám notepad")
                                subprocess.call(
                                    ["C:\WINDOWS\system32\\notepad.exe"])
                            elif "spotify" in command:
                                TalkAndTextA("Otevírám spotify.")
                                subprocess.call(
                                    ["C:/Users/42073/AppData/Local/Microsoft/WindowsApps/SpotifyAB.SpotifyMusic_zpdnekdrzrea0//spotify.exe"])
                            elif "teams online" in command:
                                TalkAndTextA("Otevírám teams online")
                                mr = "https://teams.microsoft.com/"
                                webbrowser.open_new_tab(mr)
                            else:
                                TalkAndTextA(
                                    "Omlovám se ale tohle otevřít neumím!")
                            TalkAndTextA("Máte ještě nějaký požadavek?")
                        elif "na google" in command:
                            addTextY(command)
                            terms = command.replace("vyhledej na google", "")
                            search_terms = [terms]
                            for term in search_terms:
                                url = "https://www.google.com.tr/search?q={}".format(
                                    term)
                                webbrowser.open_new_tab(url)
                            TalkAndTextA("Přejete si ještě nečo?")
                        elif "dobré ráno" in command or "dobrý večer" in command:
                            addTextY(command)
                            time = datetime.datetime.now().strftime('%H:%M')
                            date = datetime.datetime.now().strftime("%D")
                            TalkAndTextA("Dobré ráno pane, dnes je: " +
                                         date + " . Aktuálně je: " + time)
                            urlW = "https://weather.com/cs-CZ/weather/today/l/0db6a61d2e5135219cc8aad728f227b3ba9331c0b00530ad33f4974c8bad66d2"
                            page = requests.get(urlW)
                            soup = BeautifulSoup(page.content, "html.parser")
                            location = soup.find(
                                "h1", class_="CurrentConditions--location--1Ayv3").text
                            temperature = soup.find(
                                "span", class_="CurrentConditions--tempValue--3KcTQ").text
                            weatherPrediction = soup.find(
                                "div", class_="CurrentConditions--phraseValue--2xXSr").text
                            TalkAndTextA("Dnes je v " + location + " " +
                                         temperature + " " + weatherPrediction)
                            urlC = "https://www.tiscali.cz/"
                            page = requests.get(urlC)
                            soup = BeautifulSoup(page.content, "html.parser")
                            information = soup.find("p", class_="large").text
                            TalkAndTextA(
                                "nových nakažených je: " + information)
                            mr = "https://teams.microsoft.com/_#/calendarv2"
                            TalkAndTextA(
                                "Otevírám vám váš kalendář online hodin")
                            webbrowser.open_new_tab(mr)
                            TalkAndTextA("Tady máte novinky.")
                            seznam = "https://www.seznam.cz/"
                            webbrowser.open_new_tab(seznam)
                            TalkAndTextA("Přejete si ode mne ještě něco?")
                        elif "korona" in command or "kovid" in command:
                            addTextY(command)
                            url = "https://www.tiscali.cz/"
                            page = requests.get(url)
                            soup = BeautifulSoup(page.content, "html.parser")
                            information = soup.find("p", class_="large").text
                            TalkAndTextA("Nový nakažení: " + information)
                            TalkAndTextA("Přejete si ještě něco?")
                        elif "vtip" in command:
                            addTextY(command)
                            TalkAndTextA('Vtipy nejsou aktuálně funkční')
                            TalkAndTextA("Přejete si ještě něco?")
                        elif "jak jsi starý" in command or "kolik ti je" in command:
                            addTextY(command)
                            TalkAndTextA(
                                "Moje anglická verze byla vytvořena roku 2021. Já byl vytvořen o pár měsíců později.")
                            TalkAndTextA("Přejete si ještě něco?")
                        elif "ano" in command:
                            TalkAndTextA("Co si přejete?")
                        else:
                            addTextY(command)
                            TalkAndTextA("Nerozuměl jsem, omlouvám se.")
                            TalkAndTextA("Přejete si ještě něco?")
                except:
                    pass

        def TalkAndStart(self):
            time = int(datetime.datetime.now().strftime('%H'))
            salutation = random.choice(whatDoYouWant)
            if time == 12:
                TalkAndTextA("Dobré poledne, pane. " + salutation)
            elif time == 24:
                TalkAndTextA("Neobvyklý čas, pane. " + salutation)
            elif time > 0 and time < 12:
                TalkAndTextA("Dobré ráno, pane. " + salutation)
            elif time > 12 and time < 19:
                TalkAndTextA("Dobré odpoledne, pane. " + salutation)
            elif time > 19 and time < 24 or time == 19:
                TalkAndTextA("Dobrý večer, pane. " + salutation)
            else:
                TalkAndTextA(salutation)
            runCZ(self)

        spacerItem2 = QtWidgets.QSpacerItem(
            20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
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
        spacerItem3 = QtWidgets.QSpacerItem(
            40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout.addItem(spacerItem3, 0, 0, 1, 1)
        spacerItem4 = QtWidgets.QSpacerItem(
            40, 20, QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
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
        self.actionReport_crash.setText(
            _translate("MainWindow", "Report crash"))
        self.actionVisit_Discord.setText(
            _translate("MainWindow", "Visit Discord"))
        self.actionAbout.setText(_translate("MainWindow", "About"))
        self.actionAlways_on_top.setText(
            _translate("MainWindow", "Always on top"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
