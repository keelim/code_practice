import java.util.Scanner;

public class 부분합 {
    static int N, K, count;
    static int[] temp;

    static void solve(int sum, int pos) {
        if (sum > K) return;
        if (sum == K) {
            count++;
            return;
        }
        if (pos > N - 1) return;
        solve(sum, pos + 1);
        solve(sum + temp[pos], pos + 1);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 1; i <= T; i++) {
            N = sc.nextInt();
            K = sc.nextInt();
            temp = new int[N];
            for (int j = 0; j < N; j++) temp[j] = sc.nextInt();
            count = 0;
            solve(0, 0);
            System.out.println("#" + i + " " + count);
        }
        sc.close(); //스캐너를 종료를 하는 습관
    }
}