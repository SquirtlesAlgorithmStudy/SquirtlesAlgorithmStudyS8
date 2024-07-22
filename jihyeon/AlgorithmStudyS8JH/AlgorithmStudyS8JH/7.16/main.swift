//
//  main.swift
//  AlgorithmStudyS8JH
//
//  Created by 김지현 on 2024/07/16.
//

import Foundation
// 1781 컵라면

// Heap .... ㅂㄷㅂㄷ
struct Heap<Element: Comparable> {
    private var elements: [Element] = []
    private let sort: (Element, Element) -> Bool

    init(sort: @escaping (Element, Element) -> Bool) {
        self.sort = sort
    }

    init(sort: @escaping (Element, Element) -> Bool, elements: [Element]) {
        self.sort = sort
        self.elements = elements
        buildHeap()
    }

    private mutating func buildHeap() {
        for index in (0..<(elements.count / 2)).reversed() {
            siftDown(from: index)
        }
    }

    var isEmpty: Bool {
        return elements.isEmpty
    }

    var count: Int {
        return elements.count
    }

    func peek() -> Element? {
        return elements.first
    }

    mutating func insert(_ value: Element) {
        elements.append(value)
        siftUp(from: elements.count - 1)
    }

    mutating func remove() -> Element? {
        guard !elements.isEmpty else {
            return nil
        }

        elements.swapAt(0, elements.count - 1)
        let removed = elements.removeLast()
        if !elements.isEmpty {
            siftDown(from: 0)
        }

        return removed
    }

    private mutating func siftUp(from index: Int) {
        var childIndex = index
        let child = elements[childIndex]
        var parentIndex = self.parentIndex(of: childIndex)

        while childIndex > 0 && sort(child, elements[parentIndex]) {
            elements[childIndex] = elements[parentIndex]
            childIndex = parentIndex
            parentIndex = self.parentIndex(of: childIndex)
        }

        elements[childIndex] = child
    }

    private mutating func siftDown(from index: Int) {
        var parentIndex = index
        while true {
            let leftChildIndex = self.leftChildIndex(of: parentIndex)
            let rightChildIndex = leftChildIndex + 1
            var optionalParent = parentIndex

            if leftChildIndex < elements.count && sort(elements[leftChildIndex], elements[optionalParent]) {
                optionalParent = leftChildIndex
            }
            if rightChildIndex < elements.count && sort(elements[rightChildIndex], elements[optionalParent]) {
                optionalParent = rightChildIndex
            }
            if optionalParent == parentIndex {
                return
            }
            elements.swapAt(parentIndex, optionalParent)
            parentIndex = optionalParent
        }
    }

    private func parentIndex(of index: Int) -> Int {
        return (index - 1) / 2
    }

    private func leftChildIndex(of index: Int) -> Int {
        return 2 * index + 1
    }
}

let hwNum = Int(readLine()!)!
var tuple: [(deadline: Int, rmNum: Int)] = []
for _ in 0..<hwNum {
    let input = readLine()!.components(separatedBy: " ").map { Int($0)! }
    tuple.append((input[0], input[1]))
}
