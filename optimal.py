# フィードバックゲインと最適コストを求める
import numpy as np

# システムの定義
A = np.array([[0.0, 1.0], [-1.0, 2.0]])
B = np.array([[0.0], [1.0]])
Q = np.array([[2.0, 1.0], [1.0, 3.0]])
R = np.array([[1.0]])

# N = 2, 4, 8, 10,...
N = 2

# 初期化
count = 0
P = Q

# 処理
for count in range(N):
    K = np.linalg.inv(B.T @ (P @ B) + R) @ (B.T @ (P @ A))
    P = A.T @ (P @ (A - B @ K)) + Q
    K_d = -K
    print("K =")
    print(K_d)
    count += 1

# 初期状態(数字を変える)
x_0 = np.array([[1.0],[0.0]])

# 最適コスト
J = np.dot(x_0.T, np.dot(P, x_0))
print("\n J =")
print(J)
