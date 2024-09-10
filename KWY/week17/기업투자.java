import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
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
        int[][][] arr = new int[n + 1][m + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                int temp = -1;
                for (int k = 0; k <= i; k++) {
                    int curr = dp[k][j - 1] + nums[i - k][j];
                    if (temp < curr) {
                        temp = curr;
                    }
                }
                dp[i][j] = temp;
            }
        }
        System.out.println(dp[n][m]);
    }
}