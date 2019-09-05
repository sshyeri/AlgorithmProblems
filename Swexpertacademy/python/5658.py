for tc in range(1, int(input())+1):
    N, K = map(int, input().split())
    h = input()
    n = []
    p = N//4
    h+=h[:p-1]
    for i in range(N):
        n.append(h[i:i+p])
    n = sorted(list(set(n)))
    print('#{} {}'.format(tc, int(n[-K], base=16)))
    