import math


def prime(n):
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return n > 1

for _ in range(int(input())):
    n = input()
    print("YES" if prime(int(n[-4:])) else "NO")
