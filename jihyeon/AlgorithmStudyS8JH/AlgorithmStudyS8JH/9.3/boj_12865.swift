//
//  boj_12865.swift
//  AlgorithmStudyS8JH
//
//  Created by 김지현 on 9/3/24.
//

import Foundation

let firstLine = readLine()!.components(separatedBy: " ").map { Int($0)! }
var N: Int = firstLine[0] // (1 <= N(물품의 수) <= 100)
var K: Int = firstLine[1] // (1 <= K(버틸 수 있는 총 무게) <= 100,000)

var objects: [(W: Int, V: Int)] = []
for i in 0 ..< N {
  let object = readLine()!.components(separatedBy: " ").map { Int($0)! }
  objects.append((object[0], object[1]))
}

var dp: [[Int]] = [[Int]](repeating: [Int](repeating: 0, count: K+1), count: N)

for i in 0..<N {
  for j in 1...K {

    if i == 0 { // 첫번째 object ex (6,13)만 고려할 땐, K가 6보다 같거나 작으면 13이 최대 V이다
      if j >= objects[i].W {
        dp[i][j] = objects[i].V
      }
    } else {
      if objects[i].W <= j { // W <= K
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-objects[i].W] + objects[i].V)
      } else { // W > K
        dp[i][j] = dp[i-1][j]
      }
    }

  }
}

print(dp[N-1][K])
