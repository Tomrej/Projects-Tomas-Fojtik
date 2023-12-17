import cv2
import numpy as np

cap = cv2.VideoCapture(0)
cap.set(3, 1280)    #resolution 1 (HD)
cap.set(4, 720)     #resolution 2 (HD)
cap.set(10, 100)    # Brightness
kernel = np.ones((5, 5), np.uint8)

while True: 
    success, img = cap.read()

    imgGray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY) # Gray filter
    imgCanny = cv2.Canny(img, 110, 110)             # Canny filter
    imgDialation = cv2.dilate(imgCanny, kernel, iterations = 1)
    imgEroded = cv2.erode(imgDialation, kernel, iterations = 1 )

    imgResize = cv2.resize(img, (1920, 500))
    imgCroped = img[0:200,200:500]

    imgZero = np.zeros((512,512,3), np.uint8)
    imgZero[:] = 255, 0 , 0
    imgLine = cv2.line(img, (0, 0), (300 ,300), (0, 255, 0), 3)
    imgRectangle = cv2.rectangle(img, (0, 0), (250,350), (0, 255, 255), 3)
    imgCircle = cv2.circle(img, (400, 50), 30, (0, 255, 255), 5)
    imgText = cv2.putText(img," OPENCV ", (300,200), cv2.FONT_HERSHEY_COMPLEX,4,(50,250,0),1)

    cv2.imshow("Video", imgLine )    # Display video

    if cv2.waitKey(1) & 0xFF == ord("q"):
        break