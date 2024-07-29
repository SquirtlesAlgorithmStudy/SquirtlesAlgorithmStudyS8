#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> deadline_list(N + 1);

    for (int i = 0; i < N; i++) {
        int deadline, score;
        cin >> deadline >> score;
        deadline_list[deadline].push_back(score);
    }

    priority_queue<int> pq;
    long long ans = 0;

    for (int deadline = N; deadline > 0; deadline--) {
        for (int score : deadline_list[deadline]) {
            pq.push(score);
        }
        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans << "\n";

    return 0;
}