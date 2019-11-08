import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        for (int i = 1; i <= testCase; i++) {
            String temp = sc.next();
            if (temp.length() != 8) {
                System.out.println("#" + i + " " + -1);
                continue;
            }

            String year = temp.substring(0, 4);
            String month = temp.substring(4, 6);
            int iMonth = Integer.parseInt(month);
            String day = temp.substring(6);
            int iDay = Integer.parseInt(day);


            int[] end = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

            if (iMonth == 0 || iMonth >= 13) {
                System.out.println("#" + i + " " + -1);
                continue;
            } else if (iDay == 0 || iDay >= 32) {
                System.out.println("#" + i + " " + -1);
                continue;
            } else if (iDay > end[iMonth]) {
                System.out.println("#" + i + " " + -1);
                continue;
            }

            System.out.println("#" + i + " " + year + "/" + month + "/" + day);
        }
    }
}
