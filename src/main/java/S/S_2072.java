package S;

import java.util.ArrayList;
import java.util.Scanner;

public class S_2072 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());
        for (int t = 1; t <= test_case; t++) {
            ArrayList<Integer> arrayList = new ArrayList<>();
            String[] temp = sc.nextLine().split(" ");
            for (String s : temp) {
                int change_s = Integer.parseInt(s);
                if (change_s % 2 != 0) {
                    arrayList.add((change_s));
                }

            }
            int odd_sum=0;
            for ( int a: arrayList){
                odd_sum+=a;
            }
            System.out.println("#"+t+" " + odd_sum);

        }


    }

}
