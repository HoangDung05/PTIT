import math
for _ in range(int(input())):
    n = input()
    def check_prime(n):
        if n < 2: return False
        for i in range(2, int(math.sqrt(n)) + 1):
            if n % i == 0: return False
        return True
    def check(n):
        for i in range(len(n)):
            if check_prime(i):
                if not check_prime(int(n[i])): return "NO"
            else:
                if check_prime(int(n[i])): return "NO"
        return "YES"
    print(check(n))



