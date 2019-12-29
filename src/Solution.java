import java.util.Arrays;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        for (int i = 0; i < testCase; i++) {
            int total = sc.nextInt();
            int count = sc.nextInt();
            int[] array = new int[total];
            Arrays.fill(array, -1);
            for (int j = 0; j < count; j++) {
                int target = sc.nextInt();
                array[target - 1] = 1;
            }
            System.out.print("#"+ (i + 1) + " ");
            for (int j = 0; j < total; j++) {
                if (array[j] == -1)
                    System.out.print(j + 1 + " ");
            }
            System.out.println();
        }
    }
}