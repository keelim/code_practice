package S;

import java.util.Scanner;

public class S_2025 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int data = Integer.parseInt(sc.nextLine());
        int answer = 0;


        for (int i = 0; i <= data; i++) {
            answer+=i;
        }
        System.out.println(answer);

    }
}

