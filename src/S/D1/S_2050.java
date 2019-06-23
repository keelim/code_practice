package S.D1;

import java.util.ArrayList;
import java.util.Scanner;

public class S_2050 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        ArrayList<Character> list = new ArrayList<>();
        String[] temp = sc.nextLine().split("");

        for(String a : temp){
            list.add(a.charAt(0));
        }
        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i)-64 + " ");
        }



    }


}


