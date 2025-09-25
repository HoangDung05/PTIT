def Try(i, cnt:dict, sum, s:str):
    if i == sum:
        for x in cnt:
            if cnt[x] == 0: return
        if cnt["A"] > cnt["B"] or cnt["B"] > cnt["C"]: return
        print(s)
        return
    else:
        for x in "ABC":
            cnt[x] += 1
            Try(i + 1, cnt, sum, s + x)
            cnt[x] -= 1
n = int(input())
for i in range(3, n + 1):
    cnt = {"A":0, "B":0, "C":0}
    Try(0, cnt, i, "")
