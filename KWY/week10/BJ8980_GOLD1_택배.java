package greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BJ8980_GOLD1_택배 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(br.readLine());

        Pack[] packs = new Pack[m];
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken()) - 1;
            int e = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken());

            packs[i] = new Pack(s, e, b);
        }
        Arrays.sort(packs, (p1, p2) -> p1.end - p2.end);

        int answer = 0;
        int[] nums = new int[n];
        for (Pack pack : packs) {
            int temp = pack.box;
            for (int i = pack.start; i < pack.end; i++) {
                if(nums[i] == c) {
                    temp = 0;
                    break;
                }
                if (nums[i] + temp > c) {
                    temp = c - nums[i];
                }
            }
            for (int i = pack.start; i < pack.end; i++) {
                nums[i] += temp;
            }
            answer += temp;
        }

        System.out.println(answer);
    }
}

class Pack {
    int start;
    int end;
    int box;

    public Pack(int start, int end, int box) {
        this.start = start;
        this.end = end;
        this.box = box;
    }
}
