# coding: utf-8

def test(f):
    print()
    print(f(1, 2))


test(lambda x, y: x + y)

s = set()
s.add(1)
s.add(2)
s.add(1)

print(s)
