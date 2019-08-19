for tc in range(int(input())):
    N, M = map(int, input().split())
    a = [[] for _ in range(N+1)]
    for _ in range(M):
        x, y = map(int, input().split())
        a[x] += [y]
        a[y] += [x]
    print(a)