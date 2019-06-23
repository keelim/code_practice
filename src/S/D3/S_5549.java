package S.D3;

import java.util.Scanner;

public class S_5549 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());

        for (int t = 1; t <= test_case; t++) {
            int input = sc.nextInt();
            if(input % 2 == 0)
                System.out.println("#"+t+" " + "Even");
            else
                System.out.println("#"+t+" " + "Odd");
        }
    }
}
