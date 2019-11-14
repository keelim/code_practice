import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int data = sc.nextInt();
        int answer = 0;
        for (int i = 1; i <= data; i++) {
            answer += i;
        }
        System.out.println(answer);
    }
}

