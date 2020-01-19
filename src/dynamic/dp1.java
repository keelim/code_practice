package dynamic;

import java.util.Arrays;
import java.util.Scanner;

public class dp1 {
    static int max = 1000001;
    static int[] dp = new int[max];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        Arrays.fill(dp, -1);
        System.out.println(f(n));
    }

    public static int f(int n) {
        if (n == 1) return 0;
        if (dp[n] > 0) return dp[n];

        int result = f(n - 1) + 1;
        if (n % 3 == 0) result = Math.min(result, f(n/3)+1);
        if (n % 2 == 0) result = Math.min(result, f(n/2)+1);
        dp[n] = result;
        return result;
    }
}
