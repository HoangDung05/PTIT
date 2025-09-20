

for _ in range(int(input())):
    n = input()
    multiple = 1
    for i in n:
        if i == '0':
            continue
        multiple *= int(i)
    print(multiple)
