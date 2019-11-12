
N, M = map(int, input().split())
arr = [0] + [list(map(int, input().split()[1:])) for _ in range(N)]
ans = 0
werk = [0] * (N+1)
def chk(i):
	global visited
	if visited[i]: return 0
	visited[i] = 1
	for n in arr[i]:
		if not werk[n] or chk(werk[n]):
			werk[n] = i
			return 1
	return 0

for i in range(1, N+1):
	visited = [0]*(N+1)
	if chk(i): ans += 1
print(ans)
