//
//  main.swift
//  AlgorithmStudyS8JH
//
//  Created by 김지현 on 2024/07/04.
//

// 무조건 적은 것부터 더해 나가는 것이 가장 적은 횟수가 될 것이다
// 10 20 40 -> 10 + 20 + (10 + 20) + 40 -> (10 + 20) * 2 + 40
// 짝수라면 n / 2, 홀수라면 n / 2 + 1
// 1. 가장 작은 수 순서대로 sorting
// 2. 가장 작은 수 부터 두개씩 짝지어서 * n



import Foundation

/* 첫번째 시도
/* 오류 -> 30 40 50 60 이 있으면, 30+40 후 (30+40) + 50 이 아닌 50 < 60 < (30+40) 이르모 50+60을 해야한다 */
let count = Int(readLine()!)!
var array: [Int] = []
for _ in 0 ..< count {
    array.append(Int(readLine()!)!)
}
array.sort(by: <)

var answer: Int = array[0] * (count - 1)
for i in 1 ..< count {
    answer += array[i] * (count - i)
}

print(answer)
*/

/* 두번째 시도
/* 오류 -> 시간초과 */
let count = Int(readLine()!)!
var array: [Int] = []
for _ in 0 ..< count {
    array.append(Int(readLine()!)!)
}
array.sort(by: <)

if count == 1 {
    print(0)
} else {
    var answer: Int = 0
    for _ in 0 ... count / 2 {
        let sum = array[0] + array[1]
        answer += sum
        array.removeFirst()
        array.removeFirst()
        array.append(sum)
        array.sort(by: <)
    }
    print(answer)
}
*/

// 세번째 시도 -> 힙 직접 구현 & 0 ..< count/2이 아닌 0 ..< count-1

struct MinHeap {
    private var heap = [Int]()

    var isEmpty: Bool {
        return heap.isEmpty
    }

    var count: Int {
        return heap.count
    }

/// 힙의 최상위 요소를 반환 (여기서는 최소값), 비어있으면 nil
    func peek() -> Int? {
        return heap.first
    }

/// 힙에 새로운 값 추가, 값 추가 후 siftUp(from: )을 호출하여 힙 정렬
    mutating func insert(_ value: Int) {
        heap.append(value)
        siftUp(from: heap.count - 1)
    }

/// 힙의 최상위 요소를 제거하고 반환, 최상위 요소를 제거하고, 마지막 요소를 루트로 이동시키고, siftDown(from: )을 호출하여 힙 정렬
    mutating func remove() -> Int? {
        guard !heap.isEmpty else {
            return nil
        }
        if heap.count == 1 {
            return heap.removeFirst()
        } else {
            let value = heap[0]
            heap[0] = heap.removeLast()
            siftDown(from: 0)
            return value
        }
    }

/// 가장 하위 노드 부터 siftUp(from: )을 통해 정렬
    private mutating func siftUp(from index: Int) {
        var childIndex = index
        let childValue = heap[childIndex]
        var parentIndex = (childIndex - 1) / 2

        /// 부모가 자식보다 큰 경우 계속 위치 변경
        while childIndex > 0 && childValue < heap[parentIndex] {
            heap[childIndex] = heap[parentIndex]
            childIndex = parentIndex
            parentIndex = (childIndex - 1) / 2
        }

        /// childIdx가 정해지면 추가된 값을 heap[childIndex]에 대입
        heap[childIndex] = childValue
    }

/// 가장 하위 노드를 루트로 이동 시킨 후 루트 인덱스 부터 siftDown(from: )을 통해 정렬
    private mutating func siftDown(from index: Int) {
        let count = heap.count
        var parentIndex = index
        let parentValue = heap[parentIndex]
        var childIndex = 2 * parentIndex + 1

        /// 가장 하위 노드까지 확인
        while childIndex < count {
            /// 오른쪽 자식이 왼쪽 자식보다 작다면 바꿀 자식노드를 오른쪽으로 변경 (바꿀 자식 선택)
            if childIndex + 1 < count && heap[childIndex + 1] < heap[childIndex] {
                childIndex += 1
            }
            /// 자식이 비교 대상인 루트값보다 크거나 같다면 break
            if parentValue <= heap[childIndex] {
                break
            }
            /// 자식값 위로 올림
            heap[parentIndex] = heap[childIndex]
            parentIndex = childIndex
            childIndex = 2 * parentIndex + 1
        }

        /// parentIdx가 정해지면 루트에 있었던 값을 heap[parentIndex]에 대입
        heap[parentIndex] = parentValue
    }
}

let count = Int(readLine()!)!
var heap = MinHeap()
for _ in 0 ..< count {
    heap.insert(Int(readLine()!)!)
}

if count == 1 {
    print(0)
} else {
    var answer: Int = 0
    for _ in 0 ..< count-1 {
        let num1 = heap.remove()!
        let num2 = heap.remove()!
        let sum = num1 + num2
        answer += sum
        heap.insert(sum)
    }
    print(answer)
}
