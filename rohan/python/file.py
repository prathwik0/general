filename = input("Enter the filename: ")

with open(filename, 'r') as f:
    lines = f.readlines()

i = 1
for line in lines:
    marks = line.split(' ')

    marks = [int(i) for i in marks]

    # marks2 = []

    # for i in marks:
    #     marks2.append(int(i))

    total = sum(marks)

    avg = total/len(marks)

    print("Student", i, " Total: ", total, "Average: ", avg)
    i += 1
