def add_matrices():
    rows = int(input("Enter the number of rows in the matrix: "))
    cols = int(input("Enter the number of columns in the matrix: "))

    matrix1 = []
    matrix2 = []

    print("Enter the elements of first matrix: ")
    for i in range(rows):
        row = list(map(int, input().split()))
        matrix1.append(row)

    print("Enter the elements of second matrix: ")
    for i in range(rows):
        row = [int(x) for x in input().split()]
        matrix2.append(row)

    result = []
    for i in range(rows):
        row = []
        for j in range(cols):
            row.append(matrix1[i][j] + matrix2[i][j])
        result.append(row)

    return result


print("Resultant matrix is: ")
result = add_matrices()

for row in result:
    print(row)
