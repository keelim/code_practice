package S.D2;

import java.util.ArrayList;
import java.util.Scanner;

public class S_1970 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());

        for (int t = 1; t <= test_case; t++) {
            int money = Integer.parseInt(sc.nextLine());
            ArrayList<Integer> arrayList = new ArrayList<>();
            ArrayList<Integer> answer = new ArrayList<>();

            for (int a : new int[]{50000, 10000, 5000, 1000, 500, 100, 50, 10})
                arrayList.add(a);

            for (int a : arrayList) {
                int temp = money / a; //몫

                if (temp > 0) {
                    answer.add(temp);
                    money -= temp * a;
                } else
                    answer.add(0);

            }

            System.out.println("#" + t);

            for (int a : answer)
                System.out.print(a + " ");
            System.out.println();

        }
    }
}
