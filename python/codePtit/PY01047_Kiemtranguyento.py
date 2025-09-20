import math


def prime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

for _ in range(int(input())):
    s = input()
    len_s = len(s)
    n = 1000 * int(s[len_s-4]) + 100 * int(s[len_s-3]) + 10 * int(s[len_s-2]) + int(s[len_s-1])
    if prime(n):
        print("YES")
    else:
        print("NO")
