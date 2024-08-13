//
//  programmers_입국심사.swift
//  AlgorithmStudyS8JH
//
//  Created by 김지현 on 8/13/24.
//

import Foundation

func solution(_ n:Int, _ times:[Int]) -> Int64 { // n = 6, times = [7, 10]
  guard let max = times.max() else { return 0 }

  var start = 1
  var end = max * n // 60

  while start < end {
    var mid = (start + end) / 2 // [1]: 30분, [2]: 15분, [3]: (16+30)/2 = 23, [4]: (24+30)/2 = 27, [5]: (28+30)/2 = 29, [6]: (28+29)/2 = 28
    var acceptableCnt: Int = 0
    times.forEach { time in
      acceptableCnt += mid / time
      // [1] 30분 동안 수용 최대 인원 구하기 -> 7분 걸리는 심사원은 4명을, 10분 걸리는 심사원은 3명 수용 총 7명 (가능)
      // [2] 15분 동안 수용 최대 인원 구하기 -> 7분 걸리는 심사원은 2명을, 10분 걸리는 심사원은 1명 수용 총 3명 (불가능)
      // [3] 23분 동안 수용 최대 인원 구하기 -> 7분 걸리는 심사원은 3명을, 10분 걸리는 심사원은 2명 수용 총 5명 (불가능)
      // [4] 27분 동안 수용 최대 인원 구하기 -> 7분 걸리는 심사원은 3명을, 10분 걸리는 심사원은 2명 수용 총 5명 (불가능)
      // [5] 29분 동안 수용 최대 인원 구하기 -> 7분 걸리는 심사원은 4명을, 10분 걸리는 심사원은 2명 수용 총 6명 (가능) -> 아직 start<end
      // [6] 28분 동안 수용 최대 인원 구하기 -> 7분 걸리는 심사원은 4명을, 10분 걸리는 심사원은 2명 수용 총 6명 (가능)
    }

    if acceptableCnt >= n { // 가능 -> 시간이 남는다는 뜻 -> 앞쪽을 탐색
      end = mid // [6]에서 end=29를 end=28로 변경하면 start=28과 같아지게 되므로 다음 while문 통과안하고 종료
    } else { // 불가능 -> 시간이 부족하다는 뜻 -> 뒷쪽을 탐색
      start = mid + 1
    }
  }

  return Int64(start)
}

print(solution(6, [7,10]))
