package S.D1;

import java.util.ArrayList;
import java.util.Scanner;

public class S_2056 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        ArrayList month_1, month_2;
        month_1 = new ArrayList();
        month_2 = new ArrayList();

        int test_case = Integer.parseInt(sc.nextLine());
        for (int t = 1; t <= test_case; t++) {
            String[] temp = sc.nextLine().split("");
            int year, month, day;
            String year_origin = temp[0] + temp[1] + temp[2] + temp[3];
            year = Integer.parseInt(year_origin);

            String month_origin = temp[4] + temp[5];
            month = Integer.parseInt(month_origin);

            String day_origin = temp[6] + temp[7];
            day = Integer.parseInt(day_origin);

            for (int a : new int[]{1, 3, 5, 7, 8, 10, 12})
                month_1.add(a);

            for (int a : new int[]{4, 6, 9, 11})
                month_2.add(a);

            if (month == 0 || month > 12) {
                System.out.println("#" + t + " -1");
                continue;
            }

            if (month_1.contains(month)) {
                if (day == 0 || day > 30) {
                    System.out.println("#" + t + " -1");
                    continue;
                }

            }
            if (month_2.contains(month)) {
                if (day == 0 || day > 31) {
                    System.out.println("#" + t + " -1");
                    continue;
                }
            }

            if (month == 2)
                if (day > 28) {
                    System.out.println("#" + t + " -1");
                    continue;
                }


            System.out.println("#" + t + " " + year_origin + "/" + month_origin + "/" + day_origin);

        }


    }

}
