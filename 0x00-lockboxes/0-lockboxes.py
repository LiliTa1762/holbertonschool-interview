def join(item_boxes, reminder_list):
    reminder = []
    for i in reminder_list:
        reminder += item_boxes[i]
    return reminder


def canUnlockAll(boxes):
    index = 0
    total = list(set(boxes[0]) | {0})
    item_added = True
    while item_added:
        item_added = False
        for j in join(boxes, total[index:]):
            if j not in total:
                total.append(j)
                index += 1
                item_added = True

    return len(total) == len(boxes)
