package S.D1;

import java.util.Scanner;

public class S_2029 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());

        for (int t = 1; t <= test_case; t++) {
            String[] temp = sc.nextLine().split(" ");

            int first, second;
            first = Integer.parseInt(temp[0]);
            second = Integer.parseInt(temp[1]);

            System.out.println("#" + t +" "+ first / second + " " + first % second);
        }
    }
}
