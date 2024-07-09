import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

class Main {
    static int[][] moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int c = Integer.parseInt(st.nextToken());
            int r = Integer.parseInt(st.nextToken());
            String[] maps = new String[r];
            for (int row = 0; row < r; row++) {
                maps[row] = br.readLine();
            }

            // 초반 출발점을 찾고, 초기 화재가 난 곳과 벽은 이동할 수 없으니 visited를 true로 만든다.
            boolean[][] visited = new boolean[r][c];
            ArrayDeque<Site> moveQue = new ArrayDeque<>();
            ArrayDeque<Site> fireQue = new ArrayDeque<>();
            for (int row = 0; row < maps.length; row++) {
                for (int col = 0; col < maps[row].length(); col++) {
                    if (maps[row].charAt(col) == '*') {
                        fireQue.add(new Site(row, col));
                        visited[row][col] = true;
                    } else if (maps[row].charAt(col) == '@') {
                        moveQue.add(new Site(row, col));
                        visited[row][col] = true;
                    } else if (maps[row].charAt(col) == '#') {
                        visited[row][col] = true;
                    }
                }
            }

            boolean isAns = false;
            int answer = 0;
            while (!moveQue.isEmpty()) {
                // 불을 전파한다.
                int size = fireQue.size();
                for (int j = 0; j < size; j++) {
                    Site fSite = fireQue.pollFirst();
                    for (int[] move : moves) {
                        int row = fSite.r + move[0];
                        int col = fSite.c + move[1];
                        if (row < 0 || row >= r || col < 0 || col >= c || visited[row][col]) {
                            continue;
                        }
                        fireQue.addLast(new Site(row, col));
                        visited[row][col] = true;
                    }
                }

                int size2 = moveQue.size();
                answer++;
                // 이동 경로를 추가한다.
                for (int j = 0; j < size2; j++) {
                    Site site = moveQue.poll();
                    for (int[] move : moves) {
                        int row = site.r + move[0];
                        int col = site.c + move[1];

                        if (row < 0 || row >= r || col < 0 || col >= c) {
                            isAns = true;
                            break;
                        }
                        if (visited[row][col]) {
                            continue;
                        }
                        moveQue.add(new Site(row, col));
                        visited[row][col] = true;
                    }
                }

                if (isAns) {
                    sb.append(answer).append("\n");
                    break;
                }
            }

            if (!isAns) {
                sb.append("IMPOSSIBLE").append("\n");
            }
        }

        System.out.println(sb);
    }
}

class Site {
    int r;
    int c;

    public Site(int r, int c) {
        this.r = r;
        this.c = c;
    }
}
