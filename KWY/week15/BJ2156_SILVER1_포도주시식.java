package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ2156_SILVER1_포도주시식 {

    class Main {
        public static void main(String[] args) throws IOException {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int n = Integer.parseInt(br.readLine());
            int[] nums = new int[n];
            for (int i = 0; i < n; i++) {
                nums[i] = Integer.parseInt(br.readLine());
            }
            int[] dp = new int[n + 1];
            dp[1] = nums[0];
            if(n > 1) {
                dp[2] = nums[0] + nums[1];
            }
            for (int i = 3; i <= n; i++) {
                dp[i] = Math.max(dp[i - 1], Math.max(dp[i - 2], dp[i - 3] + nums[i - 2]) + nums[i - 1]);
            }

            System.out.println(dp[n]);
        }

        /*
         * 2% 정답
         *
         * 현재 인덱스의 순서가 1번째일 때, 2번째 일 때, 3번 째 일 때를 배열에 저장해 두고,
         * 마지막에 max 값을 찾는 방식
         *
         * 순서 6  10  13  9   8   1
         *   1 6  10  19  25  31  29
         *   2 0  16  23  28  33  32
         *   3 0  6   16  23  28  33
         *
         * */
        private static void solve1(int n, int[] nums) {
            if (n == 1) {
                System.out.println(nums[0]);
            } else {
                int[][] dp = new int[n + 1][3];
                dp[1][0] = nums[0];
                dp[2][0] = nums[1];
                dp[2][1] = dp[1][0] + nums[1];
                dp[2][2] = dp[1][0];

                for (int i = 3; i <= n; i++) {
                    for (int j = 0; j < 2; j++) {
                        dp[i][j] = dp[i - 1][(j + 2) % 3] + nums[i - 1];
                    }
                    dp[i][2] = Math.max(dp[i - 1][1], dp[i - 1][2]);
                }

                int answer = Math.max(dp[n][0], dp[n][1]);
                answer = Math.max(answer, dp[n][2]);
                System.out.println(answer);
            }
        }
    }
}
