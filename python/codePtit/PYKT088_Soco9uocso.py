import math
def is_prime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    limit = int(math.sqrt(n)) + 1
    for i in range(3, limit, 2):
        if n % i == 0:
            return False
    return True

def count_numbers_with_9_divisors(n):
    cnt = 0
    # form 1: p^8 with p is prime number
    p = 2
    while True:
        num = p ** 8
        if num > n:
            break
        if is_prime(p):
            cnt += 1
        p += 1

    #form 2: p^2 * q^2 with p, q is prime number
    primes = []
    max_p = int(math.sqrt(n)) + 1
    for i in range(2, max_p):
        if is_prime(i):
            primes.append(i)
    len_primes = len(primes)
    for i in range(len_primes):
        p = primes[i]
        p_pow = p * p
        if p_pow > n:
            break
        for j in range(i + 1, len_primes):
            q = primes[j]
            num = p_pow * q * q
            if num > n:
                break
            cnt += 1
    return cnt
n = int(input())
print(count_numbers_with_9_divisors(n))
