package prefixsum;

// result : https://app.codility.com/demo/results/training3Q6MFX-5D4/
public class Codility_GenomicRangeQuery {

    /*
    * CAGCCTA
    *
    *    0  1  2  3  4  5  6  7
    * A  0  0  1  1  1  1  1  2
    * C  0  1  1  1  2  3  3  3
    * G  0  0  0  1  1  1  1  1
    * T  0  0  0  0  0  0  1  0
    *
    * 위와 같은 구간합을 만들어서
    * end+1 과 start의 차를 ACGT 순으로 차를 구하고, 제일 작은 값으로 갱신한다. 
    * */
    public int[] solution(String S, int[] P, int[] Q) {
        int n = S.length();
        int[][] nums = new int[n+1][4];

        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < 4; j++) {
                nums[i][j] = nums[i-1][j];
            }
            int currNuc = getNuCleotide(S.charAt(i-1));
            nums[i][currNuc - 1] += 1;
        }

        int m = P.length;
        int[] answer = new int[m];
        for(int i = 0; i < m; i++) {
            int start = P[i];
            int end = Q[i];

            for(int j = 0; j < 4; j++) {
                if(nums[end+1][j] - nums[start][j] > 0) {
                    answer[i] = j+1;
                    break;
                }
            }

        }

        return answer;
    }

    public int getNuCleotide(char c) {
        if(c == 'A') return 1;
        if(c == 'C') return 2;
        if(c == 'G') return 3;
        return 4;
    }
}
