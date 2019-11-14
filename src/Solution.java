import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int test_case = sc.nextInt();

        for (int t = 1; t <= test_case; t++) {
            int first = sc.nextInt(), second = sc.nextInt();
            System.out.println("#" + t +" "+ first / second + " " + first % second);
        }
    }
}
