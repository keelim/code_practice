import java.util.Arrays;
import java.util.Scanner;

public class Main {
    static int[] memo = new int[10];

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Arrays.fill(memo, -1);
        int first = sc.nextInt();
        int second = sc.nextInt();
        memo[0] = 1;
        memo[1] = 1;
        int answer = factorial(first)/(factorial(second)*factorial(first-second));
        System.out.println(answer);
    }

    static int factorial(int n){
        if(memo[n]!=-1) return memo[n];
        memo[n] = memo[n-1]+memo[n-2];
        return memo[n];
    }
}