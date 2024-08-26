package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ1149_SILVER1_RGB거리 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] nums = new int[n][3];

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int r = Integer.parseInt(st.nextToken());
            int g = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            nums[i] = new int[]{r, g, b};
        }

        int[][] dp = new int[n][3];
        dp[0] = new int[]{nums[0][0], nums[0][1], nums[0][2]};
        for (int i = 1; i < n; i++) {
            dp[i][0] = Math.min(dp[i - 1][1], dp[i - 1][2]) + nums[i][0];
            dp[i][1] = Math.min(dp[i - 1][0], dp[i - 1][2]) + nums[i][1];
            dp[i][2] = Math.min(dp[i - 1][0], dp[i - 1][1]) + nums[i][2];
        }
        int answer = Math.min(dp[n - 1][0], dp[n - 1][1]);
        answer = Math.min(answer, dp[n - 1][2]);
        System.out.println(answer);
    }
}
