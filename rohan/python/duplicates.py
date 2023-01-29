def duplicates(list):
    count = {}
    for i in list:
        if i not in count:
            count[i] = 1
        else:
            count[i] += 1
    print(count)
    dupe = []
    for i in count:
        if count[i] > 1:
            dupe.append(i)
    return dupe
    # return [i for i in count if count[i] > 1]


list = [1, 2, 3, 2, 4, 1, 5, 6, 7, 8, 5]

dup = duplicates(list)
print(dup)
