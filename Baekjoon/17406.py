import itertools
import copy
def init():
    r, c, s = map(int, input().split())
    return (r-1, c-1, s)
N, M, K = map(int, input().split())
Temp = [list(map(int, input().split())) for _ in range(N)]
P = list(itertools.permutations([init() for _ in range(K)], K))
def rotate(r, c, s):
    while s:
        tr, tc = A[r-s][c-s], A[r-s][c+s]
        for i in range(-s+1, s+1):
            tr, A[r-s][c+i] = A[r-s][c+i], tr
            tc, A[r+i][c+s] = A[r+i][c+s], tc
        tr = tc
        tc = A[r+s][c-s]
        for i in range(s-1, -s-1,  -1):
            tr, A[r+s][c+i] = A[r+s][c+i], tr
            tc, A[r+i][c-s] = A[r+i][c-s], tc
        s -= 1
ans = 100*50
while P:
    R = P.pop()
    A = copy.deepcopy(Temp)
    for rot in R:
        r, c, s = rot
        rotate(r, c, s)
    for a in A:
        ans = min(sum(a), ans)
print(ans)