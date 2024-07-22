# Binary Search Algorithm
이분탐색 알고리즘

## OverView
- 이분탐색 알고리즘은 정렬된 배열에서 특정 값을 찾기 위해 사용하는 알고리즘이다.
- 이 알고리즘은 배열을 반복적으로 반으로 나누면서 목표 값을 찾아가는 방식으로 동작한다.
- 이를 통해 검색 범위를 매 단계마다 절반으로 줄일 수 있으므로, 시간 복잡도가 **O(log n)**이다.

## 장단점
### 이분탐색의 장점
빠른 검색 속도: 시간 복잡도가 O(log n)으로, 배열의 크기가 커져도 검색 시간이 크게 증가하지 않는다
### 이분탐색의 단점
정렬 필요: 배열이 정렬되어 있어야만 사용할 수 있다

## Swift 구현
```
func binarySearch(arr: [Int], target: Int) -> Int? {
    // 1. 배열의 시작점(왼쪽 인덱스)과 끝점(오른쪽 인덱스)을 설정
    var left = 0
    var right = arr.count - 1
    
    // 시작점이 끝점보다 커질 때까지(검색 범위가 유효할 때까지) 반복
    while left <= right {
        // 2. 시작점과 끝점의 중간 인덱스를 계산
        let mid = left + (right - left) / 2
        
        if arr[mid] == target { // 3-1. 만약 중간점의 값이 목표 값과 같다면, 중간 인덱스를 반환
            return mid
        } else if arr[mid] < target { // 3-2. 만약 중간점의 값이 목표 값보다 작다면, 목표 값은 중간점 오른쪽에 있으므로 검색 범위를 중간점의 오른쪽 절반으로 좁힌다
            left = mid + 1
        } else { // 3-3. 만약 중간점의 값이 목표 값보다 크다면, 목표 값은 중간점 왼쪽에 있으므로 검색 범위를 중간점의 왼쪽 절반으로 좁힌다
            right = mid - 1
        }
    }
    
    // 검색 범위가 유효하지 않게되면 목표값이 배열에 존재하지 않으므로 nil 반환
    return nil
}

// 예제 배열
let arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
if let index = binarySearch(arr: arr, target: 7) {
    print("Target found at index \(index)")
} else {
    print("Target not found in the array")
}
```
