import sys
sys.stdin = open('input.txt')


for tc in range(1, int(input())+1):
    N = int(input())
    arr = [list(map(int, input().split())) for _ in range(N)]
    ans = 0

    print('#{} {}'.format(tc, ans))p