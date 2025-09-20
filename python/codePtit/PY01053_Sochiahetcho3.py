

for _ in range(int(input())):
    n = input()
    sum_digit = 0
    for i in n:
        sum_digit += int(i)
    if sum_digit % 3 == 0:
        print("YES")
    else:
        print("NO")
