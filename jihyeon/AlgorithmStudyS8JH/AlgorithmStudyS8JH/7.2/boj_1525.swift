//
//  main.swift
//  AlgorithmStudyS8JH
//
//  Created by 김지현 on 2024/07/02.
//

import Foundation

// 최소 이동으로 번호판 만들기 (빠진 숫자는 0으로 표시)

// MARK: - Util Method
func from2DTo1D(_ r: Int, _ c: Int) -> Int {
    return 3 * r + c
}

func from1DTo2D(_ idx: Int) -> (Int, Int) {
    return (idx / 3, idx % 3)
}

func strSwap(_ left: Int, _ right: Int, _ text: String) -> String {
    var textArray = Array(text)
    textArray.swapAt(left, right)
    return String(textArray)
}
// MARK: - 구현
var visited = Set<String>()

/// 동서남북 (1,0) (-1,0) (0,1) (0,-1)
let dr = [1, -1, 0, 0]
let dc = [0, 0, 1, -1]

var board: [String] = []
for _ in 0..<3 {
    let line = readLine()!
    board += line.components(separatedBy: " ")
}

let zeroIdx = board.firstIndex(of: "0")!
/// initState -> (1차원배열로 바꾼 번호판, 0의1차원배열idx)
let initState = (board.joined(), zeroIdx)

func bfs(_ startState: (String, Int)) -> Int {
    var q = [(startState, 0)]
    var index = 0
    visited.insert(startState.0)

    /// queue에 있는 모든 state 탐색할 때까지
    while index < q.count {
        let (state, depth) = q[index]
        index += 1

        /// 완성된 번호판일 때 depth return
        if state.0 == "123456780" {
            return depth
        }

        let (r, c) = from1DTo2D(state.1)
        /// 동서남북 하나씩 모두 옮겨보고 nextState 정하는 과정
        for i in 0..<4 {
            let nr = r + dr[i]
            let nc = c + dc[i]

            /// 3*3 번호판 벗어날 경우 pass
            if nr < 0 || nr > 2 || nc < 0 || nc > 2 {
                continue
            }

            let nextIdx = from2DTo1D(nr, nc)
            let nextStateStr = strSwap(state.1, nextIdx, state.0)
            let nextState = (nextStateStr, nextIdx)

            /// 이미 탐색한 번호판 상태이므로 pass
            if visited.contains(nextState.0) {
                continue
            }

            /// 그 다음 depth를 탐방해야하는 nextState를 queue에 추가
            q.append((nextState, depth + 1))
            visited.insert(nextState.0)
        }
    }
    /// queue 모두 탐색했지만, "1234567890"에 도달하지 못했을 때
    return -1
}

print(bfs(initState))


