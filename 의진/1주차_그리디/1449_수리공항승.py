import sys
input = sys.stdin.readline

N, L = map(int, input().split())
leaks = list(map(int, input().split()))
leaks.sort()

is_fixed = {leak: False for leak in leaks}
answer = 0

for leak in leaks:
    if not is_fixed[leak]:
        answer += 1
        for i in range(1, L):
            if leak + i in is_fixed.keys():
                is_fixed[leak + i] = True
print(answer)
