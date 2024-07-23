# https://velog.io/@oxboxx/n-1-%EC%B9%B4%EB%93%9C%EA%B2%8C%EC%9E%84-2024-%EC%B9%B4%EC%B9%B4%EC%98%A4-%EA%B2%A8%EC%9A%B8-%EC%9D%B8%ED%84%B4%EC%8B%AD-Python
from collections import deque


def solution(coin, cards):
    N = len(cards)
    initial = set(cards[:N//3])
    not_yet = deque(cards[N//3:])
    possible = set()

    def update_possible():
        if not_yet:
            possible.add(not_yet.popleft())
            possible.add(not_yet.popleft())

    # source에서 숫자 하나를 고르고, 그 숫자에 맞는 쌍을 target에서 찾습니다.
    # 찾는 데 성공했다면 True를 반환하고, 실패했다면 False를 반환합니다.
    def remove_pair(source: set, target: set) -> bool:
        nonlocal coin, round
        for x in list(source):
            if N+1-x in target:
                source.remove(x)
                target.remove(N+1-x)
                return True
        return False

    round = 1
    while not_yet:
        update_possible()
        if remove_pair(initial, initial):
            round += 1
        elif coin >= 1 and remove_pair(initial, possible):
            coin -= 1
            round += 1
        elif coin >= 2 and remove_pair(possible, possible):
            coin -= 2
            round += 1
        else:
            break

    return round
