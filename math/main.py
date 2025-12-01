import numpy as np

from linear_algebra import determinant

if __name__ == "__main__":
    A = np.array([[1, 2], [3, 4]])
    print("2x2 行列式:", round(determinant.det(A)))
