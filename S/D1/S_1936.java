package S.D1;

import java.util.ArrayList;
import java.util.Scanner;

public class S_1936 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> arrayList = new ArrayList<>();
        String[] temp = sc.nextLine().split(" ");

        for (String s : temp) {
            arrayList.add(Integer.parseInt(s));
        }

        int a = arrayList.get(0);
        int b = arrayList.get(1);

        if((a == 1&&b==3)||(a==2 && b==1)||(a==3&&b==2))
            System.out.println("A");
        else
            System.out.println("B");
    }

}
