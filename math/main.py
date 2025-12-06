import numpy as np

if __name__ == "__main__":
    # 向量加法
    vector1 = np.array([1, 2, 3])
    vector2 = np.array([4, 5, 6])
    vector_sum = vector1 + vector2
    print("向量加法结果:", vector_sum)
    # 矩阵乘法
    matrix1 = np.array([[1, 2], [3, 4]])
    matrix2 = np.array([[5, 6], [7, 8]])
    matrix_product = np.dot(matrix1, matrix2)
    print("矩阵乘法结果:")
    print(matrix_product)
    # 求解线性方程组
    a = np.array([[3, 1], [1, 2]])
    b = np.array([9, 8])
    x = np.linalg.solve(a, b)
    print("线性方程组的解:", x)
    # 计算特征值和特征向量
    matrix = np.array([[1, 2], [2, 1]])
    eigenvalues, eigenvectors = np.linalg.eig(matrix)
    print("特征值:", eigenvalues)
    print("特征向量:")
    print(eigenvectors)
    # 计算矩阵的逆
    matrix = np.array([[1, 2], [3, 4]])
    inverse_matrix = np.linalg.inv(matrix)
    print("矩阵的逆:")
    print(inverse_matrix)
    # 计算矩阵的行列式
    determinant = np.linalg.det(matrix)
    print("矩阵的行列式:", determinant)
