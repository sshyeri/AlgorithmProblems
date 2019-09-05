
ans = 0
def dfs(n, s, arr, chk):
    global ans
    if not n: 
        ans += 1
        return
    chk[s] = 1
    for nex in arr[s]:
        if not chk[nex]:
            chk[nex] = 1
            dfs(n-1, nex, arr, chk)
            chk[nex] = 0 
    chk[s] = 0
    return     

for tc in range(1, int(input())+1):
    #N입력받아 배열 생성
    N, M = map(int, input().split())
    N+=1
    ans = 0
    chk = [0]*N
    arr = [[] for i in range(N)]
    #M입력받아 엣지 정보 저장
    for edge in range(M):
        a, b = map(int, input().split())
        arr[a].append(b)
        arr[b].append(a)
    if(M>3):
        for i in range(1, N):
            dfs(4, i, arr, chk)
    print('#{} {}'.format(tc, ans))