# Parametric Search Algorithm
파라메트릭 서치 알고리즘

## OverView
파라메트릭 서치는 최적화 문제를 해결하는 알고리즘 중 하나로, 이분탐색을 활용하여 문제의 파라미터 값을 결정한다.
주로 "주어진 조건을 만족하는 최대값" 또는 "최소값"을 찾는 문제에서 사용된다.

## 예제
문제: 주어진 나무 높이 배열에서 총 M만큼의 나무를 가져가기 위해 절단기의 최소 높이를 찾아라
(이 문제를 결정 문제로 변환하면, 특정 높이로 모든 나무를 잘라냈을 때, 총 M만큼의 나무를 얻을 수 있는지 여부를 판단하면 된다)

```
func canCutTrees(trees: [Int], height: Int, target: Int) -> Bool {
    var totalWood = 0
    for tree in trees {
        if tree > height {
            totalWood += tree - height
        }
    }
    return totalWood >= target
}

func findMaxSawHeight(trees: [Int], target: Int) -> Int {
    var left = 0
    var right = trees.max() ?? 0
    var result = 0
    
    while left <= right {
        let mid = left + (right - left) / 2
        if canCutTrees(trees: trees, height: mid, target: target) {
            result = mid
            left = mid + 1
        } else {
            right = mid - 1
        }
    }
    
    return result
}

// 예제 배열
let trees = [20, 15, 10, 17]
let target = 7
let maxHeight = findMaxSawHeight(trees: trees, target: target)
print("최적의 절단기 높이는 \(maxHeight)입니다.")
// maxHeight은 15가 나온다 15짜리 절단기로 나무를 자르면 [5, 0, 0, 2]가 되므로 총 target=7의 나무를 얻을 수 있다
```


