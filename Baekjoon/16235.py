def init():
    r, c, a = map(int, input().split())
    r -= 1
    c -= 1
    return [r, c, a]

N, M, K = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(N)]
trees = [init() for _ in range(M)]
ground = [[5]*N for _ in range(N)]
deads = []
dr = (-1, -1, -1, 0, 0, 1, 1, 1)
dc = (-1, 0, 1, -1, 1, -1, 0, 1)
trees.sort(key=lambda x: x[2])

def spring():
    global deads
    deads.clear()
    for i, tree in enumerate(trees, 0):
        if ground[tree[0]][tree[1]] < tree[2]:
            deads.append(i)
        else:
            ground[tree[0]][tree[1]] -= tree[2]
            tree[2] += 1
def summer():
    while deads:
        r, c, a = trees.pop(deads.pop())
        ground[r][c] += a//2
def autumn():
    global trees
    for tree in trees:
        if not tree[2]%5:
            for d in range(8):
                nr = tree[0] + dr[d]
                nc = tree[1] + dc[d]
                if 0 <= nr < N and 0 <= nc < N:
                    deads.append([nr, nc, 1])
    trees = deads + trees

def winter():
    for i in range(N):
        for j in range(N):
            ground[i][j] += A[i][j]

for i in range(K):
    spring()
    summer()
    autumn()
    winter()
print(len(trees))
