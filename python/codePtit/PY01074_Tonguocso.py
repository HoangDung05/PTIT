import math
MAXN = 2000000

arr = [0] * (MAXN + 1)
def sieve():
    for i in range(2, MAXN + 1):
        if arr[i] == 0:
            arr[i] = i
            for j in range(i * i, MAXN + 1, i):
                if arr[j] == 0:
                    arr[j] = i
    arr[1] = 1
def sum_divisor(n):
    sum = 0
    while n > 1:
        p = arr[n]
        while n % p == 0:
            sum += p
            n //= p
    return sum
sieve()
result = 0
for _ in range(int(input())):
    n = int(input())
    result += int(sum_divisor(n))
print(result)

