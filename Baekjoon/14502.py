import itertools
safe = 0
vir = []
empt = []
dr = (0, 1, -1, 0)
dc = (1, 0, 0, -1)
inf = 64
def init(i):
    global vir, empt, safe
    temp = list(map(int, input().split()))
    for j in range(M):
        if not temp[j]: 
            empt.append((i, j))
            safe += 1
        elif temp[j]==2: vir.append((i, j))
    return temp

N, M = map(int, input().split())
arr = [init(i) for i in range(N)]
walls = list(itertools.combinations(empt, 3))

def spread():
    global inf, Q, cnt
    while Q:
        r, c = Q.pop(0)
        if cnt>= inf : return
        for d in range(4):
            nr = r + dr[d]
            nc = c + dc[d]
            if 0<=nr<N and 0<=nc<M and not arr[nr][nc]:
                arr[nr][nc] = 2
                cnt += 1
                Q.append((nr, nc))
    return  

for wall in walls:
    arr[wall[0][0]][wall[0][1]] = arr[wall[1][0]][wall[1][1]] = arr[wall[2][0]][wall[2][1]] = 1
    Q = vir.copy()
    cnt = 0
    spread()
    if cnt < inf: inf = cnt
    for b in empt: arr[b[0]][b[1]] = 0
    arr[wall[0][0]][wall[0][1]] = arr[wall[1][0]][wall[1][1]] = arr[wall[2][0]][wall[2][1]] = 0

print(safe - inf - 3)