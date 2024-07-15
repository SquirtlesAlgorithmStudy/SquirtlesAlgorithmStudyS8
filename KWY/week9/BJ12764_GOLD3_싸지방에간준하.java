package greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/*
* 종료된 컴퓨터가 연속될 때(1,2,3), 차선의 인덱스(2,3)를 저장하지 않았다.
* pq로 저장하도록 수정

반례)
7
0 20
3 10
5 17
7 13
8 15
14 25
16 30

* * */
public class BJ12764_GOLD3_싸지방에간준하 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // 시간을 입력 받고, 시작 시간 순으로 오름차순한다.
        int n = Integer.parseInt(br.readLine());
        Time[] times = new Time[n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int end = Integer.parseInt(st.nextToken());
            times[i] = new Time(start, end);
        }
        Arrays.sort(times, (c1, c2) -> c1.start - c2.start);

        /*
         * cnt = 최대 컴퓨터 개수를 카운팅
         * uses = 인덱스 별 컴퓨터 사용 횟수를 카운팅
         * computers = 컴퓨터 종료 시간과 컴퓨터 인덱스를 가지고 있는 pq
         * emptyComputers = 사용이 끝난 컴퓨터 인덱스를 가지고 있는 pq
         * */
        int cnt = 0;
        int[] uses = new int[100_001];
        PriorityQueue<Computer> computers = new PriorityQueue<>((c1, c2) -> c1.end - c2.end);
        PriorityQueue<Integer> emptyComputers = new PriorityQueue<>();

        for (Time time : times) {
            // computers pq 내에 컴퓨터가 없다면, (cnt, uses) 갱신
            if (computers.isEmpty()) {
                uses[cnt] += 1;
                computers.add(new Computer(cnt++, time.end));
                continue;
            }
            // 비어있는 자리 중 번호가 가장 작은 자리에 앉아야 하기 때문에 종료된 컴퓨터의 인덱스 갱신
            while (!computers.isEmpty() && computers.peek().end <= time.start) {
                Computer computer = computers.poll();
                emptyComputers.add(computer.idx);
            }
            // 종료된 컴퓨터가 있다면 해당 컴퓨터 자리를 사용, 아니라면 새로운 컴퓨터 설치
            if (!emptyComputers.isEmpty()) {
                int temp = emptyComputers.poll();
                uses[temp] += 1;
                computers.add(new Computer(temp, time.end));
            } else {
                uses[cnt] += 1;
                computers.add(new Computer(cnt++, time.end));
            }
        }

        StringBuilder sb = new StringBuilder();
        sb.append(cnt).append("\n");
        for (int i = 0; i < cnt; i++) {
            sb.append(uses[i]).append(" ");
        }
        System.out.println(sb);
    }
}

class Time {
    int start;
    int end;

    public Time(int start, int end) {
        this.start = start;
        this.end = end;
    }
}

class Computer {
    int idx;
    int end;

    public Computer(int idx, int end) {
        this.idx = idx;
        this.end = end;
    }
}
