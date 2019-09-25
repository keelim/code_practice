package S.D1;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class S_2058 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String[] temp = sc.nextLine().split("");
        ArrayList<Integer> list = new ArrayList<>();
        for (String a : temp)
            list.add(Integer.parseInt(a));
        int answer = 0;

        for (int a : list)
            answer+=a;

        System.out.println(answer);

    }


}


