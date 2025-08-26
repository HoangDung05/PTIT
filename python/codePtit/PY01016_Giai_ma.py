for _ in range(int(input())):
    s = input()
    for i in range(len(s)):
        if i % 2 == 0:
            print(s[i], end="")
        else:
            for x in range(int(s[i]) - 1):
                print(s[i-1], end="")
    print()

