package S.D2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class S_1989 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());

        for (int t = 1; t <= test_case; t++) {

            ArrayList<String> temp_list = new ArrayList<>();
            ArrayList<String> temp_list1 = new ArrayList<>();
            Boolean flag = false;
            String[] temp = sc.nextLine().split("");

            for (String s : temp) {
                temp_list.add(s);
                temp_list1.add(s);
            }

            Collections.reverse(temp_list1);

            for (int j = 0; j < temp_list.size(); j++) {
                String first = temp_list.get(j);
                String second = temp_list1.get(j);

                if (first.equals(second) ==false)
                    flag = true;
            }

            if (flag == true)
                System.out.println("#" + t + " " + 0);
            else
                System.out.println("#" + t + " " + 1);


        }
    }
}

