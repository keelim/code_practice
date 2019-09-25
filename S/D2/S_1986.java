package S.D2;

import java.util.ArrayList;
import java.util.Scanner;

public class S_1986 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());

        for (int t = 1; t <= test_case; t++) {
            ArrayList<Integer> arrayList = new ArrayList<>();

            int count = Integer.parseInt(sc.nextLine());

            for (int i = 1; i <= count; i++)
                arrayList.add(i);

            for (int i = 0; i < arrayList.size(); i++) {
                if (arrayList.get(i) % 2 == 0)
                    arrayList.set(i, -1 * arrayList.get(i));
            }

            int answer = 0;

            for (int a : arrayList)
                answer += a;

            System.out.println("#" + t + " " + answer);


        }
    }
}

