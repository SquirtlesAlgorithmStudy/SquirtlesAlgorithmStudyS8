package binary_search;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BJ2110_GOLD4_공유기설치 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(br.readLine());
        }
        Arrays.sort(nums);

        int start = 1;
        int end = nums[n - 1] - nums[0];
        while (start <= end) {
            int mid = (start + end) / 2;
            int cnt = 1;
            int temp = nums[0];
            for (int i = 1; i < n; i++) {
                if (nums[i] - temp >= mid) {
                    temp = nums[i];
                    cnt++;
                }
            }
            if (cnt >= m) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        System.out.println(end);
    }
}
