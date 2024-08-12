package sliding_window;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ15961_GOLD4_회전초밥 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int d = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        int[] nums = new int[n];
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(br.readLine());
        }

        int[] cnt = new int[d + 1];
        int temp = 1;
        for (int i = 0; i < k; i++) {
            if (nums[i] == c) {
                continue;
            }
            if (cnt[nums[i]] == 0) {
                temp += 1;
            }
            cnt[nums[i]] += 1;
        }

        int answer = temp;
        int start = 0;
        int end = k - 1;
        for (int i = 0; i < n; i++) {
            if (cnt[nums[start]] - 1 == 0 && nums[start] != c) {
                temp -= 1;
            }
            if(nums[start] != c) {
                cnt[nums[start]] -= 1;
            }

            start = (start + 1) % n;
            end = (end + 1) % n;

            if (cnt[nums[end]] == 0 && nums[end] != c) {
                temp += 1;
            }
            if (nums[end] != c) {
                cnt[nums[end]] += 1;
            }

            answer = Math.max(answer, temp);
        }

        System.out.println(answer);
    }
}
