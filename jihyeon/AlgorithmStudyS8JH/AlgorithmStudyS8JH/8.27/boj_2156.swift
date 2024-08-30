//
//  main.swift
//  AlgorithmStudyS8JH
//
//  Created by 김지현 on 8/26/24.
//

import Foundation

var glasses: [Int] = [0]
let glassCnt: Int = Int(readLine()!)!
for _ in 1 ... glassCnt {
  glasses.append(Int(readLine()!)!)
}

// - 두번째 시도
var dp: [Int] = Array(repeating: 0, count: glassCnt + 1)
for i in 1 ... glassCnt {
  if i == 1 {
    dp[i] = glasses[i]
  } else if i == 2 {
    dp[i] = glasses[i-1] + glasses[i]
  } else {
    // 4개라고 가정할 때, (1+2+new), (1+3+new), 제일 최근 max (연달아 세개가 될 경우) 중 max
    dp[i] = max(dp[i-2] + glasses[i], dp[i-3] + glasses[i-1] + glasses[i], dp[i-1])
  }
}

print(dp[glassCnt])

// - 첫번째 시도

//var dp: [[Int]] = Array(repeating: [], count: glassCnt + 1)
//for glassIdx in 1 ... glassCnt {
//  if glassIdx == 1 {
//    dp[1] = [0]
//  } else if glassIdx == 2 {
//    dp[2] = [0,1]
//  } else {
//    dp[glassIdx] = makeMax(prevMaxArr: dp[glassIdx-1], newIdx: glassIdx-1)
//  }
//
//}
//print(dp[glassCnt].reduce(0, { $0 + glasses[$1] }))
//
//func makeMax(prevMaxArr: [Int], newIdx: Int) -> [Int] {
//  var newMaxArr: [Int] = prevMaxArr
//
//  if prevMaxArr[prevMaxArr.count - 2] + 1 == prevMaxArr[prevMaxArr.count - 1] &&
//      prevMaxArr[prevMaxArr.count - 1] + 1 == newIdx  {
//    let prevMax = prevMaxArr.max(by: { glasses[$0] < glasses[$1] })!
//    let prevMin = prevMaxArr.min(by: { glasses[$0] < glasses[$1] })!
//    let prevMaxSum = prevMaxArr.reduce(0, { $0 + glasses[$1] })
//
//    if  glasses[prevMax] + glasses[newIdx] > prevMaxSum  {
//      newMaxArr.remove(at: prevMin)
//      newMaxArr.append(newIdx)
//    }
//  } else {
//    newMaxArr.append(newIdx)
//  }
//
//  return newMaxArr
//}
