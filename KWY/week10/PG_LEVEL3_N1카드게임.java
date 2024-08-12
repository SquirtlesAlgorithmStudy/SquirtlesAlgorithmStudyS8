package greedy;

import java.util.*;

public class PG_LEVEL3_N1카드게임 {

    class Solution {
        public int solution(int coin, int[] cards) {
            int n = cards.length;
            List<Integer> handCards = new ArrayList<>();
            List<Integer> drawCards = new ArrayList<>();
            for (int i = 0; i < n / 3; i++) {
                handCards.add(cards[i]);
            }

            int idx = n / 3;
            int target = n + 1;
            int answer = 1;
            while (idx < n) {
                // draw card
                for (int i = idx; i < idx + 2; i++) {
                    drawCards.add(cards[i]);
                }
                idx += 2;

                int c1 = -1;
                int c2 = -1;
                int temp = Integer.MAX_VALUE;
                // 손에 있는 카드로만 해결할 수 있는 경우
                for (int i = 0; i < handCards.size(); i++) {
                    for (int j = i + 1; j < handCards.size(); j++) {
                        int sum = handCards.get(i) + handCards.get(j);
                        if (sum == target) {
                            c1 = handCards.get(i);
                            c2 = handCards.get(j);
                        }
                    }
                }
                if (c1 != -1) {
                    handCards.remove(Integer.valueOf(c1));
                    handCards.remove(Integer.valueOf(c2));
                    answer++;
                    continue;
                }

                // 카드 한장을 뽑아야 하는 경우
                if (coin >= 1 && drawCards.size() >= 1) {
                    for (int i = 0; i < handCards.size(); i++) {
                        for (int j = 0; j < drawCards.size(); j++) {
                            int sum = handCards.get(i) + drawCards.get(j);
                            if (sum == target) {
                                c1 = handCards.get(i);
                                c2 = drawCards.get(j);
                            }
                        }
                    }
                    if (c1 != -1) {
                        handCards.remove(Integer.valueOf(c1));
                        drawCards.remove(Integer.valueOf(c2));
                        answer++;
                        coin -= 1;
                        continue;
                    }
                }

                // 카드 두장을 뽑아야 하는 경우
                if (coin >= 2 && drawCards.size() >= 2) {
                    for (int i = 0; i < drawCards.size(); i++) {
                        for (int j = i + 1; j < drawCards.size(); j++) {
                            int sum = drawCards.get(i) + drawCards.get(j);
                            if (sum == target) {
                                c1 = drawCards.get(i);
                                c2 = drawCards.get(j);
                            }
                        }
                    }
                    if (c1 != -1) {
                        drawCards.remove(Integer.valueOf(c1));
                        drawCards.remove(Integer.valueOf(c2));
                        answer++;
                        coin -= 2;
                        continue;
                    }
                }

                break;
            }
            return answer;
        }
    }
}
