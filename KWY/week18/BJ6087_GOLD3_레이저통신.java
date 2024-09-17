package greedy;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class BJ6087_GOLD3_레이저통신 {
    static class Site {
        int r;
        int c;
        int d;
        int m;

        public Site(int r, int c, int d, int m) {
            this.r = r;
            this.c = c;
            this.d = d;
            this.m = m;
        }
    }

    /*
    * 현재 row, col, 방향, 사용한 거울의 수의 정보를 가지고 있는 Site class를 만든다.
    * 1. map을 한번 순회해서 시작점과 끝점을 구한다.
    *   1-1. 시작점에서 뻗을 수 있는 레이저를 pq에 추가한다. (첫 레이저는 거울을 사용하지 않기 때문에 0이다.)
    * 2. pq가 empty가 될 때까지 반복을 한다.
    *   2-1. visited를 통해서 현재의 row, col, 방향으로 온 적이 있는지 확인한다.
    *   2-2. visited를 갱신한다.
    *   2-3. 현재 위치에서 같은 방향은 거울을 추가하지 않고, 90도 방향은 (현재 사용한 거울의 수 + 1)을 한다.
    *        만약 현재 위치에서 180도 방향은 갈 방법이 없기 때문에 건너뛴다. [우,하,좌,상]으로 배치해서 (n+2)%4 == n 이면 continue
    *
    * 주의
    * 1. visited 배열은 꼭 필요하다: 안하면 80%에서 메모리 초과가 생긴다.
    * 2. visited 배열은 방향까지 고려해야 한다: (1,1)에서 사용한 거울의 수가 1인 아래 방향과 오른쪽 방향이 생길 수 있다.
    *    둘 중 어느 것이 최적일지 모르기 때문에 2개 다 순회를 해봐야한다.

해당 예시
4 5
C..*
...*
...*
*.**
...C

    *
    * */
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int w = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());
        String[] map = new String[h];

        for (int i = 0; i < h; i++) {
            map[i] = br.readLine();
        }

        // "R", "D", "L", "U"
        int[][] moves = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int endRow = 0;
        int endCol = 0;
        int[][] nums = new int[h][w];
        PriorityQueue<Site> que = new PriorityQueue<>((s1, s2) -> s1.m - s2.m);
        for (int r = 0; r < h; r++) {
            for (int c = 0; c < w; c++) {
                nums[r][c] = Integer.MAX_VALUE;
            }
        }

        for (int r = 0; r < h; r++) {
            for (int c = 0; c < w; c++) {
                if (map[r].charAt(c) == 'C' && que.isEmpty()) {
                    for (int n = 0; n < 4; n++) {
                        int nr = r + moves[n][0];
                        int nc = c + moves[n][1];
                        if (nr < 0 || nr >= h || nc < 0 || nc >= w || map[nr].charAt(nc) == '*') {
                            continue;
                        }
                        que.add(new Site(nr, nc, n, 0));
                        nums[nr][nc] = 0;
                    }
                }
                if (map[r].charAt(c) == 'C' && !que.isEmpty()) {
                    endRow = r;
                    endCol = c;
                }
            }
        }

        boolean[][][] visited = new boolean[h][w][4];
        while (!que.isEmpty()) {
            Site site = que.poll();
            if (visited[site.r][site.c][site.d]) {
                continue;
            }
            visited[site.r][site.c][site.d] = true;

            for (int n = 0; n < 4; n++) {
                int nr = site.r + moves[n][0];
                int nc = site.c + moves[n][1];
                // 180도 방향은 생길 수 없다.
                if ((site.d + 2) % 4 == n || nr < 0 || nr >= h || nc < 0 || nc >= w || map[nr].charAt(nc) == '*') {
                    continue;
                }

                if (site.d == n && nums[nr][nc] >= site.m) {
                    que.add(new Site(nr, nc, n, site.m));
                    nums[nr][nc] = site.m;
                } else if (nums[nr][nc] >= site.m + 1) {
                    que.add(new Site(nr, nc, n, site.m + 1));
                    nums[nr][nc] = site.m + 1;
                }
            }

        }

        System.out.println(nums[endRow][endCol]);
    }
}
