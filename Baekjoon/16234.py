N, L, R = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]
B = [[0]*N for _ in range(N)]
dr = (0,0,1,-1)
dc = (1,-1,0,0)
cnt = 0
info = {}
tag = True

def open(s, r, c):
    global N, L, R, A, B, dr, dc, cnt, tag
    Q = [(r, c)]

    while Q:
        r, c = Q.pop()
        for d in range(4):
            nr = r + dr[d]
            nc = c + dc[d]
            if 0<=nr<N and 0<=nc<N and not B[nr][nc] and L<=abs(A[r][c]-A[nr][nc])<=R:
                    if not tag: tag = True
                    Q.append((nr, nc))
                    if s in info:
                        info[s]['p'] += A[nr][nc]
                        info[s]['c'] += 1
                    else:
                        info[s] = {
                            'p': A[r][c] + A[nr][nc],
                            'c': 2
                        }
                        B[r][c] = s
                    B[nr][nc] = s
def move():
    global cnt
    cnt += 1
    for r in range(N):
        for c in range(N):
            if B[r][c]:
                A[r][c] = info[B[r][c]]['p']//info[B[r][c]]['c']
                B[r][c] = 0
    info.clear()
while tag:
    tag = False
    s = 0
    for r in range(N):
        for c in range(N):
            if not B[r][c]:
                s+=1
                open(s, r, c)
    if not tag: break
    move()

print(cnt)

