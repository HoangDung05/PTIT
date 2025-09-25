for i in range(int(input())):
    s1 = [x for x in input()]
    s2 = [x for x in input()]
    print(f"Test {i+1}: " + ("YES" if sorted(s1) == sorted(s2) else "NO"))