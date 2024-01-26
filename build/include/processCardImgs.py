import cv2

def main():
    print("processing images")

    heartPath = "./images/heartSet.jpg"
    heartSet = cv2.imread(heartPath)
    diamondPath = "./images/diamondSet.jpg"
    diamondSet = cv2.imread(diamondPath)
    spadePath = "./images/spadeSet.jpg"
    spadeSet = cv2.imread(spadePath)
    clubPath = "./images/clubSet.jpg"
    clubSet = cv2.imread(clubPath)

    hh, hw = heartSet.shape[:2]
    hCentreX, hCentreY = (hw // 2), (hh // 2)
    heartTop = heartSet[100:hCentreY-45, 105:hw-100]
    heartBottom = heartSet[hCentreY+40:hh-110, 105:hw-100]
    heartTopHeight, heartTopWidth = heartTop.shape[:2]
    heartBottomHeight, heartBottomWidth = heartBottom.shape[:2]

    dh, dw = diamondSet.shape[:2]
    dCentreX, dCentreY = (dw // 2), (dh // 2)
    diamondTop = diamondSet[100:dCentreY-45, 105:dw-100]
    diamondBottom = diamondSet[dCentreY+40:dh-110, 105:dw-100]
    diamondTopHeight, diamondTopWidth = diamondTop.shape[:2]
    diamondBottomHeight, diamondBottomWidth = diamondBottom.shape[:2]

    sh, sw = spadeSet.shape[:2]
    sCentreX, sCentreY = (sw // 2), (sh // 2)
    spadeTop = spadeSet[100:sCentreY-45, 105:sw-100]
    spadeBottom = spadeSet[sCentreY+40:sh-110, 105:sw-100]
    spadeTopHeight, spadeTopWidth = spadeTop.shape[:2]
    spadeBottomHeight, spadeBottomWidth = spadeBottom.shape[:2]

    ch, cw = clubSet.shape[:2]
    cCentreX, cCentreY = (cw // 2), (ch // 2)
    clubTop = clubSet[100:cCentreY-45, 105:cw-100]
    clubBottom = clubSet[cCentreY+40:ch-110, 105:cw-100]
    clubTopHeight, clubTopWidth = clubTop.shape[:2]
    clubBottomHeight, clubBottomWidth = clubBottom.shape[:2]

    start = 0
    stop = 900
    offset = 967
    for i in range(1, 8):

        cv2.imwrite("./images/H"+str(i)+".jpg", heartTop[0:heartTopHeight, start:stop])
        cv2.imwrite("./images/H"+str(i+7)+".jpg", heartBottom[0:heartBottomHeight, start:stop])
        cv2.imwrite("./images/D"+str(i)+".jpg", diamondTop[0:diamondTopHeight, start:stop])
        cv2.imwrite("./images/D"+str(i+7)+".jpg", diamondBottom[0:diamondBottomHeight, start:stop])
        cv2.imwrite("./images/S"+str(i)+".jpg", spadeTop[0:spadeTopHeight, start:stop])
        cv2.imwrite("./images/S"+str(i+7)+".jpg", spadeBottom[0:spadeBottomHeight, start:stop])
        cv2.imwrite("./images/C"+str(i)+".jpg",clubTop[0:clubTopHeight, start:stop])
        cv2.imwrite("./images/C"+str(i+7)+".jpg",clubBottom[0:clubBottomHeight, start:stop])
        start += offset
        stop += offset

if __name__ == "__main__":
    main()
