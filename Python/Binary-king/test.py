import cv2
import pytesseract

# Load the image
image = cv2.imread('your_image.jpg')

# Convert to grayscale
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

# Apply thresholding or other preprocessing techniques

# Use contour detection to find regions of interest (ROIs)
contours, _ = cv2.findContours(thresholded_image, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

# Iterate through each contour
for contour in contours:
    # Get the bounding box of the contour
    x, y, w, h = cv2.boundingRect(contour)
    
    # Extract the digit region of interest (ROI)
    digit_roi = gray[y:y+h, x:x+w]
    
    # Use Tesseract OCR to recognize the digit
    digit_text = pytesseract.image_to_string(digit_roi, config='--psm 10 --oem 3')
    
    # Process the recognized digit text as needed
    print("Detected digit:", digit_text.strip())

# Display the result
cv2.imshow('image', image)
cv2.waitKey(0)
cv2.destroyAllWindows()