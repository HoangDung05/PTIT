a, b = map(int, input().split())
if a == 0 :
    if b != 0:
        print("VN")
    else:
        print("VSN")
else:
    result = b * (-1) / a
    print(f"{result:.2f}")