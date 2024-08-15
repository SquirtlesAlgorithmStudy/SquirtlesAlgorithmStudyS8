package binary_search;

import java.util.Arrays;

public class Codility_NailingPlanks {
    // 누적합 사용 / https://app.codility.com/demo/results/training6APYXN-H28/
    // 시작점과 끝점의 누적합의 값이 다르면 그 사이에 못이 있다는 뜻이다.
    /*
    * 0 1 2 3 4 5 6 7 8 9 10
    * 0 0 1 0 1 0 1 1 0 0 1
    * 0 0 1 1 2 2 3 4 4 4 5
    *
    * 4~5 : [4]-> 2-1 , [5]->2 / 4~5 사이에 못이 있다.
    * */
    class Solution2 {
        public static int solution(int[] A, int[] B, int[] C) {
            int m = C.length;

            int start = 0;
            int end = m - 1;
            int answer = -1;
            while (start <= end) {
                int mid = (start + end) / 2;

                if (check(A, B, C, mid)) {
                    end = mid - 1;
                    answer = mid + 1;
                } else {
                    start = mid + 1;
                }
            }

            return answer;
        }

        public static boolean check(int[] A, int[] B, int[] C, int mid) {
            // each element of arrays A, B and C is an integer within the range [1..2*M] 조건 때문에 2*m + 1을 하는 것이다.
            int size = 2 * C.length + 1;
            int[] sum = new int[size];
            for (int i = 0; i <= mid; i++) {
                ++sum[C[i]];
            }
            for (int i = 1; i < size; i++) {
                sum[i] += sum[i - 1];
            }

            for (int i = 0; i < A.length; i++) {
                if (sum[B[i]] <= sum[A[i] - 1]) {
                    return false;
                }
            }
            return true;
        }
    }

    class Solution1 {
        // solve 1 result : https://app.codility.com/demo/results/trainingCQE4PM-5TS/
        // 하지만 해당 풀이는 시간초과가 생길 수 있다.
        // [1,30,000], [2,30,000], [3,30,000] 이고, 못 위치가 [1,2,3,4....,30,000] 일 때 시간 초과가 생길 수 있지만 해당 케이스가 없어서 정답인 것이다.
        public static int solution(int[] A, int[] B, int[] C) {
            int n = A.length;
            int m = C.length;

            int[][] c = new int[m][2];
            for (int i = 0; i < m; i++) {
                c[i] = new int[]{C[i], i + 1};
            }
            Arrays.sort(c, (c1, c2) -> c1[0] - c2[0]);

            int answer = -1;
            for (int i = 0; i < n; i++) {
                int nail = check(A[i], B[i], c, answer);
                if (nail == -1) {
                    return -1;
                }
                answer = Math.max(answer, nail);
            }

            return answer;
        }

        public static int check(int start, int end, int[][] c, int prev) {
            int left = 0;
            int right = c.length - 1;

            // 가장 왼쪽에 위치한 못을 구한다.
            int minIdx = -1;
            while (left <= right) {
                int mid = (left + right) / 2;

                if (start > c[mid][0]) {
                    left = mid + 1;
                } else if (end < c[mid][0]) {
                    right = mid - 1;
                } else {
                    right = mid - 1;
                    minIdx = mid;
                }
            }

            if (minIdx == -1) {
                return -1;
            }

            // 가장 왼쪽에 있는 못부터 end 까지 순회하면서 최소 인덱스를 구한다.
            int min = Integer.MAX_VALUE;
            for (int i = minIdx; i < c.length; i++) {
                // 해당 위치가 끝점인지 확인한다.
                if (c[i][0] > end) {
                    break;
                }

                // 이전 정답보다 왼쪽에 있으면 이전 정답 값을 반환한다.
                if (c[i][1] <= prev) {
                    return prev;
                }

                min = Math.min(min, c[i][1]);
            }

            return min;
        }
    }

}
