package S.D3;

import java.util.ArrayList;
import java.util.Scanner;

public class S_5688 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());

        for (int t = 1; t <= test_case; t++) {
            int input = sc.nextInt();
            ArrayList<Integer> arrayList = new ArrayList<>();


            for (int i = 0; ; i++) {
                arrayList.add((int) Math.pow(i, 3));
                int a = arrayList.get(i);

                if (a == input) {
                    System.out.println("#" + t + " " + i);
                    break;
                }

                if (a > input) {
                    System.out.println("#" + t + " -1");
                    break;
                }
            }


        }
    }
}
