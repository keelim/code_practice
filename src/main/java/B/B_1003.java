package B;

import java.util.Scanner;

public class B_1003 {
    
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());

        for (int t = 1; t <= test_case; t++) {
            int temp = Integer.parseInt(sc.nextLine());
            this.count1 = 0;
            this.count2 = 0;

        }

    }

    public static int fibonacci(int n) {

        if (n == 0) {
            count1++;
            return 0;
        }
        if (n == 1) {
            count2++
            return 1;
        } else {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }
}
