//
//  main.swift
//  AlgorithmStudyS8JH
//
//  Created by 김지현 on 8/26/24.
//

import Foundation

let houseCnt: Int = Int(readLine()!)!
var RGB: [[Int]] = [[0,0,0]]
for _ in 1 ... houseCnt {
  let rgb = readLine()!.components(separatedBy: " ").map { Int($0)! }
  RGB.append(rgb)
}

var dp = [(sum: Int, last: Int)].init(repeating: (0,0), count: houseCnt + 1)
for i in 1 ... houseCnt {
  if i == 1 {
    let min = RGB[i].min()!
    dp[i] = (min, RGB[i].firstIndex(of: min)!)
  } else {
    var rgb = RGB[i]
    _ = rgb.remove(at: dp[i-1].last)
    let min = rgb.min()!
    print(rgb, dp[i-1].last, min)
    dp[i] = (min + dp[i-1].sum, RGB[i].firstIndex(of: min)!)
  }
}

print(dp[houseCnt].sum)

// 예제3, 5 통과 못함
