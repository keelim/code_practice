import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int anInt = sc.nextInt();
        int answer = 1;
        for (int t = 0; t <= anInt; t++) {
            System.out.print(answer + " ");
            answer *= 2;
        }
    }
}
