package S.D3;

import java.util.Scanner;

public class S_1217 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < 10; i++) {
            int test_case = Integer.parseInt(sc.nextLine());
            int answer = 0;
            String[] abc = sc.nextLine().split(" ");

            int num1 = Integer.parseInt(abc[0]);
            int num2 = Integer.parseInt(abc[1]);
            answer = (int) Math.pow(num1, num2);

            System.out.println("#" + test_case + " " + answer);
        }

    }
}
