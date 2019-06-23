package S.D1;

import java.util.ArrayList;
import java.util.Scanner;

public class S_2070 {
    public static void main(String[] args) {
        int first, second;
        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());
        for (int t = 1; t <= test_case; t++) {
            ArrayList<Integer> arrayList = new ArrayList<>();
            String[] temp = sc.nextLine().split(" ");

            first = Integer.parseInt(temp[0]);
            second = Integer.parseInt(temp[1]);
            String s;
            if (first > second)
                s = ">";
            else if (first < second)
                s = "<";
            else
                s = "=";

            System.out.println("#" + t + " " + s);
        }


    }


}


