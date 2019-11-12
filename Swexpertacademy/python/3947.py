import sys
import heapq
sys.stdin = open('input.txt')

for tc in range(1, int(input())+1):
    N, M = map(int, input().split())
    costs = {}
    for i in range(M):
        s, e, c = map(int, input().split())
        if s in costs:
            costs[s].append((e, c))
        else:
            costs[s] = [(e, c)]
    dist = []
    print(costs)