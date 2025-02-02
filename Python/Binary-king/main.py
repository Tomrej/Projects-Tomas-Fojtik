import cv2
import numpy as np
from mss import mss
from PIL import Image
import pytesseract
import time
import pyautogui
import re

def read_number_from_image(image):
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

    cv2.imshow('roi', roi)

    number_text = pytesseract.image_to_string(gray, config='--psm 7')
    print(number_text)
    number_text = re.sub(r'\D', '', number_text)

    try:
        number = int(number_text.strip()) # Converts text to an int
    except ValueError:
        print("Failed to recognize number:", number_text)
        return None
    return number


def binaryToDecimal(binary):
    decimal = 0
    j = 0
    binary = int(binary)

    while(binary != 0):
        dec = binary % 10
        decimal = decimal + dec * pow(2, j)
        binary = binary//10
        j += 1
    return decimal

def clickNumber(number):
    pyautogui.click(x=1200, y=970, duration=duration)
    time.sleep(1)
    for k in str(number):
        if k == "0":
            print(0)
            pyautogui.click(x=1210, y=870, duration=duration)
        if k == "1":
            print(1)
            pyautogui.click(x=1140, y=810, duration=duration)
        if k == "2":
            print(2)
            pyautogui.click(x=1215, y=810, duration=duration)
        if k == "3":
            print(3)
            pyautogui.click(x=1300, y=810, duration=duration)
        if k == "4":
            print(4)
            pyautogui.click(x=1140, y=750, duration=duration)
        if k == "5":
            print(5)
            pyautogui.click(x=1215, y=750, duration=duration)
        if k == "6":
            print(6)
            pyautogui.click(x=1300, y=750, duration=duration)
        if k == "7":
            print(7)
            pyautogui.click(x=1140, y=680, duration=duration)
        if k == "8":
            print(8)
            pyautogui.click(x=1215, y=680, duration=0.5)
        if k == "9":
            print(9)
            pyautogui.click(x=1300, y=680, duration=0.5)
    
    pyautogui.click(x=1300, y=880, duration=0.3)

def clickBinary(number):

    time.sleep(1)

    block = [START_BLOCK[0], START_BLOCK[1]]
    binary = "{0:b}".format(int(number))
    
    for j in range(8-len(binary)):
        print("Zero")
        pixelColor = image[block[0], block[1]][:3]
        print(pixelColor)
        print(i)
        print(block[0], block[1])
        if not np.array_equal(pixelColor, YELLOW_DARK):
            print("change state of pixel")
            pyautogui.click(x=block[1]+350, y=block[0]+280, duration=duration)
        block[1] += 100

    for k in binary:
        print(k)
        pixelColor = image[block[0], block[1]][:3]
        print(pixelColor)
        print(i)
        print(block[0], block[1])
        if not np.array_equal(pixelColor, YELLOW_DARK):
            pyautogui.click(x=block[1]+350, y=block[0]+280, duration=duration)
            print("change state of pixel")
        if k == "1":
            pyautogui.click(x=block[1]+350, y=block[0]+280, duration=duration)
        block[1] += 100
    print(binary)

bounding_box = {'top': 280, 'left': 350, 'width': 1000, 'height': 800}

START_BLOCK = [670, 50] # binary clicking
first_block = [670, 50]
number_block = [670, 50] # location of number for scan

YELLOW = [234, 187, 0]
YELLOW_DARK = [115, 80, 0]

# region of interest
roi_top = 650
roi_left = 840
roi_width = 153
roi_height = 79

duration = 0.1

sct = mss()

print("5 seconds till start")
time.sleep(5)

while True:
    bit = ""
    current_block = [first_block[0], first_block[1]]
    sct_img = sct.grab(bounding_box)

    image = np.array(sct_img)

    roi = image[roi_top:roi_top+roi_height, roi_left:roi_left+roi_width]

    print(image[first_block[0], first_block[1]][:3])

    for i in range(8):
        print(i)
        print(current_block[0], current_block[1])
        pixelColor = image[current_block[0], current_block[1]][:3]
        print(pixelColor)
        if np.array_equal(pixelColor, YELLOW_DARK):
            bit += "0"
        elif np.array_equal(pixelColor, [213, 203, 179]) and not current_block[1] > 650: # new level
            pyautogui.click(x=900, y=650, duration=duration)
            time.sleep(1)
        else:
            bit += "1"
        current_block[1] += 100

    print("!COLOR")
    print([current_block[0], current_block[1]])
    inputMode = image[current_block[0], current_block[1]][:3]
    print(inputMode)
    if np.array_equal(inputMode, [255, 255, 255]):
        # READ NUMBER
        time.sleep(2.2)
        number_from_image = read_number_from_image(roi)
        
        count = 0
        while number_from_image is None or not count < 5:
            time.sleep(2.2)
            number_from_image = read_number_from_image(roi)
            count += 1
            if count <= 5:
                number_from_image = 1

        print("NUMBER FROM IMAGE:")
        print(number_from_image)
        
        clickBinary(number_from_image)
        time.sleep(0.5)
    else:
        clickNumber(binaryToDecimal(bit))
        time.sleep(0.5)

    
    if (cv2.waitKey(1) & 0xFF) == ord('q'):
        cv2.destroyAllWindows()
        break