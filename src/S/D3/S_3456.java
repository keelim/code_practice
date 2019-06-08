package S.D3;

import java.util.ArrayList;
import java.util.Scanner;

public class S_3456 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());

        for (int t = 1; t <= test_case; t++) {
            int answer = 0;
            ArrayList<Integer> arrayList = new ArrayList<>();

            for (String a : sc.nextLine().split(" "))
                arrayList.add(Integer.parseInt(a));

            int a = arrayList.get(0);
            int b = arrayList.get(1);
            int c = arrayList.get(2);

            if (a == b) {
                if (b == c) {
                    answer = a;

                } else
                    answer = c;

            } else if (a == c) {
                answer = b;

            } else if (b == c) {
                answer = a;

            }

            System.out.println("#" + t + " " + answer);

        }
    }
}
