package S.D2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class S_1966 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());

        for (int t = 1; t <= test_case; t++) {
            String input = sc.nextLine();
            ArrayList arrayList = new ArrayList<>();
            String[] tmp = sc.nextLine().split(" ");

            for (String s : tmp) {
                int change_s = Integer.parseInt(s);
                arrayList.add(change_s);
            }

            Collections.sort(arrayList);

            System.out.print("#"+t+" ");
            for (int i = 0; i < arrayList.size(); i++) {
                System.out.print(arrayList.get(i)+" ");
            }


        }
    }
}
