import sys
sys.stdin = open('input.txt')

dr = (-1, 1, 0, 0)
dc = (0, 0, -1, 1)

def stem(arr):
	new = {}
	for k, v in arr.items():
		if v[0]==0 and v[1]:
			breed(*k, v[1], new)
		v[0]-=1
	arr.update(new)
def breed(r, c, v, new):
	for d in range(4):
		nr = r + dr[d]
		nc = c + dc[d]
		side = arr.get((nr, nc))
		if side==None or not side[1]:
			if not new.get((nr, nc)) or new[(nr, nc)][1]<v:
				new[(nr, nc)] = [v, v]
def alive(arr):
	ans = 0
	for v in arr.values():
		if v[1] and -v[1]<v[0]:
			ans += 1
	return ans

for tc in range(1, int(input())+1):
	N, M, K = map(int, input().split())
	arr = {}
	for i in range(N):
		for j, a in enumerate(map(int, input().split()), 0):
			arr[(i, j)] = [a, a]
	while K:
		K-=1
		stem(arr)		
	print('#{} {}'.format(tc, alive(arr)))
