import sys
sys.stdin = open("암호코드스캔_input.txt")

codes = ['0001101', '0011001', '0010011', '0111101', '0100011',
        '0110001', '0101111', '0111011', '0110111', '0001011']
def iswall(i, j):
    return i<0 or j<0 or i>N-1 or j>M-1 or arr[i][j]=='0'

def find_code(i, j):
    t = ''
    while not iswall(i, j):
        t += arr[i][j]
        j += 1
    return t

def change_code(i, j, p, c):

    while not iswall(i, j):
        arr[i]=arr[i].replace(p, c)
        i += 1

def HtoB(H):
    b = ''
    for n in H:
        t = ''
        if n > '9':
            n = ord(n) - 55
        else:
            n = int(n)
        for _ in range(4):
            t = str(n % 2) + t
            n //= 2
        b += t
    return b

def verify(binN):
    realcode = ''
    for i in range(len(binN)-1, -1, -1):
        if binN[i]!='0':
            if (i+1)%7: return False
            else: k = (i+1)//56
            break
    for j in range(0, i+1, k*7):
        for n, code in enumerate(codes):
            for p in range(j, j+k*7):
                if code[(p-j)//k]!=binN[j]:
                    break
            else:
                realcode += str(n)
    print(realcode)


for tc in range(int(input())):
    N, M = map(int, input().split())
    arr = [input() for _ in range(N)]
    hexs = []
    bins = []
    for i in range(N):
        for j in range(M):
            if arr[i][j] != '0':
                p = find_code(i, j)
                k = len(p)
                if k>=14:
                    hexs.append(p)
                    bins.append(HtoB(p))
                    verify(bins[-1])
                change_code(i, j, p, '0'*k)


    print(hexs)
    print(bins)
