class Rectangle:
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def getArea(self):
        self.area = self.width*self.height
        return self.area

    def printFn(self):
        print("Area:", self.area)
        print("Width:", self.width)
        print("Height:", self.height)


def MaxMinArea(rect):
    max = rect[0]
    min = rect[0]

    for i in rect:
        if i.getArea() > max.getArea():
            max = i

        if i.getArea() < min.getArea():
            min = i

    return max, min


n = int(input("Enter the number of Rectangles:"))
rect = []

for i in range(n):
    width = float(input("Width:"))
    height = float(input("Height:"))
    rect.append(Rectangle(width, height))
    print(rect)

maxArea, minArea = MaxMinArea(rect)

maxArea.printFn()
minArea.printFn()
