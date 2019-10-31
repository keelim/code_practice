import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        for (int i = 1; i <= testCase ; i++) {
            int answer = 0;
            for (int j = 0; j < 10; j++) {
                answer+= sc.nextInt();
            }
            answer/=10;
            System.out.println("#"+i+" " + answer);
        }
    }
}