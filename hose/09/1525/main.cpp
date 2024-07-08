#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

// path, 

set<pair<string, int>> visited;
int bfs(const string& start, int zero) {
    

    set<pair<string, int>> visited;
    queue<pair<pair<string, int>, int>> que;
    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};

    const string ans = "123456780";

    que.push({{start, zero}, 0});
    visited.insert({start, zero});

    while(!que.empty()) {
        string cur = que.front().first.first;
        
        int z = que.front().first.second;
        int dep = que.front().second;
        que.pop();

        if(cur == ans) {
            return dep;
        }

        int r = z / 3;
        int c = z % 3;

        for(int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr < 0 || nr > 2 || nc < 0 || nc > 2) 
                continue;

            int nz = nr * 3 + nc;
            string next = cur;
            swap(next[z], next[nz]);

            if(visited.find({next, nz}) != visited.end()){
                continue;
            }


             que.push( {{next, nz}, dep + 1});
             visited.insert({next, nz});
        }
    }

    return -1;
}



int main() {
    // 문제는 bfs -> 완전탐색
    vector<string> board;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            string temp;
            cin >> temp;
            board.push_back(temp);
        }
    }

    string initial_state;
    int zero_idx;
    for (int i = 0; i < 9; i++) {
        if (board[i] == "0") {
            zero_idx = i;
        }
        initial_state += board[i];
    }

    cout << bfs(initial_state, zero_idx) << endl;


    return 0;
}