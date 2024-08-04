#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 처음에 조합으로 풀었으나 시간초과로 실패
// 집 위치로 이분탐색 하는 것이 아닌 거리로

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;

	cin >> n >> k;


	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	// 최소거리
	int min_di = 1;
	// 최대거리
	int max_di = v[n - 1] - v[0];

	while (min_di <= max_di) {
		int mid_di = (min_di + max_di) / 2;

		int count = 1;
		int start = v[0];

		for (int i = 1; i < n; i++) {
			if (v[i] - start >= mid_di) {
				count++;
				start = v[i];
			}
		}

		if (count >= k) {
			min_di = mid_di + 1;
		}
		else {
			max_di = mid_di - 1;
		}

	 }

	cout << max_di << '\n';

	return 0;
}