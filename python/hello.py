s = "hello my name is Dung how are you"
my_list = s.split()
for x in range(ord("A"), ord("z")):
    if my_list.count(chr(x)) > 0:
        print(f"{chr(x)} {my_list.count(chr(x))}")
