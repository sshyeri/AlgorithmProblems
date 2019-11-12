import sys
sys.stdin = open('input.txt')

V, E = map(int, input().split())
S = int(input())

dist = [3000001]*(V+1)
visited = [0]*(V+1)
P = [0] * (V+1)
dist[S] = 0
P[S] = S
graph = [[] for _ in range(V+1)]
for i in range(E):
	u, v, w = map(int, input().split())
	graph[u].append((v, w))

for _ in range(V):
	minidx = -1
	minw = 3000001
	for i in range(1, V+1):
		if not visited[i] and dist[i] < minw:
			minw = dist[i]
			minidx = i
	visited[minidx] = 1
	for v, w in graph[minidx]:
		if not visited[v] and dist[minidx] + w < dist[v]:
			dist[v] = dist[minidx] + w
			P[v] = minidx 
for i in range(1, V+1):
	if dist[i]==3000001: print('INF')
	else: print(dist[i])
