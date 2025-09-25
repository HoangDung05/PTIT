import math

arr = [0] * 10000001 # arr[k] luu so uoc tinh tu 1 -> k
def isPrime(x):
    if x < 2: return False
    for i in range(2, int(math.sqrt(x)) + 1):
        if x % i == 0: return False
    return True

def cntDivisor(x):
    if x == 1:
        return 1
    if isPrime(x):
        return 2
    cnt = 1
    for i in range(2, int(math.sqrt(x)) + 1):
        power = 0
        while x % i == 0:
            power += 1
            x //= i
        cnt *= (power + 1)
    if x > 1:
        cnt *= 2
    return cnt
def init():
    arr[1] = 1
    for i in range(2, 10000001):
        if cntDivisor(i) > arr[i - 1]:
            arr[i] = cntDivisor(i)
        else:
            arr[i] = arr[i - 1]
init()
for _ in range(int(input())):
    n = int(input())
    temp = arr[n - 1]
    while 1:
        if arr[n] > temp:
            print(n)
            break
        n += 1
    print(n)