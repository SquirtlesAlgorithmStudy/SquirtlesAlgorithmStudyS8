package union_find;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class BJ20955_GOLD4_민서의응급수술 {

   /*
   반례

6 10
3 4
1 3
1 5
3 5
1 6
3 6
2 5
1 2
5 6
2 3
    */

    /*
     *  1  2  3  4  5  6
     *  1  1  1  3  1  1
     *
     * 위와 같이 4의 집합도 결국 1인데, 경로 압축을 하지 않아서 2개의 집합으로 결과가 나온다.
     * 따라서 마지막에 set.add를 할 때, parent[i]가 아닌 find(i)를 통해서 해당 parent 배열을 갱신하면서
     * 자신의 집합을 add 한다.
     *
     * */
    static int[] parent;
    static int delete = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        parent = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            union(u, v);
        }
        Set<Integer> set = new HashSet<>();
        for (int i = 1; i <= n; i++) {
            set.add(find(i));
        }
        System.out.println(set.size() - 1 + delete);
    }

    private static void union(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px < py) {
            parent[py] = px;
        } else if (px > py) {
            parent[px] = py;
        } else {
            delete++;
        }
    }

    private static int find(int x) {
        if (parent[x] == x) {
            return parent[x];
        }
        return parent[x] = find(parent[x]);
    }
}
