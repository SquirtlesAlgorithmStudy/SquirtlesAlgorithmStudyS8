#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 하나의 널빤지를 고정하는데 필요한 최소 인덱스의 못 찾기
int minNails(int plankStart, int plankEnd, const std::vector<std::pair<int, int>>& sortedC, int prev) 
{
        int start = 0, end = sortedC.size() - 1, mid = 0;
        int minIdx = -1; // 조건 만족하기 시작하는 nail idx


        // 널빤지의 시작점 이상이면서 가장 왼쪽에 있는 못 찾기 -> Lowerbound로 찾을 수 있을까?
        while (start <= end) {
            mid = (start + end) / 2;
            if (sortedC[mid].first < plankStart) {
                start = mid + 1;
            } else if (sortedC[mid].first > plankEnd) {
                end = mid - 1;
            } else {
                minIdx = mid;
                end = mid - 1;
            }
        }

        // 조건 만족하는 nail이 없다
        if (minIdx == -1) {
            return -1;
        }

        // 최소 인덱스의 못 찾기
        // 정렬전 C배열에서의 인덱스
        int minOrgIdx = sortedC[minIdx].second;
        for (int i = minIdx; i < sortedC.size(); i++) {
            // 널빤지의 끝점을 넘어섰음 루프 탈출
            if (sortedC[i].first > plankEnd) 
                break;
            minOrgIdx = std::min(sortedC[i].second, minOrgIdx);
            if (minOrgIdx <= prev) {
                return prev;
            }
        }

        return minOrgIdx;
    }

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
    int N = A.size();
    int M = C.size();
    std::vector<std::pair<int, int>> sortedC(M);

    for (int i = 0; i < M; i++) {
        sortedC[i] = {C[i], i};
    }

    std::sort(sortedC.begin(), sortedC.end());

        // 한 널빤지의 못 사용 최소 개수 구하기
    int result = 0, numberOfNails = 0;
    for (int i = 0; i < N; i++) 
    {
        numberOfNails = minNails(A[i], B[i], sortedC, result);
        if (numberOfNails == -1) 
            return -1;

        // 모든 못을 커버하는 최대 구하기
        result = std::max(result, numberOfNails);
    }

    return result + 1;

}