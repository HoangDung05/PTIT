import math

n, k = map(int, input().split())
cnt_line = 0
for i in range(int(math.pow(10, k - 1)), int(math.pow(10, k))):
    if math.gcd(i, n) == 1:
        print(i, end=" ")
        cnt_line += 1
    if cnt_line == 10:
        print()
        cnt_line = 0