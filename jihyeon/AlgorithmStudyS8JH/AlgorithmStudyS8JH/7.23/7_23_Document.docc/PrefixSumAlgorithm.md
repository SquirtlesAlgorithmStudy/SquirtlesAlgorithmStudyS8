# Prefix Sum Algorithm
누적합 알고리즘

## OverView
누적합 알고리즘은 배열 각 요소에 대해, 그 이전 요소들까지의 합을 계산하는 알고리즘
ex. [1, 2, 3, 4, 5] -> [1, 3(1+2), 6(1+2+3), 10, 15]

## Swift 구현
```
func prefixSum(arr: [Int]) -> [Int] {
    var prefixSumArr = [Int](repeating: 0, count: arr.count)
    prefixSumArr[0] = arr[0]
    
    for i in 1..<arr.count { O(n)
        prefixSumArr[i] = prefixSumArr[i - 1] + arr[i]
    }
    
    return prefixSumArr
}

// 예제 배열
let arr = [1, 2, 3, 4, 5]
let result = prefixSum(arr: arr)
print(result)  // [1, 3, 6, 10, 15]
```
