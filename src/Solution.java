import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        for (int i = 1; i <= testCase; i++) {
            int num = sc.nextInt();
            int count = 0;
            for (int j = 0; j < num; j++) {
                String[] temp = sc.next().toLowerCase().split("");
                boolean flag = true;
                for (int k = 0; k < temp.length / 2; k++) {
                    if (temp[k].equals(temp[temp.length - 1 - k]))
                        flag = true;
                    else
                        flag = false;
                }
                if (flag)
                    count++;
            }

            System.out.println("#" + i + " " + count);
        }
    }
}