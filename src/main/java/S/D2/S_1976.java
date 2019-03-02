package S.D2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class S_1976 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());

        for (int t = 1; t <= test_case; t++) {

            ArrayList<String> arrayList = new ArrayList<>();

            for (String s : sc.nextLine().split(" "))
                arrayList.add(s);


            int miniute = Integer.parseInt(arrayList.get(0)) + Integer.parseInt(arrayList.get(2));
            int second = Integer.parseInt(arrayList.get(1)) + Integer.parseInt(arrayList.get(3));

            if (second >= 60) {
                miniute += 1;
                second -= 60;
            }

            if(miniute >12)
                miniute-=12;

            System.out.println("#" + t + " " + miniute + " " + second);


        }
    }
}
