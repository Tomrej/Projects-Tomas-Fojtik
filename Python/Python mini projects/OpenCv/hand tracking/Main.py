import cv2
from cvzone.HandTrackingModule import HandDetector

cap = cv2.VideoCapture(0)
cap.set(3, 1280)
cap.set(4, 720)
detector = HandDetector(detectionCon=0.8)

colorR = 225, 200, 100
cx, cy, w, h = 100, 100, 200, 200

while True:
    success, img = cap.read()
    img = cv2.flip(img, 1)
    img = detector.findHands(img)
    lmList, _ = detector.findPosition(img)

    if lmList:

        l, _, _ = detector.findDistance(8, 12, img)
        print(l)
        if l<35:
            cursor = lmList[8]
            if cx-w//2<cursor[0]<cx+w//2 and cy-h//2<cursor[1]<cy+h//2:
                colorR = 255, 10, 100
                cx, cy = cursor
            else:
                colorR = 225, 200, 100
    cv2.rectangle(img, (cx-w//2, cy-h//2), (cx+w//2, cy+h//2), (colorR), cv2.FILLED)

    cv2.imshow("image", img)
    cv2.waitKey(1)
