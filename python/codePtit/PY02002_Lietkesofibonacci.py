fib = [1] * 93
for i in range(3, 93):
    fib[i] = fib[i - 1] + fib[i - 2]
for _ in range(int(input())):
    a, b = [int(i) for i in input().split()]
    for i in range(a, b + 1):
        print(fib[i], end=" ")
    print()
