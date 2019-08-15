def chk(i, j):
    for p in range(8):
        ni, nj = i+dr[p], j+dc[p]
        while 0<=ni<N and 0<=nj<N:
            if arr[ni][nj]==2: return False
            arr[ni][nj] = 1
            ni += dr[p]
            nj += dc[p]
    return True
def nextqueen(i, j):
    for p in range(i+1, N):
        for q in range(N):
            if not arr[p][q]: 
                arr[p][q] = 2
                return p, q
    return False

N = int(input())
dr = (-1, -1, -1, 0, 1, 1, 1, 0)
dc = (-1, 0, 1, 1, 1, 0, -1, -1)
cnt = 0
for i in range(N):
    for j in range(N):
        Q = [(i, j)]
        arr = [[0]*N for _ in range(N)]
        arr[i][j]=2
        chk(i, j)
        for k in range(N-1):
            r, c = Q.pop(0)
            temp = nextqueen(r, c)
            if not temp: break
            if not chk(*temp): break
            Q.append(temp)
        else: cnt += 1
print(cnt)