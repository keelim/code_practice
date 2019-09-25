import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        for (int i = 1; i <= testCase; i++) {
            System.out.println("#" + testCase);
            int input = sc.nextInt();

            int[][] arr = new int[input][input];
            int size = input;
            int value = 1, row = 0, col = -1, inc = 1;
            while (size > 0) {
                for (int j = 0; j < size; j++) {
                    col += inc;
                    arr[row][col] = value;
                    value++;
                }
                size--;
                if (size == 0) break;//loop exist
                for (int j = 0; j < size; j++) {
                    row+=inc;
                    arr[row][col] = value;
                    value++;
                }
                inc*=-1;
            }
            for (int k = 0; k < input; k++) {
                for (int j = 0; j < input; j++) {
                    System.out.print(arr[k][j] + " ");
                }
                System.out.println();
            }

        }
    }
}
