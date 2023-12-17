import time
import pyautogui

time.sleep(1)

text = open("beemovie", 'r')

for word in text:
    pyautogui.typewrite(word)
    pyautogui.press("enter")