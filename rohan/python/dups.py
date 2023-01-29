def dups(list):
    elements = []
    duplicates = []
    for i in list:
        if i not in elements:
            elements.append(i)
        elif i not in duplicates:
            duplicates.append(i)
    return duplicates


a = []
n = int(input("enter number of elements\n"))
print("enter the elements")
for i in range(n):
    a.append(int(input()))
b = dups(a)
print(b)
