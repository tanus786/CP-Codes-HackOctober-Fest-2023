def get_matrix_input():
    matrix = []
    print("Enter the elements of the 3x3 matrix:")
    for i in range(3):
        row = []
        for j in range(3):
            element = float(input(f"Enter element at position ({i + 1}, {j + 1}): "))
            row.append(element)
        matrix.append(row)
    return matrix

def calculate_determinant(matrix):
    return (
        matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1])
        - matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0])
        + matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0])
    )

def calculate_adjoint(matrix):
    adjoint = [
        [
            matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1],
            matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2],
            matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1],
        ],
        [
            matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2],
            matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0],
            matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2],
        ],
        [
            matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0],
            matrix[0][1] * matrix[2][0] - matrix[0][0] * matrix[2][1],
            matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0],
        ],
    ]
    return adjoint

def multiply_matrix_by_scalar(matrix, scalar):
    result = []
    for i in range(len(matrix)):
        row = []
        for j in range(len(matrix[i])):
            row.append(matrix[i][j] * scalar)
        result.append(row)
    return result


def inverse_matrix(matrix):
    determinant = calculate_determinant(matrix)
    if determinant == 0:
        return None  # inverse is not possible

    adjoint = calculate_adjoint(matrix)
    inverse = multiply_matrix_by_scalar(adjoint, 1 / determinant)
    return inverse

def main():
    matrix = get_matrix_input()

    inverse = inverse_matrix(matrix)
    if inverse is not None:
        print("\nThe inverse matrix is:")
        for row in inverse:
            print(row)
    else:
        print("The matrix is not invertible.")

if __name__ == "__main__":
    main()
