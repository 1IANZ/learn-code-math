import numpy as np


def day1():
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


def day2():
    # 两行/列线性无关 (Rank = 2)
    A = np.array([[1, 2], [3, 4]])
    rank_A = np.linalg.matrix_rank(A)
    print(f"矩阵 A 的秩: {rank_A}")
    # 第二行是第一行的 2 倍，线性相关 (Rank = 1)
    B = np.array([[1, 2], [2, 4]])
    rank_B = np.linalg.matrix_rank(B)
    print(f"矩阵 B 的秩: {rank_B}")
    C = np.array([[1, 0], [0, 1], [2, 3]])
    rank_C = np.linalg.matrix_rank(C)
    print(f"矩阵 C 的秩: {rank_C}")

    print("-" * 30)

    # 线性相关 (Redundant)
    v1 = np.array([1, 0, 0])
    v2 = np.array([0, 1, 0])
    v3 = np.array([1, 1, 0])
    matrix_dependent = np.column_stack((v1, v2, v3))
    rank = np.linalg.matrix_rank(matrix_dependent)
    num_vectors = 3
    print(f"矩阵秩: {rank}, 向量个数: {num_vectors}")
    if rank < num_vectors:
        print("-> 判定结果：线性相关 (Linearly Dependent)")
    else:
        print("-> 判定结果：线性无关 (Linearly Independent)")
    # 线性无关 (Independent)
    u1 = np.array([1, 0, 0])
    u2 = np.array([0, 1, 0])
    u3 = np.array([0, 0, 1])
    matrix_independent = np.column_stack((u1, u2, u3))
    rank = np.linalg.matrix_rank(matrix_independent)
    print(f"矩阵秩: {rank}, 向量个数: 3")
    if rank < 3:
        print("-> 判定结果：线性相关 (Linearly Dependent)")
    else:
        print("-> 判定结果：线性无关 (Linearly Independent)")


if __name__ == "__main__":
    day2()
