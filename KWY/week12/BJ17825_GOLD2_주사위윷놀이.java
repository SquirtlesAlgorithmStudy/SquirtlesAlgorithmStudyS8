package simulation;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ17825_GOLD2_주사위윷놀이 {
    /*
     * 말이 이동을 마치는 칸에 다른 말이 있으면 그 말은 고를 수 없다. 단, 이동을 마치는 칸이 도착 칸이면 고를 수 있다.
     * -> 이동하려는 칸에 다른 말이 있으면 해당 칸으로 이동할 수 없다.
     *
     * 주사위 : 10번, 말 4개 -> 모든 경우의 수 4^10 -> 완탐
     * */
    private static Place[] map;
    private static int[] nums;
    private static int answer = -1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        createMap();

        StringTokenizer st = new StringTokenizer(br.readLine());
        nums = new int[10];
        for (int i = 0; i < 10; i++) {
            nums[i] = Integer.parseInt(st.nextToken());
        }
        dfs(0, new int[]{0, 0, 0, 0}, new int[]{0, 0, 0, 0});
        System.out.println(answer);
    }

    private static void dfs(int idx, int[] place, int[] scores) {
        if (idx == 10) {
            int temp = 0;
            for (int score : scores) {
                temp += score;
            }
            answer = Math.max(answer, temp);
            return;
        }

        for (int i = 0; i < 4; i++) {
            if (place[i] == 32) {
                continue;
            }

            int nextPlace = map[place[i]].next[nums[idx] - 1];
            if (isPlace(place, nextPlace)) {
                continue;
            }

            int tempPlace = place[i];
            place[i] = nextPlace;

            int tempScore = scores[i];
            scores[i] += map[place[i]].score;
            dfs(idx + 1, place, scores);

            place[i] = tempPlace;
            scores[i] = tempScore;
        }
    }

    private static boolean isPlace(int[] place, int nextPlace) {
        for (int p : place) {
            if (p == 32) {
                continue;
            }
            if (p == nextPlace) {
                return true;
            }
        }
        return false;
    }

    private static void createMap() {
        map = new Place[33];
        map[0] = new Place(0, 1, 2, 3, 4, 5);
        for (int i = 1; i <= 20; i++) {
            map[i] = new Place(i * 2, i + 1, i + 2, i + 3, i + 4, i + 5);
        }
        map[16] = new Place(32, 17, 18, 19, 20, 32);
        map[17] = new Place(34, 18, 19, 20, 32, 32);
        map[18] = new Place(36, 19, 20, 32, 32, 32);
        map[19] = new Place(38, 20, 32, 32, 32, 32);

        map[5] = new Place(10, 21, 22, 23, 24, 30);
        map[10] = new Place(20, 25, 26, 24, 30, 31);
        map[15] = new Place(30, 27, 28, 29, 24, 30);
        map[20] = new Place(40, 32, 32, 32, 32, 32);

        map[21] = new Place(13, 22, 23, 24, 30, 31);
        map[22] = new Place(16, 23, 24, 30, 31, 20);
        map[23] = new Place(19, 24, 30, 31, 20, 32);
        map[24] = new Place(25, 30, 31, 20, 32, 32);

        map[25] = new Place(22, 26, 24, 30, 31, 20);
        map[26] = new Place(24, 24, 30, 31, 20, 32);

        map[27] = new Place(28, 28, 29, 24, 30, 31);
        map[28] = new Place(27, 29, 24, 30, 31, 20);
        map[29] = new Place(26, 24, 30, 31, 20, 32);

        map[30] = new Place(30, 31, 20, 32, 32, 32);
        map[31] = new Place(35, 20, 32, 32, 32, 32);
        map[32] = new Place(0, 32, 32, 32, 32, 32);
    }
}

class Place {
    int score;
    int[] next;

    public Place(int score, int num1, int num2, int num3, int num4, int num5) {
        this.score = score;
        this.next = new int[]{num1, num2, num3, num4, num5};
    }
}
