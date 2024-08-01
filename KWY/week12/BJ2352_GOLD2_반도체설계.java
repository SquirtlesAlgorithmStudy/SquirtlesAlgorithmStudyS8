package lis;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ2352_GOLD2_반도체설계 {
    public static void main(String[] args) throws IOException {
        solve2();
    }

    /*
     * solve2 LIS 이분탐색 풀이 (NlogN)
     * 시간 : 284ms
     * */
    private static void solve2() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        int[][] nums = new int[n][];
        for (int i = 0; i < n; i++) {
            nums[i] = new int[]{i + 1, Integer.parseInt(st.nextToken())};
        }

        int[] lis = new int[n + 1];
        int len = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i][1] > lis[len]) {
                len += 1;
                lis[len] = nums[i][1];
            } else {
                int idx = binarySearch(0, len, nums[i][1], lis);
                lis[idx] = nums[i][1];
            }
        }
        System.out.println(len);
    }

    private static int binarySearch(int left, int right, int key, int[] lis) {
        while (left < right) {
            int mid = (left + right) / 2;
            if (lis[mid] > key) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

    /* solve1 LIS DP 풀이
     * N^2 시 10^8이라 1초 이상이 걸리는데, 시간 제한이 2초라서 LIS 방식으로 풀었는데 맞았다.
     * 시간 : 4380ms
     * */
    public static void solve1() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        int[][] nums = new int[n][];
        for (int i = 0; i < n; i++) {
            nums[i] = new int[]{i + 1, Integer.parseInt(st.nextToken())};
        }

        int[] dp = new int[n];
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i][1] > nums[j][1]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
        }

        int answer = -1;
        for (int i : dp) {
            answer = Math.max(answer, i);
        }

        System.out.println(answer);
    }
}
