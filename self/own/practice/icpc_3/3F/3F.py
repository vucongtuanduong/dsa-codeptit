import math
import numpy as np
a = np.array([[1,1], [1, 0]])
# print(len(a))
# print(a.shape)

print(a * a)

# def mul_matrix(a, b) :
#     c = [[0, 0], [0, 0]]
#     for i in range(len(a[0])):
#         for j in range(len(a[1])):
#             for k in range(len(a[1])):
#                 c[i][j] += a[i][k] * b[k][j]
#                 # print(c[i][j])
#     return c
# def powll(a, n):
#     if n == 1:
#         return a
#     res = powll(a, n // 2)
#     res = mul_matrix(res, res)
#     if (n % 2 == 1):
#         res = mul_matrix(res, a)
#     return res
# t = int(input())
# for i in range(t):
#     string = input()
#     l = string.split(" ")
#     # print(l)
#     s = int(l[0])
#     w = int(l[1])
#     m = int(l[2])
#     x = powll(a, s - 1)[0][0]
#     # print(x)
#     a = [[1,1], [1, 0]]
#     y = powll(a, w - 1)[0][0]
#     print(math.gcd(x, y) % m)