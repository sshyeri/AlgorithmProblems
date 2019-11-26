import sys
import heapq
sys.stdin = open("input.txt")

N = int(input())
M = int(input())
dist = [100_000*N]*(N+1)
edges = [[] for _ in range(N+1)]
for _ in range(M):
    u, v, w = map(int, input().split())
    edges[u].append((v, w))

S, E = map(int, input().split())
dist[S] = 0
heap = [(0, S)]

while heap:
    c, u = heapq.heappop(heap)
    if u==E: break
    if c != dist[u] : continue
    for v, w in edges[u]:
        if dist[v] > dist[u] + w:
            dist[v] = dist[u] + w
            heapq.heappush(heap, (dist[v], v))
print(dist[E])