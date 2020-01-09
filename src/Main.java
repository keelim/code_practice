import java.util.Scanner;

public class Main {// 4

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int testCase = sc.nextInt();
        for (int i = 0; i < testCase; i++) {
            int a = sc.nextInt(), b = sc.nextInt();
            int gcd_a = a, gcd_b = b;

            while (gcd_b > 0) {
                int temp = gcd_b;
                gcd_b = gcd_a % gcd_b;
                gcd_a = temp;
            }
            int lcm = a * b / gcd_a;
            System.out.println(lcm);
        }


    }


}
