package S.D1;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class S_2063 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int count_case = Integer.parseInt(sc.nextLine());

        ArrayList<Integer> list = new ArrayList<>();
        int index;

        String[] temp = sc.nextLine().split(" ");
        for (String temp_string : temp)
            list.add(Integer.parseInt(temp_string));
        Collections.sort(list);
        index = count_case/2;

        System.out.println(list.get(index));

    }


}


