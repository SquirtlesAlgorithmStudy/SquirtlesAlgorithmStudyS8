import sys
input = sys.stdin.readline

N = int(input())
prices = list(map(int, input().split()))
budget = int(input())

if N == 1:
    print(0)
    sys.exit()

# 1. 자리수 결정
num_and_prices = []
for num, price in enumerate(prices):
    num_and_prices.append((price, num))

num_and_prices.sort(key=lambda x: (x[0], -x[1]))

budget_for_digit_det = budget
if num_and_prices[0][1] == 0:
    budget_for_digit_det -= num_and_prices[1][0]
    if budget_for_digit_det < 0:
        print(0)
        sys.exit()
    msd = num_and_prices[1][1]
    digit_cnt = budget_for_digit_det // num_and_prices[0][0]
    remainer = budget_for_digit_det % num_and_prices[0][0]
    standard_num_str = str(msd) + ("0" * digit_cnt)

else:
    msd = num_and_prices[0][1]
    digit_cnt = budget_for_digit_det // num_and_prices[0][0]
    remainer = budget_for_digit_det % num_and_prices[0][0]
    standard_num_str = str(msd) * digit_cnt

if len(standard_num_str) == 0:
    print(0)
    sys.exit()

# 2. 큰 수로 대체


def get_replacing_cost(past, new):
    past_price = prices[past]
    new_price = prices[new]
    replacing_cost = new_price - past_price
    return replacing_cost


standard_num_list = list(standard_num_str)
for i, digit in enumerate(standard_num_list):
    for new in range(N-1, int(digit), -1):
        replacing_cost = get_replacing_cost(int(digit), new)
        if replacing_cost <= remainer:
            standard_num_list[i] = new
            remainer -= replacing_cost
            break

answer = ""
for digit in standard_num_list:
    answer += str(digit)
print(int(answer))
