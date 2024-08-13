// Immigration(Programmers / Binary Search)

// 입국자 1,2,3,4,5,6
// 심사자 A(7분) :1 (7), 3 (14), 5 (21), 6 (28!!!)
// 심사자 B(10분) :2 (10)', 4 (20), 6 (30xxxx)

// 근데 만약 심사가 끝나는 시간이 주어진다면??? 이분탐색으로!!! 최소시간 * 사람수 = 7분 * 6명 = 42분
// 심사자 A(7분) : 15 / 7 = 최대 2명
// 심사자 B(10분) : 15 / 10 = 최대 1명

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> times)
{
    int start = 1;                                          // 1분
    int end = *min_element(times.begin(), times.end()) * n; // 42분
    int answer = end;

    while (start <= end)
    {
        // 이분탐색
        int mid = (start + end) / 2;
        int cnt = 0;

        // 중간값을 기준으로 최대 몇명을 심사?
        cnt = 0;

        // 주어진시간 / 심사관의 심사시간 = 심사가능한 최대 인원
        for (int time : times)
        {
            cnt += mid / time;
        }
        // 심사할수있는 사람수 < 심사해야하는 사람 수 = 시간 더 필요
        if (cnt < n)
        {
            start = mid + 1;
        }
        else
            end = mid - 1;
    }
    return start;
}

int main()
{
    int n = 6;
    vector<int> times = {7, 10};

    cout << solution(n, times) << endl;

    return 0;
}
