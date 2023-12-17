from bs4 import BeautifulSoup
import requests

urlW = "https://weather.com/weather/today/l/44cfc278c6342c0cd68382189733f6b7a12ba7f59e47c707403880ae214f5b8e"
page = requests.get(urlW)
soup = BeautifulSoup(page.content, "html.parser")
location = soup.find("span", class_="styles--locationName--GkM1S").text
temperature = soup.find("div", class_="Column--temp--2v_go").text
#weatherPrediction = soup.find("div", class_="CurrentConditions--phraseValue--2xXSr").text
rain = soup.find("span", class_="Column--precip--2H5Iw").text
print(location + " " + temperature + " " + " " + rain)