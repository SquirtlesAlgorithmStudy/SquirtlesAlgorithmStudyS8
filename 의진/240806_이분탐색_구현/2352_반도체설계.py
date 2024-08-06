import sys
import bisect
input = sys.stdin.readline

N = int(input())
ports = list(map(int, input().split()))
lis = []

for port in ports:
    if not lis or lis[-1] < port:
        lis.append(port)
    else:
        lis[bisect.bisect_right(lis, port)] = port

print(len(lis))
