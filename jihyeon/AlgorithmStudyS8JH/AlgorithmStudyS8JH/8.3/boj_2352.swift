//
//  main.swift
//  AlgorithmStudyS8JH
//
//  Created by 김지현 on 8/5/24.
//

// 문제 유형 파악에 시간 소모
import Foundation

let _ = Int(readLine()!)!
var list = readLine()!.split(separator: " ").map{ Int(String($0))! }
var lisList: [Int] = [list[0]]

for i in 1..<list.count {
  if lisList.last! < list[i] {
    lisList.append(list[i])
  } else {
    binarySearch(&lisList, list[i])
  }
}

func binarySearch(_ list: inout [Int], _ x: Int) {
  var start = 0
  var end = list.count - 1

  while start < end {
    let mid = (start + end) / 2
    if list[mid] < x {
      start = mid + 1
    } else {
      end = mid
    }
  }
  list[end] = x
}

print(lisList.count)
