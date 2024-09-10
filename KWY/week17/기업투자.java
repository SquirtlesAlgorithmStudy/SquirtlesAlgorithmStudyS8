package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ2662_GOLD2_기업투자 {
    /*
     * 주의: '여기서 투자가는 한 기업에 돈을 나누어 투자할 수 없다'
     *
     * */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[][] nums = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            st.nextToken();
            for (int j = 1; j <= m; j++) {
                nums[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int[][] dp = new int[n + 1][m + 1];
        // dp 별 history를 저장한다. 4개의 기업이 있을 때, 각각의 기업이 얼마씩 투자했는지 나타낸다.
        // A:1, B:0, C:3, D:0 => [1,0,3,0]
        int[][][] history = new int[n + 1][m + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int temp = -1;
                for (int k = 0; k <= i; k++) {
                    int curr = dp[k][j - 1] + nums[i - k][j];
                    if (temp < curr) {
                        temp = curr;

                        // 해당 dp의 history를 copy 한다.
                        for (int t = 1; t <= m; t++) {
                            history[i][j][t] = history[k][j - 1][t];
                        }
                        // i-k = 현재 투자한 값
                        history[i][j][j] = i - k;
                    }
                }
                dp[i][j] = temp;
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(dp[n][m]).append("\n");
        for (int i = 1; i <= m; i++) {
            sb.append(history[n][m][i]).append(" ");
        }
        System.out.println(sb);
    }
}
