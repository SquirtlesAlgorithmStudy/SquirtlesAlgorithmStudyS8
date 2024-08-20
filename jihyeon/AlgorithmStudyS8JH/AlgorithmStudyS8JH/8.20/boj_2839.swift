//
//  boj_2839.swift
//  AlgorithmStudyS8JH
//
//  Created by 김지현 on 8/20/24.
//

import Foundation

var num = Int(readLine()!)!
var count = 0

while true {
    if num % 5 == 0 {
        print(num/5 + count)
        break
    } else {
        num -= 3
        count += 1
        if num == 0 {
            print(count)
            break
        } else if num < 0 {
            print(-1)
            break
        }
    }
}
