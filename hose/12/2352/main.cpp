#include <iostream>
#include <vector>
using namespace std;

// 오름차순이 아니면 선 끊김
// 가장 긴 수열 찾기 -> lis
// lowerbound라는 멋진 함수 이용하기

int arr[40001];

int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> arr_index;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> v;
    v.push_back(arr[0]);

    for (int i = 1; i < n; ++i) {
        if (v.back() < arr[i]) {
            v.push_back(arr[i]);

        } else {
            auto it = lower_bound(v.begin(), v.end(), arr[i]);
            v[it - v.begin()] = arr[i];
        }
    }

    cout << v.size() << '\n';

    for (int i = 0; i < n; i++) {
        cout << arr_index[i] << ' ';
    }

    return 0;
}

// lower bound: 찾고자 하는 값 이상이 처음 나오는 위치.
// 4 2 6 3 1 5
// 2, 3, 5

// LIS: 4 // index[0] = 1
// LIS: 2 // index[1] = 1
// 2 6: //  index[2] = 2
// 2 3 //  index[3] = 2
// 1 3 // index[4] = 1
// 1 3 5 index[5] = 3



// index[5], index[3], index[1]
// 5 3 2 뒤집어. 
