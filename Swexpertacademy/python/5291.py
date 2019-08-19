arr = [1 if (not i%2 or not i%3) and i>3 else 0 for i in range(1000001)]
for tc in range(1, int(input())+1):
    a, b = map(int, input().split())
    ans = 0 if a>2 else 2
    for i in range(3, b, 2):
        if not arr[i]:
            if i>a:
                ans += i
            for j in range(i+i, b, i):
                if not arr[j]:
                    arr[j] = 1
    print(f'#{tc} {ans}')