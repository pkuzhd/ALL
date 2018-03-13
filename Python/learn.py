s1 = input()
s2 = input()

def f(s1, s2):
    union = set()
    u1 = set(s1)
    u2 = set(s2)
    union = u1 | u2
    return sorted(union)

print(f(s1, s2))