#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int number_case;

int width;
int height;

queue<pair<int, int>> fire;

char map[1000][1000];
bool visited[1000][1000];

int dr[4] = { -1, 1, 0 , 0 };
int dc[4] = { 0, 0, 1, -1 };

string bfs(pair<int, int> start, queue<pair<int, int>> fire, bool visited[1000][1000]) {
	queue<pair<pair<int, int>, int>> q;
	visited[start.first][start.second] = true;
	q.push({ start, 0 });


	while (!q.empty()) {

		int fire_size = fire.size();
		for (int i = 0; i < fire_size; ++i) {
			int fire_r = fire.front().first;
			int fire_c = fire.front().second;

			fire.pop();

			for (int j = 0; j < 4; ++j) {
				int next_fire_r = fire_r + dr[j];
				int next_fire_c = fire_c + dc[j];

				if (next_fire_r < 0 || next_fire_r == height || next_fire_c < 0 || next_fire_c == width) {
					continue;
				}

				if (map[next_fire_r][next_fire_c] == '.') {
					map[next_fire_r][next_fire_c] = '*';
					fire.push({ next_fire_r, next_fire_c });
				}
			}
		}
		
        int q_size = q.size();
        for (int i = 0; i < q_size; ++i) {
            int r = q.front().first.first;
		    int c = q.front().first.second;
		    int dep = q.front().second;
		    q.pop();
        
            for (int i = 0; i < 4; ++i) {
                int next_r = r + dr[i];
                int next_c = c + dc[i];

                if (next_r < 0 || next_r == height || next_c < 0 || next_c == width) {
                    return to_string(dep + 1);
                }

                if (map[next_r][next_c] == '*' || map[next_r][next_c] == '#' || visited[next_r][next_c]) {
                    continue;
                }

                visited[next_r][next_c] = true;
                q.push({ {next_r, next_c}, dep + 1 });
            }
	    }
    }

	return "IMPOSSIBLE";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> number_case;

	pair<int, int> start;
	for (int i = 0; i < number_case; ++i) {
		cin >> width >> height;

		for (int j = 0; j < height; ++j) {
			for (int k = 0; k < width; ++k) {
				cin >> map[j][k];

				if (map[j][k] == '@') {
					start = { j, k };
					map[j][k] = '.';
				}
				else if (map[j][k] == '*') {
					fire.push({ j, k });
				}
			}
		}

		cout << bfs(start, fire, visited) << '\n';
	}

	return 0;
}