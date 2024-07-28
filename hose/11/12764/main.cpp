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

    vector<pair<int, pair<string, int>>> events;
    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        events.push_back({start, {"Start", i}});
        events.push_back({end, {"End", i}});
    }

    sort(events.begin(), events.end());

    priority_queue<int, vector<int>, greater<int>> pq_pc;
    vector<int> pc_info_list(N, 0);
    vector<int> person_idx2pc(N, -1);
    int now_pc = 0;

    for (const auto& event : events) {
        int time = event.first;
        string type = event.second.first;
        int idx = event.second.second;

        if (type == "Start") {
            int pc;
            if (!pq_pc.empty()) {
                pc = pq_pc.top();
                pq_pc.pop();
            } else {
                pc = now_pc++;
            }
            pc_info_list[pc]++;
            person_idx2pc[idx] = pc;
        } else {
            int pc = person_idx2pc[idx];
            pq_pc.push(pc);
        }
    }

    cout << now_pc << "\n";
    for (int i = 0; i < now_pc; i++) {
        cout << pc_info_list[i] << " ";
    }
    cout << "\n";

    return 0;
}