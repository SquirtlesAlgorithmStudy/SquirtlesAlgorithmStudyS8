package greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BJ1052_GOLD5_물병 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        /*
         * n = 13 이면 초기 물병 조합운 8,4,1이다.
         * 이는 13(10진수) = 1101(진수) 와 같기 때문에
         * 아래와 같이 초기 물병 조합을 구한다.
         * */
        int num = n;
        int cnt = 1;
        PriorityQueue<Integer> que = new PriorityQueue<>();
        while (num != 0) {
            if (num % 2 != 0) {
                que.add(cnt);
            }
            num /= 2;
            cnt *= 2;
        }

        /*
         * que size가 k 보다 크면 물병을 조합해야하기 때문에
         * 오름차순으로 되어 있는 que에서 2개를 숫자 2개를 poll한 다음에
         * 두 물병의 크기가 다르면, 두 물병 중 max 값으로 가기 위해 필요한 물병의 개수를 구한다. 필요한 물병의 개수 = (max - min) 1 -> 4 : 3개 필요
         * 이후 두 물병을 합친 값을 추가한다.
         * */
        int answer = 0;
        while (!que.isEmpty() && que.size() > k) {
            int n1 = que.poll();
            int n2 = que.poll();

            if (n1 != n2) {
                int count = Math.abs(n2 - n1);
                answer += count;
            }
            que.add(Math.max(n1, n2) * 2);
        }

        System.out.println(answer);
    }

}
