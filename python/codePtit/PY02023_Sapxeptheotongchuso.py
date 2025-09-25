def sum_digit(n):
    s = 0
    for i in n:
        s += int(i)
    return s
for _ in range(int(input())):
    input()
    for i in sorted([(sum_digit(x), int(x)) for x in input().split()]):
        print(i[1], end=" ")
    print()
