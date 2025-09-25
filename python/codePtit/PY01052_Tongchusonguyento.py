import math
for _ in range(int(input())):
    def check_prime(n):
        if (n < 2): return False
        for i in range(2, int(math.sqrt(n)) + 1):
            if (n % i == 0): return False
        return True
    def solve(n):
        sum_digit = sum((int(x) for x in n))
        return "YES" if check_prime(sum_digit) else "NO"
    print(solve(input()))

