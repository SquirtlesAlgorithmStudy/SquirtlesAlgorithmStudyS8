//
//  main.swift
//  AlgorithmStudyS8JH
//
//  Created by 김지현 on 8/25/24.
//

// 2×n 직사각형을 1×2, 2×1과 2×2 타일로 채우는 방법의 수를 구하는 프로그램을 작성하시오.

import Foundation

let n = Int(readLine()!)!
var dp: [Int] = Array(repeating: 0, count: n+1)

if n == 1 {
  print(1)
} else if n == 2 {
  print(3)
} else {
  dp[1] = 1
  dp[2] = 3
  for i in 3...n {
    dp[i] = (dp[i-1] + 2*dp[i-2]) % 10007
  }
  print(dp[n])
}
