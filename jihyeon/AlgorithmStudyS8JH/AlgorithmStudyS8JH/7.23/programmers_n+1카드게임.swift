// 프로그래머스 : https://school.programmers.co.kr/learn/courses/30/lessons/258707
// N + 1 카드게임

/*
 0 ≤ coin ≤ n
 6 ≤ cards의 길이 = n < 1,000
 cards[i]는 i+1번째로 뽑는 카드에 적힌 수를 나타냅니다.
 1 ≤ cards[i] ≤ n
 cards의 원소는 중복되지 않습니다.
 n은 6의 배수입니다.
 */

// 실패 -> 좀 더 봐야함
import Foundation

func solution(_ coin:Int, _ cards:[Int]) -> Int {
    let N = cards.count
    var round = 0
    var leftCoin: Int = coin
    var leftCards: [Int] = Array(cards[cards.count/3..<cards.count]) // 아직 안뽑은 남은 카드들
    var myCards: [Int] = Array(cards[0..<cards.count/3]) // 나에게 있는 내가 뽑은 카드들

    func dfs(mc: [Int], lc: [Int], coin: Int, r: Int) {
        round = max(r, round)
        print("round start     : \(mc), \(lc), \(coin)")
        if coin == 0 || lc.count < 2 { return }

        var poppedTwoCard: [Int] = Array(lc[0..<2])

        if let afterMyCards = canUseZeroCoin(n: N, mc) {
            print("case zero coin : \(mc), \(lc), \(coin)")
            dfs(mc: afterMyCards, lc: Array(lc[2..<lc.count]), coin: coin, r: r + 1)
            return
        } else if let afterMyCards1 = canUseOneCoin(n: N, mc, poppedTwoCard), coin >= 1 {
            print("case one coin : \(mc), \(lc), \(coin)")
            dfs(mc: afterMyCards1, lc: Array(lc[2..<lc.count]), coin: coin - 1, r: r + 1)
            return

        } else if (poppedTwoCard[0] + poppedTwoCard[1] == N + 1) && coin >= 2 {
            print("case two coin : \(mc), \(lc), \(coin)")
            dfs(mc: mc, lc: Array(lc[2..<lc.count]), coin: coin - 2, r: r + 1)
            return
        } else{
            return
        }
    }

    dfs(mc: myCards, lc: leftCards, coin: leftCoin, r: round)
    return round
}



// 내 카드끼리 합
func canUseZeroCoin(n: Int, _ myCards: [Int]) -> [Int]? {
    if myCards.count < 2 { return nil }
    var newMyCards: [Int] = myCards
    for i in 0..<myCards.count {
        let target = (n + 1) - myCards[i]
        if myCards.contains(target) {
            newMyCards.remove(at: i)
            newMyCards.remove(at: myCards.firstIndex(of: target)!)
            return newMyCards
        }
    }
    return nil
}

// 하나는 뽑은 카드, 하나는 내 카드 합
func canUseOneCoin(n: Int, _ myCards: [Int], _ poppedTwoCard: [Int]) -> [Int]? {
    if myCards.count < 1 { return nil }
    var newMyCards: [Int] = myCards
    for i in 0..<myCards.count {
        let target = (n + 1) - myCards[i]
        for j in 0..<2 {
            if poppedTwoCard[j] == target {
                newMyCards.remove(at: i)
                return myCards
            }
        }
    }
    return nil
}

print(solution(4, [3, 6, 7, 2, 1, 10, 5, 9, 8, 12, 11, 4]))
/*
 coin    cards    result
 4    [3, 6, 7, 2, 1, 10, 5, 9, 8, 12, 11, 4]    5
 3    [1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11, 12]    2
 2    [5, 8, 1, 2, 9, 4, 12, 11, 3, 10, 6, 7]    4
 10    [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18]    1
 */
