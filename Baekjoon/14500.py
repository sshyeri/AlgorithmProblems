#pattern
N, M = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(N)]
ans = 0

def bar(i, j):
    global ans
    if i+2<N:
        temp = arr[i][j] + arr[i+1][j] + arr[i+2][j]
        for p in range(3): 
            if j-1>=0 : ans = max(ans, temp + arr[i+p][j-1])
            if j+1<M : ans = max(ans, temp + arr[i+p][j+1])
        if i+3<N: ans = max(ans, temp + arr[i+3][j])
    if j+2<M:
        temp = sum(arr[i][j:j+3])
        for p in range(3): 
            if i-1>=0 : ans = max(ans, temp + arr[i-1][j+p])
            if i+1<N : ans = max(ans, temp + arr[i+1][j+p])
        if j+3 < M : ans = max(ans, temp + arr[i][j+3])
    
def box(i, j):
    global ans
    temp = arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1]
    ans = max(ans, temp)
    if i+2 < N:
        ans = max(ans, temp - arr[i][j] + arr[i+2][j])
        ans = max(ans, temp - arr[i][j+1] + arr[i+2][j+1])
    if j+2<M:
        ans = max(ans, temp - arr[i+1][j] + arr[i+1][j+2])
        ans = max(ans, temp - arr[i][j] + arr[i][j+2])

for i in range(N):
    for j in range(M):
        bar(i, j)
        if i==N-1 or j==M-1: continue
        box(i, j)
print(ans)

