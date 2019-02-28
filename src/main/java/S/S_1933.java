package S;

import java.util.Scanner;

public class S_1933 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int temp = Integer.parseInt(sc.nextLine());

        for (int i = 1; i <= temp ; i++) {
            if((temp%i) == 0)
                System.out.print(i+" ");
        }

    }

}
