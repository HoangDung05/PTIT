for _ in range(int(input())):
    n = int(input())
    check = False
    for i in range(1000):
        if n % 7 == 0:
            print(n)
            check = True
            break
        n += int("".join(reversed(str(n))))
    if check == False:
        print(-1)

