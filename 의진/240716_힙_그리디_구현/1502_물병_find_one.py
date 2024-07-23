import sys
input = sys.stdin.readline

n, k = map(int, input().split())

result = 0


def find_one(n):
    one_count = 0
    while n != 0:
        one_count += (n % 2)
        n //= 2
    return one_count


while find_one(n) > k:
    first_one_index = bin(n)[::-1].index('1')
    result += 2 ** first_one_index
    n += 2 ** first_one_index

print(result)
