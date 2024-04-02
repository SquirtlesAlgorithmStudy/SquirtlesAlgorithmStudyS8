import sys
input = sys.stdin.readline

question = input().rstrip()


def get_sum(text):
    return sum(map(int, text.split("+")))


add_values = sum(map(int, question.split("-")[0].split("+")))
subtract_values = sum(map(get_sum, question.split("-")[1:]))

print(add_values - subtract_values)
