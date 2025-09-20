import itertools

s = input()
for p in itertools.permutations(s):
    print("".join(p))


