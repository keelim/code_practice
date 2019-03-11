package S.D2;

import java.util.Scanner;

public class S_1954 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());

        for (int t = 1; t <= test_case; t++) {
            int input = Integer.parseInt(sc.nextLine());
            System.out.println("#" + t);
            int[][] arr = new int[input][input];
            int size = input;
            int value = 1, row = 0, col = -1, inc = 1;

            while (size > 0) {
                for (int i = 0; i < size; i++) {
                    col += inc;
                    arr[row][col] = value;
                    value++;

                }
                size--;
                if (size == 0) break;
                for (int i = 0; i < size; i++) {
                    row += inc;
                    arr[row][col] = value;
                    value++;

                }
                inc *= -1;
            }

            for (int i = 0; i < input; i++) {
                for (int j = 0; j < input; j++) {

                    System.out.print(arr[i][j] + " ");
                }
                System.out.println();

            }
        }
    }
}
