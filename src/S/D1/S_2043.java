package S.D1;

import java.util.Scanner;

public class S_2043 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String[] temp = sc.nextLine().split(" ");
        int pass, input;
        pass = Integer.parseInt(temp[0]);

        input = Integer.parseInt(temp[1]);

        System.out.println(pass-input+1);
    }
}

