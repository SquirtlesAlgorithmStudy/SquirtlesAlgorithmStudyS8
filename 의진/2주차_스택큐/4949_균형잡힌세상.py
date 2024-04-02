import sys
input = sys.stdin.readline

while True:
    sentence = input().rstrip()
    is_passed = True
    if sentence == ".":
        break
    stack = []
    for char in sentence:
        if char == "[" or char == "(":
            stack.append(char)
        elif char == "]":
            if stack and stack[-1] == "[":
                stack.pop()
            else:
                is_passed = False
                break
        elif char == ")":
            if stack and stack[-1] == "(":
                stack.pop()
            else:
                is_passed = False
                break
    if stack:
        is_passed = False

    print("yes") if is_passed else print("no")
