import math
for _ in range(int(input())):
    def check_prime(n):
        if (n < 2): return False
        for i in range(2, int(math.sqrt(n)) + 1):
            if (n % i == 0): return False
        return True
    def solve(n):
        if not check_prime(len(n)): return "NO"
        prime = len([x for x in n if check_prime(int(x))])
        return "YES" if prime > (len(n) - prime) else "NO"
    print(solve(input()))

