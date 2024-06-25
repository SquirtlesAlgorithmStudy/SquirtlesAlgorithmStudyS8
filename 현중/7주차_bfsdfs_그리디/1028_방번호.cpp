//방 번호

// 0~2 21원으로 1의가격 = 7 / 2의가격 = 8 

#include <iostream>

using namespace std;

int N, M;          // N-1 : 까지 숫자, M : 금액
int cost[10];
int ans[51];

void solve() {
	int h_min = 1, r_min = 0, idx = 1;
	for (int i = 0; i < N; i++) {
		if (cost[i] <= cost[r_min])
			r_min = i;
	}
    
	if (r_min == 0) {
		for (int i = 1; i < N; i++) {
			if (cost[i] <= cost[h_min])
				h_min = i;
		}
	}
	else h_min = r_min;

	if (M < cost[h_min] || N == 1) {
		cout << "0";
		return;
	}
	ans[0] = h_min;
	M -= cost[h_min];
	while (1) {
		if (M - cost[r_min] < 0)
			break;
		M -= cost[r_min];
		ans[idx++] = r_min;
	}
	for (int i = N - 1; i > h_min; i--) {
		if (M - (cost[i] - cost[h_min]) >= 0) {
			ans[0] = i;
			M -= (cost[i] - cost[h_min]);
			break;
		}
	}
	int p = 1, reduce = cost[r_min];
	for (int i = 0; i < N; i++) {
		cost[i] = cost[i] - reduce;
	}
	while (1) {
		int tmp = ans[p];
		for (int i = N - 1; i >= 0; i--) {
			if (M - cost[i] >= 0) {
				ans[p] = i;
				M -= cost[i];
				break;
			}
		}
		if (tmp == ans[p]) break;
		p++;
	}


	for (int i = 0; i < idx; i++) {
		cout << ans[i];
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
	}
	cin >> M;
	solve();
}