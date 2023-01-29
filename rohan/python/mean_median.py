def mean(list):
    return sum(list) / len(list)


def median(list):
    list.sort()
    n = len(list)
    if n % 2 == 0:
        return (list[n//2 - 1] + list[n//2])/2
    else:
        return list[n//2]


list = [1, 2, 3, 4, 5, 6, 7]
print(list)
print("Mean: ", mean(list))
print("Median: ", median(list))
