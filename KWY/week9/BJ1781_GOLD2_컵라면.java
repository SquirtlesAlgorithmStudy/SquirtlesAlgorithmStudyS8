package greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BJ1781_GOLD2_컵라면 {
    /*
     * n <= 200,000 -> NLogN
     * answer <= 2^31 -> int 가능
     *
     * */
    public static void main(String[] args) throws IOException {
        solve2();
    }

    /*
     * 반례 해결) 뒤에 것이 더 클 때,
     * 4
     * 1 1
     * 2 1
     * 3 10
     * 3 10
     *
     * 마감일, 마감일이 같으면 라면 개수 순으로 poll()을 하는 우선 순위 큐를 만들고 문제 정보를 우선 순위 큐에 넣는다.
     * 라면 개수가 적은 순으로 출력하는 우선 순위 큐를 만들고, 푼 문제를 해당 큐에 넣는다.
     * 우선 순위 큐가 빌 때까지 poll()을 하면서 아래와 같이 조건 식을 이어나간 뒤 답을 출력한다.
     *   1. 현재 문제의 마감 기한이 지나지 않았다면 answer += 라면개수
     *   2. 기한이 지났고, (answer) - (풀었던 문제 중 가장 라면 개수가 작은 문제) + (현재 문제) > answer 이라면 문제를 교체한다.
     * */
    private static void solve2() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        PriorityQueue<Problem> que = new PriorityQueue<>((o1, o2) -> {
            if (o1.deadLine == o2.deadLine) {
                return o2.count - o1.count;
            }
            return o1.deadLine - o2.deadLine;
        });
        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int deadLine = Integer.parseInt(st.nextToken());
            int count = Integer.parseInt(st.nextToken());
            que.add(new Problem(i, deadLine, count));
        }

        PriorityQueue<Problem> solved = new PriorityQueue<>((o1, o2) -> {
            return o1.count - o2.count;
        });
        int day = 1;
        int answer = 0;
        while (!que.isEmpty()) {
            Problem p = que.poll();
            if (p.deadLine >= day) {
                answer += p.count;
                day++;
                solved.add(p);
            } else if (!solved.isEmpty() && answer - solved.peek().count + p.count > answer) {
                answer = answer - solved.peek().count + p.count;
                solved.poll();
                solved.add(p);
            }
        }
        System.out.println(answer);
    }


    /*
     * 4% 정답
     * 마감일, 마감일이 같으면 라면 개수 순으로 poll()을 하는 우선 순위 큐를 만들고 문제 정보를 우선 순위 큐에 넣는다.
     *
     * 우선 순위 큐가 빌 때까지 poll()을 하면서 아래와 같이 조건 식을 이어나간 뒤 답을 출력했다.
     *   1. 현재 문제의 마감 기한이 지났으면 continue
     *   2. 지나지 않았으면 answer += 라면개수
     * */
    private static void solve1() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        PriorityQueue<Problem> que = new PriorityQueue<>((o1, o2) -> {
            if (o1.deadLine == o2.deadLine) {
                return o2.count - o1.count;
            }
            return o1.deadLine - o2.deadLine;
        });
        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int deadLine = Integer.parseInt(st.nextToken());
            int count = Integer.parseInt(st.nextToken());
            que.add(new Problem(i, deadLine, count));
        }

        int day = 1;
        int answer = 0;
        while (!que.isEmpty()) {
            Problem p = que.poll();
            if (p.deadLine < day) {
                continue;
            }
            answer += p.count;
            day++;
        }
        System.out.println(answer);
    }
}

class Problem {
    int idx;
    int deadLine;
    int count;

    public Problem(int idx, int deadLine, int count) {
        this.idx = idx;
        this.deadLine = deadLine;
        this.count = count;
    }
}
