import math
def isPrime(n):
    if n < 2:
        return False
    for i in range (2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

def sumDigits(c):
    sum = 0
    while c > 0:
        sum += c % 10
        c //= 10
    return sum

for _ in range(int(input())):
    a, b = map(int, input().split())
    c = math.gcd(a, b)
    if isPrime(sumDigits(c)):
        print("YES")
    else:
        print("NO")

