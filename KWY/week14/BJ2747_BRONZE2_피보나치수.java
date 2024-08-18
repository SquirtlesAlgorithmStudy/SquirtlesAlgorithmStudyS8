package dp;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BJ2747_BRONZE2_피보나치수 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] f1Call = new int[n + 1];
        int[] f2Call = new int[n + 1];
        int[] f3Call = new int[n + 1];

        // 재귀
        System.out.println("재귀 방식 풀이 : " + f1(n, f1Call));
        printResult(f1Call);

        // top down
        int[] dp = new int[n + 1];
        dp[1] = 1;
        System.out.println("Top Down 방식 풀이 : " + f2(n, dp, f2Call));
        printResult(f2Call);

        // bottom up
        System.out.println("Bottom Up 방식 풀이 : " + f3(n, f3Call));
        printResult(f3Call);
    }

    /*
     * Bottom-Up 방식 풀이
     *
     * Bottom-Up 방식이란 가장 작은 문제부터 시작해서 답을 쌓아가면서 큰 문제를 해결하는 방식이다.
     * 주로 반복문을 사용하고, 점화식을 찾아야한다.
     * */
    public static int f3(int n, int[] f3Call) {
        int[] dp = new int[n + 1];
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];

            f3Call[i - 1] += 1;
            f3Call[i - 2] += 1;
        }
        f3Call[n] += 1;
        return dp[n];
    }

    /*
     * Top-down 방식 풀이
     *
     * Top-down 방식이란 가장 큰 문제부터 시작해서 작은 문제를 차례로 해결하는 방식이다.
     * 이 때, 메모이제이션을 통해서 해결한 문제를 기억했다가 재방문했을 때 추가 재귀 호출 없이 그 값을 바로 반환한다.
     * 주로 재귀를 사용한다.
     * */
    public static int f2(int n, int[] dp, int[] f2Call) {
        f2Call[n] += 1;
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (dp[n] != 0) {
            return dp[n];
        }
        dp[n] = f2(n - 1, dp, f2Call) + f2(n - 2, dp, f2Call);
        return dp[n];
    }

    /*
     * 재귀를 이용한 풀이
     *
     * https://blogfiles.pstatic.net/20160801_275/kks227_14700305083805XBuM_GIF/complexityRecursion_1.gif?type=w3840
     * */
    public static int f1(int n, int[] f1Call) {
        f1Call[n] += 1;
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        return f1(n - 1, f1Call) + f1(n - 2, f1Call);
    }

    public static void printResult(int[] result) {
        for (int i = 0; i < result.length; i++) {
            System.out.println("f(" + i + ") 호출 횟수 " + result[i]);
        }
        System.out.println("-----------------------");
    }
    /*
        재귀 방식 풀이 : 55
        f(0) 호출 횟수 34
        f(1) 호출 횟수 55
        f(2) 호출 횟수 34
        f(3) 호출 횟수 21
        f(4) 호출 횟수 13
        f(5) 호출 횟수 8
        f(6) 호출 횟수 5
        f(7) 호출 횟수 3
        f(8) 호출 횟수 2
        f(9) 호출 횟수 1
        f(10) 호출 횟수 1
        -----------------------
        Top Down 방식 풀이 : 55
        f(0) 호출 횟수 1
        f(1) 호출 횟수 2
        f(2) 호출 횟수 2
        f(3) 호출 횟수 2
        f(4) 호출 횟수 2
        f(5) 호출 횟수 2
        f(6) 호출 횟수 2
        f(7) 호출 횟수 2
        f(8) 호출 횟수 2
        f(9) 호출 횟수 1
        f(10) 호출 횟수 1
        -----------------------
        Bottom Up 방식 풀이 : 55
        f(0) 호출 횟수 1
        f(1) 호출 횟수 2
        f(2) 호출 횟수 2
        f(3) 호출 횟수 2
        f(4) 호출 횟수 2
        f(5) 호출 횟수 2
        f(6) 호출 횟수 2
        f(7) 호출 횟수 2
        f(8) 호출 횟수 2
        f(9) 호출 횟수 1
        f(10) 호출 횟수 1
        -----------------------
    * */
}
