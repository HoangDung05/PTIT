for _ in range(int(input())):
    s = input()
    sum_digit = sum([int(x) for x in s if x.isdigit()])
    list_alpha = [x for x in s if x.isalpha()]
    list_alpha.sort()
    print("".join(list_alpha), end="")
    print(sum_digit)
