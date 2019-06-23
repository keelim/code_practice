package S.D1;

import java.util.Scanner;

public class S_2019 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int answer;
        int anInt = Integer.parseInt(sc.nextLine());
        for (int t = 0; t <= anInt; t++) {
            answer = (int) Math.pow(2, t);
            System.out.print(answer + " ");
        }

    }

}
