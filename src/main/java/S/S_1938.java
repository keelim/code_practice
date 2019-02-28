package S;

import java.util.ArrayList;
import java.util.Scanner;

public class S_1938 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        ArrayList<Integer> arrayList = new ArrayList<>();
        String[] temp = sc.nextLine().split(" ");

        for (String s :  temp)
            arrayList.add(Integer.parseInt(s));

        System.out.println(arrayList.get(0) + arrayList.get(1));
        System.out.println(arrayList.get(0) - arrayList.get(1));
        System.out.println(arrayList.get(0) * arrayList.get(1));
        System.out.println(arrayList.get(0) / arrayList.get(1));

    }

}
