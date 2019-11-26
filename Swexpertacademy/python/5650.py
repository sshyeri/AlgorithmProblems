import sys
sys.stdin = open('input.txt')
dr = (1, -1, 0, 0)
dc = (0, 0, -1, 1)
change = {1: [3, 0, 1, 2],
          2: [1, 3, 0, 2],
          3: [1, 2, 3, 0],
          4: [2, 0, 3, 1],
          5: [1, 0, 3, 2]}

def play(r, c, d):
    global arr, chk, N, ans
    sr = r
    sc = c
    now = 1
    while not chk[r][c][d]:
        chk[r][c][d] = now
        r += dr[d]
        c += dc[d]
        if r<0 or r>=N or c<0 or c>=N:
            d = change[5][d]
            now += 1
            r += dr[d]
            c += dc[d]
        elif not arr[r][c]: continue
        elif arr[r][c]== -1 or (r==sr and c==sc):
            if now > ans: ans = now
            return
        elif arr[r][c]<=5:
            d = change[arr[r][c]][d]
            now += 1
        else:
            r, c = warm[(r, c)]


for tc in range(1, int(input())+1):
    N = int(input())
    warm = {}
    arr = [list(map(int, input().split())) for _ in range(N)]
    temp = [0]*5
    for r in range(N):
        for c in range(N):
            if arr[r][c]>5:
                if not temp[arr[r][c]-5]:
                    temp[arr[r][c] - 5] = (r, c)
                else:
                    warm[(r, c)] = temp[arr[r][c]-5]
                    warm[temp[arr[r][c]-5]] = (r, c)
    chk = [[[0, 0, 0, 0] for c in range(N)] for r in range(N)]
    ans = 1
    for r in range(N):
        for c in range(N):
            for d in range(4):
                if not arr[r][c]:
                    play(r, c, d)
    print(ans-1)