N, M = map(int, input().split())
rr, rc, rd = map(int, input().split())
room = [list(map(int, input().split())) for _ in range(N)]
ans = 0
dr = (-1, 0, 1, 0)
dc = (0, 1, 0, -1)

def clean(r, c, d):
    global ans, room
    if not room[r][c]:
        room[r][c] = -1
        ans += 1
    for _ in range(4):
        d -= 1
        if d<0: d+=4
        nr = r + dr[d]
        nc = c + dc[d]
        if 0<= nr <N and 0<= nc <M and not room[nr][nc]:
            return clean(nr, nc, d)
    nr = r + dr[d-2]
    nc = c + dc[d-2]
    if 0 <= nr < N and 0 <= nc < M and room[nr][nc] != 1:
        return clean(nr, nc, d)
    return

clean(rr, rc, rd)
print(ans)
