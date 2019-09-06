import sys
sys.setrecursionlimit(100000)
N, M = map(int, input().split())
bing = [list(map(int, input().split())) for _ in range(N)]
stage = [[0]*M for _ in range(N)]

dr = (0, 0, -1, 1)
dc = (1, -1, 0, 0)

def dfs(r, c, s):
    for d in range(4):
        nr, nc = r + dr[d], c + dc[d]
        if 0<bing[nr][nc] and stage[nr][nc]<s:
            stage[nr][nc] = s
            dfs(nr, nc, s)
        elif bing[r][c] > 0 and not bing[nr][nc] and stage[nr][nc]<s:
            bing[r][c] -= 1

def solve():
    s = 1
    tag = True
    while tag:
        tag = False
        for r in range(1, N-1):
            for c in range(1, M-1):
                if bing[r][c] and stage[r][c]<s:
                    if not tag:
                        stage[r][c] = s
                        dfs(r, c, s)
                        tag = True
                    else: return s-1
        s += 1
    return 0

print(solve())