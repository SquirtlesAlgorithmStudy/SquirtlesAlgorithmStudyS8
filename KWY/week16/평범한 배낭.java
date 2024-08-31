import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {
    /*
    * 1: (3,6), 2: (4,8), 3: (5,12), 4: (6,13)
    *
    *
    *     0   1   2   3   4
    *  0  0   0   0   0   0
    *  1  0   0   0   0   0
    *  2  0   0   0   0   0
    *  3  0   6   6   6   6
    *  4  0   6   8   8   8
    *  5  0   6   8   12  12
    *  6  0   6   8   12  13
    *  7  0   6   14  14  14
    *
    *
    * */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int[][] nums = new int[n][2];

        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            nums[i][0] = Integer.parseInt(st.nextToken());
            nums[i][1] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(nums, (n1, n2) -> n1[0] - n2[0]);

        int[][] dp = new int[n + 1][k + 1];
        for(int j = 0 ; j< n ; j++) {
            for(int i = 1 ; i<= k ; i++) {
                if(nums[j][0] > i) {
                    dp[j+1][i] = dp[j][i];
                    continue;
                }
                dp[j+1][i] = Math.max(dp[j][i], nums[j][1] + dp[j][i - nums[j][0]]);
            }
        }

        System.out.println(dp[n][k]);
    }
}