package S.D2;

import java.util.ArrayList;
import java.util.Scanner;

public class S_1926 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());

        for (int t = 1; t <= test_case; t++) {
            ArrayList<Integer> arrayList = new ArrayList<>();
            String temp2 = "";
            String temp[] = String.valueOf(t).split("");

            for (String a : temp)
                arrayList.add(Integer.parseInt(a));

            for (int i = 0; i < arrayList.size(); i++) {
                if (arrayList.get(i) % 3 == 0) {
                    if(arrayList.get(i) == 0)
                        continue;
                    temp2 += "-";

                }
            }

            if (temp2 != "") {
                System.out.print(temp2 + " ");
                continue;
            }

            System.out.print(t + " ");

        }
    }
}
