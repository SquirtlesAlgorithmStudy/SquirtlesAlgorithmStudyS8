#include <vector>
#include <string>
#include <algorithm>

std::vector<int> solution(std::string& S, std::vector<int>& P, std::vector<int>& Q) {
	int N = S.length();
	std::vector<std::vector<int>> prefixSum(4, std::vector<int>(N + 1, 0));

	// Calculate prefix sums for A, C, G, T
	for (int i = 0; i < N; i++) {
		prefixSum[0][i + 1] = prefixSum[0][i] + (S[i] == 'A');
		prefixSum[1][i + 1] = prefixSum[1][i] + (S[i] == 'C');
		prefixSum[2][i + 1] = prefixSum[2][i] + (S[i] == 'G');
		prefixSum[3][i + 1] = prefixSum[3][i] + (S[i] == 'T');
	}

	std::vector<int> result;
	for (size_t i = 0; i < P.size(); i++) {
		int start = P[i], end = Q[i] + 1;
		if (prefixSum[0][end] - prefixSum[0][start] > 0) {
			result.push_back(1);  // A found
		}
		else if (prefixSum[1][end] - prefixSum[1][start] > 0) {
			result.push_back(2);  // C found
		}
		else if (prefixSum[2][end] - prefixSum[2][start] > 0) {
			result.push_back(3);  // G found
		}
		else {
			result.push_back(4);  // Only T remains
		}
	}

	return result;
}