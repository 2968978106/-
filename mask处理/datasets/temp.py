import cv2
import matplotlib.pyplot as plt

mask = cv2.imread('shapan_460_coco/Masks/train_25.png', cv2.COLOR_BGR2GRAY)
plt.imshow(mask, 'gray')
plt.show()

mask = cv2.imread('0719_labeled/SegmentationClass/photo_19700101_000028.png')
plt.imshow(mask[:, :, [2,1,0]])
plt.show()