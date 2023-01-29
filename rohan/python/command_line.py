import sys

sum = 0

n = len(sys.argv)

print("Number of command line arguments: ", n)


for i in range(1, n):
    print("Argument", i, " : ", sys.argv[i])
    sum = sum + int(sys.argv[i])
print("Sum: ", sum)
