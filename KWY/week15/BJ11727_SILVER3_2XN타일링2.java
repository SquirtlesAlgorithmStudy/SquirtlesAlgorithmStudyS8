package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ11727_SILVER3_2XN타일링2 {
    /*
    * 1: 1
    * 2: 3
    * 3: 5
    * 4: 11
    * 5: 21
    * 6: ?
    * 7: ?
    * 8: 171
    *
    * 2 - 1 : 2
    * 3 - 2 : 2
    * 4 - 3 : 6
    * 5 - 4 : 10
    *
    * n-2 번째 수에서 * 2를 더하면 되는 규칙을 파악
    *
    * 6 -> 2*(11) + 21 = 43
    * 7 -> 2*(21) + 43 = 85
    * 8 -> 2*(43) + 85 = 171
    *
    * 예시로 나와 있는 8까지 해당 규칙이 잘 적용되는 것을 확인 후 점화식 적용
    *
    * */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        int[] dp = new int[n + 1];
        dp[1] = 1;
        if (n > 1) {
            dp[2] = 3;
            for (int i = 3; i <= n; i++) {
                dp[i] = (2 * dp[i - 2] % 10_007 + dp[i - 1] % 10_007) % 10_007;
            }
        }
        System.out.println(dp[n]);
    }
}
