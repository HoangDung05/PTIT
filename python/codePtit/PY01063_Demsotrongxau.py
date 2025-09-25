for _ in range(int(input())):
    s, n = input(), input()
    cnt = 0
    i = 0
    while i < len(s):
        x = s.find(n, i)
        if x == -1:
            break
        else:
            cnt += 1
            i = x + len(n)
    print(cnt)