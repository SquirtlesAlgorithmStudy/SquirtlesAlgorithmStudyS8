//
//  main.swift
//  AlgorithmStudyS8JH
//
//  Created by 김지현 on 8/5/24.
//

import Foundation

typealias Meeple = (boardIdx: Int, positionIdx: Int)

let moves = readLine()!.components(separatedBy: " ").map { Int($0)! }
// 탐색 공간
// 25, 30, 35, 40이 각각 보드에 다 존재하면 안됨 (중복 체크 못함)
// through10, **20, **30 모두 첫자리를 비워둬야함 (0으로 비워둠)

let straightBoard: [Int] = Array(stride(from: 0, to: 40, by: 2))
let through10Board: [Int] = [10, 13, 16, 19]
let through20Board:[Int] = [20, 22, 24]
let through30Board: [Int] = [30, 28, 27, 26]
let lastCommonBoard: [Int] = [25, 30, 35, 40, 0]
let board: [[Int]] = [straightBoard, through10Board, through20Board, through30Board, lastCommonBoard]

var meeples = [Meeple].init(repeating: Meeple(0,0), count: 4)

var maxScore: Int = 0

func moveMeeple(_ meeple: Meeple, for move: Int) -> Meeple {
  let curBoard = board[meeple.boardIdx]

  if curBoard == straightBoard { // 1. 현재 꺾는 곳 없이 가장 크게 한바퀴를 돌고 있는 경우
    let movedIdx = meeple.positionIdx + move

    if movedIdx > 20 { // movedIdx가 20을 초과한 경우, 보드판을 벗어나 lastCommonBoard의 마지막인덱스로
      return (4, 4)

    } else if movedIdx == 20 {
      return (4, 3)
    } else {
      let movedScore = straightBoard[movedIdx]
      if movedScore == 10 { // 10에서 멈춘경우, through10Board의 첫번째로 변경
        return (1, 0)
      } else if movedScore == 20 { // 20에서 멈춘경우, through10Board의 첫번째로 변경
        return (2, 0)
      } else if movedScore == 30 { // 30에서 멈춘경우, through10Board의 첫번째로 변경
        return (3, 0)
      } else { // 위 해당사항에 포함되지 않으면 straightBoard에서 쭉 이동
        return (0, movedIdx)
      }
    }

  } else if curBoard == through10Board { // 2. [0, 13, 16, 19]
    let movedIdx = meeple.positionIdx + move
    if movedIdx > 3 { // through10Board를 벗어나면 lastCommonBoard로 이동
      return (4, movedIdx - through10Board.count)
    } else {
      return (1, movedIdx)
    }

  } else if curBoard == through20Board { // 3. [0, 22, 24]
    let movedIdx = meeple.positionIdx + move
    if movedIdx > 2 { // through10Board를 벗어나면 lastCommonBoard로 이동
      return (4, movedIdx - through20Board.count)
    } else {
      return (2, movedIdx)
    }

  } else if curBoard == through30Board { // 4. [0, 28, 27, 26]
    let movedIdx = meeple.positionIdx + move
    if movedIdx > 3 { // through10Board를 벗어나면 lastCommonBoard로 이동
      return (4, movedIdx - through30Board.count)
    } else {
      return (3, movedIdx)
    }

  } else { // 5. curBoard == lastCommonBoard -> [25, 30, 35, 40, 0]
    let movedIdx = min(meeple.positionIdx + move, 4)
    return (4, movedIdx)
  }
}

func play(_ turn: Int, _ score: Int) {
  guard turn < 10 else {
    if maxScore < score { maxScore = score }
    return
  }

  for movingIdx in 0..<4 where meeples[movingIdx] != (4, 4) {
    let meeple = meeples[movingIdx]

    let movedMeeple = moveMeeple(meeple, for: moves[turn])
    // 놓여져 있는 말과 동일한 위치에 있을 수 없으므로 비교를 한다
      // 조건1. 이미 완주한 말은 비교대상에서 제외
      // 조건2. 현재 이동중인 말 비교대상에서 제외
    var canMove = true
    for compareIdx in 0..<4 where meeples[compareIdx] != (4, 4) && compareIdx != movingIdx {
      if meeples[compareIdx] == movedMeeple { // 이미 이동하고자 하는 위치에 다른 말이 있다면
        canMove = false
        break
      }
    }

    if canMove {
      meeples[movingIdx] = movedMeeple
      play(turn + 1, score + board[movedMeeple.boardIdx][movedMeeple.positionIdx])
      meeples[movingIdx] = meeple
    }
  }
}

play(0,0)
print(maxScore)
