//
//  main.swift
//  AlgorithmStudyS8JH
//
//  Created by 김지현 on 9/21/24.
//

/*
 N은 거리에 있는 아이들의 수,M은 아이들의 친구 관계 수, K는 울음소리가 공명하기 위한 최소 아이의 수이다.
 둘째 줄에는 아이들이 받은 사탕의 수를 나타내는 정수
 셋째 줄부터 M개 줄에 갈쳐 각각의 줄에 정수 a, b가 주어진다.
 이는 a와 b가 친구임을 의미한다. 같은 친구 관계가 두 번 주어지는 경우는 없다.
 */

// 시간초과
// Q 친구 관계가 없는 아이는 없나

import Foundation

let firstLine = readLine()!.components(separatedBy: " ").map { Int($0)! }
let N = firstLine[0] // 아이 수
let M = firstLine[1] // 아이들의 관계 수
let K = firstLine[2] // 공명 가능한 최소 아이 수

// 아이의 숫자가 1부터 시작하기 때문에 idx 0에 허수 삽입
var candies: [Int] = [0] +  readLine()!.components(separatedBy: " ").map { Int($0)! }
var friends: [Int] = Array.init(repeating: 1, count: N + 1)

// Union Find
var parent = Array(0...N)
func find(_ num: Int) -> Int {
  if num != parent[num] {
    parent[num] = find(parent[num])
  }
  return parent[num]
}

func unionFind(x: Int, y: Int) {
  let rootX = find(x)
  let rootY = find(y)
  if rootX != rootY {
    if rootX < rootY {
      parent[rootY] = rootX
    } else {
      parent[rootX] = rootY
    }
  }
}

// [0, 1, 2, 1, 4, 2, 2, 7, 7, 4, 2]
for _ in 0 ..< M {
  let r = readLine()!.components(separatedBy: " ").map { Int($0)! }
  unionFind(x: r[0], y: r[1])
}

for i in 0 ... N {
  if i != parent[i] {
    friends[find(i)] += 1
    candies[find(i)] += candies[i]
    // root가 되는 친구의 index에 그룹 내의 친구 수, 사탕 수가 저장될 것
  }
}

parent = Array(Set(parent).subtracting([0]))
// 아이들을 다 돌 필요 없이 우두머리 친구를 통해 그룹 통째로 확인하면 됨
var dp: [[Int]] = [[Int]](repeating: [Int](repeating: 0, count: K+1), count: parent.count)
for i in 0 ..< parent.count {
  let rep = parent[i]
  for j in 1 ... K {
    if i == 0 {
      dp[i][j] = friends[rep] <= j ? candies[rep] : 0
    } else {
      if friends[rep] <= j { // 그룹 다 뺏어도 들키지 않는 범위 내일 때
        dp[i][j] = max(dp[i-1][j], dp[i-1][j-friends[rep]] + candies[rep])
      } else { // 이 그룹의 사탕을 뺏을 경우 K를 넘어갈 때
        dp[i][j] = dp[i-1][j]
      }
    }
  }
}

print(dp.last![K-1])
