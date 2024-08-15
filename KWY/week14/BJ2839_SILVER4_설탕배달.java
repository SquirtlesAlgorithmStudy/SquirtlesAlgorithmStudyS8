package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ2839_SILVER4_설탕배달 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] nums = new int[n + 1];
        nums[3] = 1;
        if (n >= 5) {
            nums[5] = 1;
            for (int i = 6; i <= n; i++) {
                int n3 = nums[i - 3];
                int n5 = nums[i - 5];
                if (n3 != 0 && n5 != 0) {
                    nums[i] = Math.min(n3, n5) + 1;
                } else if (n3 != 0) {
                    nums[i] = n3 + 1;
                } else if (n5 != 0) {
                    nums[i] = n5 + 1;
                }
            }
        }
        if (nums[n] == 0) {
            System.out.println(-1);
        } else {
            System.out.println(nums[n]);
        }
    }
}
