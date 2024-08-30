import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
    /*
    *    0  1  2  3  4  5  6
    * 1  1  1  1  1  1  1  1
    * 2  1  2  3  4  5  6  7
    * 3  1  3  6  10 15 21 28
    * 4  1  4  10 20 35 56 64
    *
    * */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        if (k == 1) {
            System.out.println(1);
            return;
        }

        int[][] dp = new int[n + 1][k + 1];

        for (int i = 0; i <= n; i++) {
            dp[i][1] = 1;
        }
        for (int i = 0; i <= k; i++) {
            dp[0][i] = 1;
        }

        for (int i = 2; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                dp[j][i] = (dp[j - 1][i] % 1_000_000_000 + dp[j][i - 1] % 1_000_000_000) % 1_000_000_000;
            }
        }

        System.out.println(dp[n][k]);
    }
}