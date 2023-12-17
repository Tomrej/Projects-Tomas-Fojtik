import cv2
import cvzone
from cvzone.SelfiSegmentationModule import SelfiSegmentation
import os


cap = cv2.VideoCapture(0)
cap.set(3, 648)
cap.set(4, 488)
cap.set(cv2.CAP_PROP_FPS, 30)
segmentor = SelfiSegmentation()
fps = cvzone.FPS()


while True:
    success, img = cap.read()
    imgOut = segmentor.removeBG(img, (0, 255, 0),threshold=0.2)
    imgStacked = cvzone.stackImages([img, imgOut],2,1)
    _, imgStacked = fps.update(imgStacked)
    cv2.imshow("Image", imgOut)
    cv2.waitKey(1)
