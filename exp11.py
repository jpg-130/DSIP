from PIL import Image
import cv2

img = cv2.imread('im.jpg')
cv2.imshow('color',img)

gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
cv2.imshow('gray',gray)

sobel_horizontal_mask = [[-1, -2, -1],
                         [0, 0, 0],
                         [1, 2, 1]]
sobel_horizontal = cv2.bitwise_and(gray, gray, mask=sobel_horizontal_mask)