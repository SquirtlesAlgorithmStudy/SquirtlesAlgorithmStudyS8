package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Queue;
import java.util.StringTokenizer;

public class BJ20303_GOLD3_할로윈의양아치 {
    /*
     * union-find 알고리즘을 통해서 친구들의 집합을 구하고, 해당 집합 별 인원을 카운팅 한다.
     *   1: 2명(1,3) , 2: 4명(2,5,6,10) , 4: 2명(4,9) , 7: 2명(7,8)
     *
     * 각 집합에서 뺏을 수 있는 사탕의 수를 dfs를 통해서 구한다.
     *   1(2명): 13개 , 2(4명): 26개 , 4(2명): 24개, 7(2명): 33개
     *
     * knapsack 풀이 때 사용한 dp 방식으로 최대 사탕의 수를 구한다.
     *
     * 집합\친구 수 : 0  1  2  3  4  5
     *       2:13   0  0 13 13 13 13
     *       4:26   0  0 13 13 26 26
     *       2:24   0  0 24 24 26 26
     *       2:33   0  0 33 33 57 57
     *
     * */
    static int[] parent;
    static List<List<Integer>> graph;
    static int[] candies;
    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        candies = new int[n + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            candies[i] = Integer.parseInt(st.nextToken());
        }

        parent = new int[n + 1];
        graph = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            graph.add(new ArrayList<>());
        }

        // graph를 입력 받음과 동시에 union-find를 통해 친구들의 집합을 구한다.
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            graph.get(a).add(b);
            graph.get(b).add(a);
            union(a, b);
        }

        // 친구 집합 별 인원을 구한다.
        Map<Integer, Integer> count = new HashMap<>();
        for (int i = 1; i <= n; i++) {
            int p = find(i);
            int value = count.getOrDefault(p, 0) + 1;
            count.put(p, value);
        }

        // k 보다 이상인 집합은 건너뛰고, 각 집합 별 뺏을 수 있는 사탕의 수를 구한다.
        List<Steal> steals = new ArrayList<>();
        for (Entry<Integer, Integer> entry : count.entrySet()) {
            if (entry.getValue() >= k) {
                continue;
            }
            steals.add(new Steal(entry.getValue(), getCandies(entry.getKey())));
        }

        // knapsack 방식으로 최대 뺏을 수 있는 사탕의 수를 구한다.
        int[][] dp = new int[steals.size() + 1][k];
        for (int i = 1; i <= steals.size(); i++) {
            Steal steal = steals.get(i - 1);
            for (int j = 1; j < k; j++) {
                if (steal.child > j) {
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }
                dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - steal.child] + steal.candy);
            }
        }

        System.out.println(dp[steals.size()][k - 1]);
    }

    private static int getCandies(int parent) {
        boolean[] visited = new boolean[n + 1];

        int candy = 0;
        Queue<Integer> que = new LinkedList<>();
        que.add(parent);
        visited[parent] = true;
        while (!que.isEmpty()) {
            int friend = que.poll();
            candy += candies[friend];

            for (int next : graph.get(friend)) {
                if (visited[next]) {
                    continue;
                }
                que.add(next);
                visited[next] = true;
            }
        }
        return candy;
    }

    private static void union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px > py) {
            parent[px] = py;
        } else {
            parent[py] = px;
        }
    }

    private static int find(int child) {
        if (child == parent[child]) {
            return child;
        }
        return parent[child] = find(parent[child]);
    }

    static class Steal {
        int child;
        int candy;

        public Steal(int child, int candy) {
            this.child = child;
            this.candy = candy;
        }
    }
}
