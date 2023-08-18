def canUnlockAll(boxes):
    newlist = []
    k = len(boxes)
    for i in boxes:
        if len(i) == 0 and i is not boxes[k-1]:
            return False
    for index, keys in enumerate(boxes):
        if index in newlist or index < k-1:
            return True
        else:
            return False
