# A binary search function which searches an item
# in a sorted list. The function should return the
# index of element to be searched in the list.


def binarySearch(list, element):
    start = 0
    stop = len(list) - 1
    while (start <= stop):
        mid = (start + stop)//2
        if list[mid] == element:
            return mid
        elif list[mid] < element:
            start = mid + 1
        elif list[mid] > element:
            stop = mid - 1
    return -1


list = [4, 6, 2, 1, 9, 67, 3, 44, 0]
list = sorted(list)
print(list)

element = 99
index = binarySearch(list, element)
print(index)
