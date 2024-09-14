import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int[][] moves = new int[][]{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int c = 1;
        while (true) {
            int n = Integer.parseInt(br.readLine());
            if (n == 0) {
                break;
            }

            int[][] maps = new int[n][n];
            int[][] max = new int[n][n];
            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                for (int j = 0; j < n; j++) {
                    maps[i][j] = Integer.parseInt(st.nextToken());
                    max[i][j] = Integer.MAX_VALUE;
                }
            }

            PriorityQueue<Site> que = new PriorityQueue<>((s1, s2) -> {
                return s1.w - s2.w;
            });
            que.add(new Site(0, 0, maps[0][0]));
            boolean[][] visited = new boolean[n][n];
            while (!que.isEmpty()) {
                Site site = que.poll();

                for (int[] move : moves) {
                    int row = site.r + move[0];
                    int col = site.c + move[1];
                    if (row < 0 || row >= n || col < 0 || col >= n || visited[row][col]) {
                        continue;
                    }
                    int currWeight = site.w + maps[row][col];
                    if (max[row][col] > currWeight) {
                        max[row][col] = currWeight;
                        visited[row][col] = true;
                        que.add(new Site(row, col, currWeight));
                    }
                }
            }

            sb.append("Problem ").append(c++).append(": ").append(max[n - 1][n - 1]).append("\n");
        }
        System.out.println(sb);
    }

    static class Site {
        int r;
        int c;
        int w;

        public Site(int r, int c, int w) {
            this.r = r;
            this.c = c;
            this.w = w;
        }
    }
}
