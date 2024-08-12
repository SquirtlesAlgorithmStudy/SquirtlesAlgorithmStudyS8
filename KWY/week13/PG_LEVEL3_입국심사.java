package binary_search;

import java.util.Arrays;

public class PG_LEVEL3_입국심사 {
    class Solution {
        // 심사관 : m , 고객 : n 일 때, mLog(n) 이 되어야 한다.
        public long solution(int n, int[] times) {
            Arrays.sort(times);
            long start = times[0];
            long end = (long)times[times.length-1]*(long)n;
            while(start <= end) {
                long mid = (start + end) / 2;
                long temp = 0;
                for(int t: times) {
                    temp += (mid/t);
                }
                if(temp >= n) {
                    end = mid-1;
                } else {
                    start = mid+1;
                }
            }

            return start;
        }
    }
}
