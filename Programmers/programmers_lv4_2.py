programmers_lv4_2.py
AL = 26
a = 'a'
MAX = 1000000
trie = [[0 for _ in range(AL)] for _ in range(MAX)]
cnt = [0 for _ in range(MAX)]
pos = 1

def solution(words):
    global pos, cnt, trie, MAX, a, AL
    answer = 0
    for word in words:
        now = 0
        for char in word:
            if (not trie[now][ord(char) - ord(a)]):
                trie[now][ord(char) - ord(a)] = pos
                pos += 1
            now = trie[now][ord(char) - ord(a)]
            cnt[now] += 1
            
    for word in words:
        now = 0
        temp = 0
        for char in word:
            now = trie[now][ord(char) - ord(a)]
            temp += 1
            if cnt[now] == 1:
                break
            
        answer += temp
    return answer