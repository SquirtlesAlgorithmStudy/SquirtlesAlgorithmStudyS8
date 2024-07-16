//
//  main.swift
//  AlgorithmStudyS8JH
//
//  Created by 김지현 on 2024/07/16.
//

import Foundation

// 시도1. 시간초과 남
/*
let input = readLine()!.components(separatedBy: " ").map { Int($0)! }
var N = input[0]
let K = input[1]

var answer = 0
// 매번 2진수로 변환해서 1의 개수가 K개를 초과하는지 확인
// N이 최대 10^7 이므로 초과
while String(N, radix: 2).filter({ $0 == "1" }).count > K {
    answer += 1
    N += 1
}
print(answer)
 */

// 시도2.
let input = readLine()!.components(separatedBy: " ").map { Int($0)! }
var N = input[0]
let K = input[1]

// N을 2진수로 만들고 배열로 변경 Ex) 1110 -> ["1", "1", "1", "0"]
let binaryN = Array(String(N, radix: 2))
// 배열로 만든 2진수 N을 지수만 저장 Ex) ["1", "1", "1", "0"] -> [3, 2, 1]
var array: Array<Int> = []
for (idx, bin) in binaryN.enumerated() {
    if bin == "1" {
        array.append(binaryN.count - 1 - idx)
    }
}

// 만약 상점에서 더 살 필요가 없으면 0 출력
if array.count <= K {
    print(0)
} else { // K = 1 이라면 2^2 - 2^1 , K = 2 이라면 2^3 - (2^2 + 2^1)
    let sum = array[K..<array.count].reduce(0) {
        return Double($0) + pow(2.0, Double($1))
    }
    let neededBottleNum = pow(2, Double(array[K-1])) - sum
    print(Int(neededBottleNum))
}
