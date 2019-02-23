package S;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class S_2068 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());
        for (int t = 1; t <= test_case; t++) {
            ArrayList<Integer> arrayList = new ArrayList<>();
            String[] temp = sc.nextLine().split(" ");
            for (String temp_string : temp)
                arrayList.add(Integer.parseInt(temp_string));
            Collections.sort(arrayList);
            Collections.reverse(arrayList);
            System.out.println("#" + t + " " + arrayList.get(0));
        }


    }


}


