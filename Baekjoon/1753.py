import heapq
V, E = map(int, input().split())
K = int(input())
edges = [[] for _ in range(V+1) ]
dist = [0] + [11*V]*V

for _ in range(E):
    u, v, w = map(int, input().split())
    edges[u].append((v, w))

dist[K] = 0
hq = [(0, K)]
while(hq):
    c, u = heapq.heappop(hq)
    if c != dist[u]: continue
    for v, w in edges[u]:
        if dist[v] > dist[u] + w:
            dist[v] = dist[u] + w
            heapq.heappush(hq, (dist[v], v))
for i in range(1, V+1):
    if dist[i] < V*11: print(dist[i])
    else: print('INF')
