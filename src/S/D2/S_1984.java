package S.D2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class S_1984 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());

        for (int t = 1; t <= test_case; t++) {
            ArrayList<Integer> arrayList = new ArrayList<>();
            String[] temp = sc.nextLine().split(" ");

            for (String s : temp) {
                int change_s = Integer.parseInt(s);
                arrayList.add(change_s);
            }

            Collections.sort(arrayList);
            float temp_int = 0;

            for (int i = 1; i < arrayList.size() - 1; i++) {
                temp_int += (float) arrayList.get(i);
            }

            float size = arrayList.size()-2;
            float answer = temp_int/size;

            System.out.println("#" + t + " " + Math.round(answer*10/10.0));

        }
    }
}
