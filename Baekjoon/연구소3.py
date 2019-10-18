N, ST = input().split()
numbers = [list(input().split()) for _ in range(int(N))]
print(numbers)
mga = int(max(numbers)[0])
se = mga*2 - 1
arr = [[] for _ in range(se)]
def one(ga, se, s, e):
    i=0
    while i<s:
        arr[i] += ['.' * ga]
        i+=1
    while i<=e:
        arr[i] += ['.' * (ga-1) + '#']
        i+=1
    while i<se:
        arr[i] += ['.'* ga]
        i+=1
def two(ga, se, s, e):
    i = 0
    while i < s:
        arr[i] += ['.' * ga]
        i += 1
    arr[i] += ['#' * ga]
    i+=1
    while i < (s+e)//2:
        arr[i] += ['.' * (ga - 1) + '#']
        i += 1
    arr[i] += ['#' * ga]
    i+=1
    while i < e:
        arr[i] += ['#' + '.' * (ga - 1)]
        i += 1
    arr[i] += ['#' * ga]
    i+=1
    while i < se:
        arr[i] += ['.' * ga]
        i += 1
def three(ga, se, s, e):
    i = 0
    while i < s:
        arr[i] += ['.' * ga]
        i += 1
    arr[i] += ['#' * ga]
    i+=1
    while i < (s+e)//2:
        arr[i] += ['.' * (ga - 1) + '#']
        i += 1
    arr[i] += ['#' * ga]
    i+=1
    while i < e:
        arr[i] += ['.' * (ga - 1) + '#']
        i += 1
    arr[i] += ['#' * ga]
    i+=1
    while i < se:
        arr[i] += ['.' * ga]
        i += 1
def four(ga, se, s, e):
    i = 0
    while i < s:
        arr[i] += ['.' * ga]
        i += 1
    while i < (s+e)//2:
        arr[i] += ['#' + '.' * (ga - 2) + '#']
        i += 1
    arr[i] += ['#' * ga]
    i+=1
    while i <= e:
        arr[i] += ['.' * (ga - 1) + '#']
        i += 1
    while i < se:
        arr[i] += ['.' * ga]
        i += 1
def five(ga, se, s, e):
    i = 0
    while i < s:
        arr[i] += ['.' * ga]
        i += 1
    arr[i] += ['#' * ga]
    i+=1
    while i < (s+e)//2:
        arr[i] += ['#' + '.' * (ga - 1)]
        i += 1
    arr[i] += ['#' * ga]
    i+=1
    while i < e:
        arr[i] += ['.' * (ga - 1) + '#']
        i += 1
    arr[i] += ['#' * ga]
    i+=1
    while i < se:
        arr[i] += ['.' * ga]
        i += 1
def six(ga, se, s, e):
    i = 0
    while i < s:
        arr[i] += ['.' * ga]
        i += 1
    while i < (s+e)//2:
        arr[i] += ['#' + '.' * (ga - 1)]
        i += 1
    arr[i] += ['#' * ga]
    i+=1
    while i < e:
        arr[i] += ['#' + '.' * (ga - 2) + '#']
        i += 1
    arr[i] += ['#' * ga]
    i+=1
    while i < se:
        arr[i] += ['.' * ga]
        i += 1
def seven(ga, se, s, e):
    i=0
    while i<s:
        arr[i] += ['.' * ga]
        i+=1
    arr[i] += ['#' * ga]
    i += 1
    while i<=e:
        arr[i] += ['.' * (ga-1) + '#']
        i+=1
    while i<se:
        arr[i] += ['.'* ga]
        i+=1
def eight(ga, se, s, e):
    i = 0
    while i < s:
        arr[i] += ['.' * ga]
        i += 1
    arr[i] += ['#' * ga]
    i += 1
    while i < (s+e) // 2:
        arr[i] += ['#' + '.' * (ga - 2) + '#']
        i += 1
    arr[i] += ['#' * ga]
    i += 1
    while i < e:
        arr[i] += ['#' + '.' * (ga - 2) + '#']
        i += 1
    arr[i] += ['#' * ga]
    i += 1
    while i < se:
        arr[i] += ['.' * ga]
        i += 1
def nine(ga, se, s, e):
    i = 0
    while i < s:
        arr[i] += ['.' * ga]
        i += 1
    arr[i] += ['#' * ga]
    i += 1
    while i < (s+e) // 2:
        arr[i] += ['#' + '.' * (ga - 2) + '#']
        i += 1
    arr[i] += ['#' * ga]
    i += 1
    while i <= e:
        arr[i] += ['.' * (ga - 1) + '#']
        i += 1
    while i < se:
        arr[i] += ['.' * ga]
        i += 1
def zero(ga, se, s, e):
    i = 0
    while i < s:
        arr[i] += ['.' * ga]
        i += 1
    arr[i] += ['#' * ga]
    i += 1
    while i < e:
        arr[i] += ['#' + '.' * (ga - 2) + '#']
        i += 1
    arr[i] += ['#' * ga]
    i += 1
    while i < se:
        arr[i] += ['.' * ga]
        i += 1
for number in numbers:
    ga = int(number[0])
    s = 0
    e = se-1
    if ga<mga:
        if ST=='TOP':
            e//=2
        elif ST=='MIDDLE':
            s = se//4
            e = se-s-1
        else:
            s = se//2
    for n in number[1]:
        if n == '1':
            one(ga, se, s, e)
        if n == '2':
            two(ga, se, s, e)
        if n=='3':
            three(ga, se, s, e)
        if n=='4':
            four(ga, se, s, e)
        if n=='5':
            five(ga, se, s, e)
        if n=='6':
            six(ga, se, s, e)
        if n=='7':
            seven(ga, se, s, e)
        if n=='8':
            eight(ga, se, s, e)
        if n=='9':
            nine(ga, se, s, e)
        if n=='0':
            zero(ga, se, s, e)
for ans in arr:
    print(*ans)