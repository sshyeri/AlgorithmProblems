for tc in range(int(input())):
    s1, s2 = input().split()
    C = set(s1) & set(s2)
    print(C)