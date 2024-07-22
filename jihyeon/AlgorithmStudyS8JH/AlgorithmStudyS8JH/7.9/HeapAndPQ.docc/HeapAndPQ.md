# Heap And Priority Queue

7.9 알고리즘 과제에 선행하여 알아본 Heap과 PQ

## Overview

### Heap
Heap은 완전 이진트리이다.
부모노드가 자식노드보다 크거나 작다는 특성을 가지고 있기 때문에,
최댓값 또는 최소값을 효율적으로 찾고 제거할 수 있다.

```
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

```

### Priority Queue
Priority Queue는 우선순위가 높은 요소가 먼저 처리되는 자료구조이다.
대부분 내부적으로 힙을 사용하여 구현된다.

## Heap & Priority Queue
|특성|Heap|Priority Queue|
|------|---|---|
|정의|완전 이진 트리|우선순위 기반 큐|
|구현 방식|배열로 구현|힙을 사용하여 구현|
|주요 연산|삽입, 삭제, 최대/최소 값|삽입, 삭제, 최고 우선순위 값|
|사용 예시|힙 정렬, 우선순위 큐 구현|작업 스케줄링, 다익스트라 알고리즘|
|복잡도|삽입 O(logn), 삭제 O(logn)|삽입 O(logn), 삭제 O(logn)|
