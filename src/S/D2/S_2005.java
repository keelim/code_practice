package S.D2;

import java.util.ArrayList;
import java.util.Scanner;

public class S_2005 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());

        for (int t = 1; t <= test_case; t++) {

            System.out.println("#" + t);

            int input = Integer.parseInt(sc.nextLine());

            ArrayList<Integer> temp = new ArrayList<>();
            if (input < 3) {
                System.out.println(1);

                if (input == 2)
                    System.out.println(1 + " " + 1);

            }

            for (int i = 2; i < input; i++) { //줄
                ArrayList<Integer> answer = new ArrayList<>(); //
                System.out.println(1);
                System.out.println(1 + " " + 1);

                temp.add(1);
                temp.add(1);

                for (int j = 0; j <= i; j++)  //현재 줄 설정
                    answer.add(1);

                for (int j = 0; j < answer.size(); j++) {
                    if ((j == 0 || j == answer.size() - 1))
                        continue;

                    answer.set(j, temp.get(j - 1) + temp.get(j));

                }
                temp.clear();

                for (int a : answer)
                    System.out.print(a + " ");

                System.out.println();
                temp.addAll(answer);
                answer.clear();

            }
        }
    }
}