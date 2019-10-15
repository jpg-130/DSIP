import numpy as np
import cv2

# Original Image
orig = cv2.imread("gray_test.jpg", 0)
cv2.imshow("Original Image", orig)
cv2.waitKey(0)

# # Contrast stretching
# a, v = [int(x) for x in input("Enter the pair a, v: ").split()]
# b, w = [int(x) for x in input("Enter the pair b, w: ").split()]
# rows, cols = orig.shape
# cs_image = np.zeros((rows, cols), dtype='uint8')
# for i in range(rows):
# 	for j in range(cols):
# 		if orig[i, j] <= a:
# 			cs_image[i, j] = int((v / a) * orig[i, j])
# 		elif orig[i, j] <= b:
# 			cs_image[i, j] = int(v + (orig[i, j] - a)*(w - v)/(b - a))
# 		else:
# 			cs_image[i, j] = int(w + (orig[i, j] - b)*(255 - w)/(255 - b))
# cv2.imshow("Contrast stretching with a = {}, v = {}, b = {}, w = {}".format(a, v, b, w), cs_image)
# cv2.waitKey(0)

# Dynamic Range Compression / Log Transformation
(_, maxVal, _, _) = cv2.minMaxLoc(orig)
c = 255 / np.log(1 + maxVal)
drc_image = c*np.log(orig + 1)
cv2.imshow("Log Transformation", drc_image.astype(np.uint8))
cv2.waitKey(0)

# Bit Plane Slicing

cv2.destroyAllWindows()
