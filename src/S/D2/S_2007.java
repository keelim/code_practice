package S.D2;

import java.util.ArrayList;
import java.util.Scanner;

public class S_2007 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());

        for (int t = 1; t <= test_case; t++) {
            ArrayList<String> arrayList = new ArrayList<>();
            ArrayList<Integer> arrayList_1 = new ArrayList<>();
            Boolean flag = false;
            int answer = 0;

            for (String s : sc.nextLine().split(""))
                arrayList.add(s);

            for (int i = 1; i < arrayList.size(); i++) {
                if (arrayList.size() % i == 0)
                    arrayList_1.add(i);
            }

            for (int a : arrayList_1) {

                for (int i = 0; i < a; i++) {
                    if (arrayList.get(i).equals(arrayList.get(i + a)))
                        flag = true;
                    else flag = false;

                }

                if (flag == true) {
                    answer = a;
                    break;
                }
            }

            System.out.println("#" + t + " " + answer);


        }
    }
}
