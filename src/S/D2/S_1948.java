package S.D2;

import java.util.ArrayList;
import java.util.Scanner;

public class S_1948 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int test_case =  Integer.parseInt(sc.nextLine());

        for (int i = 1; i <= test_case ; i++) {
            ArrayList<Integer> month_1 = new ArrayList<>();
            ArrayList<Integer> month_2 = new ArrayList<>();
            ArrayList<Integer> temp_list = new ArrayList<>();

            String[] temp = sc.nextLine().split("");
            int year, month, day;

            String year_origin = temp[0] + temp[1] + temp[2] + temp[3];
            year = Integer.parseInt(year_origin);

            String month_origin = temp[4] + temp[5];
            month = Integer.parseInt(month_origin);

            String day_origin = temp[6] + temp[7];
            day = Integer.parseInt(day_origin);

            for (int a : new int[]{1, 3, 5, 7, 8, 10, 12})//31
                month_1.add(a);

            for (int a : new int[]{4, 6, 9, 11})//30
                month_2.add(a);

            for(String s : sc.nextLine().split(" "))
                temp_list.add(Integer.parseInt(s));

            int first_month = temp_list.get(0);
            int first_date = temp_list.get(1);
            int second_month = temp_list.get(2);
            int second_date = temp_list.get(3);


        }

    }
}