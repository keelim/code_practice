import java.util.Scanner;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();

        for (int i = 0; i < testCase; i++) {
            int total = sc.nextInt();
            String[] line = sc.nextLine().split(" ");
            ArrayList<String> array1 = new ArrayList<>();
            ArrayList<String> array2 = new ArrayList<>();
            for (int j = 0; j < total; j++) {
                if (j > total / 2)
                    array2.add(line[j]);
                else
                    array1.add(line[j]);

            }

            System.out.println("#" + (i + 1) + " ");
            for (int j = 0; j < total; j++) {
                if(j%2==0)
                array1.get(j);
                else
                array2.get(j);
            }
            System.out.println();
        }

    }
}