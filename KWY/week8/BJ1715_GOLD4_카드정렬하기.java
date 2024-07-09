package heap;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class BJ1715_GOLD4_카드정렬하기 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        PriorityQueue<Integer> que = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            que.add(Integer.parseInt(br.readLine()));
        }

        int answer = 0;

        while (!que.isEmpty() && que.size() != 1) {
            int n1 = que.poll();
            int n2 = que.poll();
            int num = n1 + n2;
            answer += num;
            que.add(num);
        }

        System.out.println(answer);
    }
}
