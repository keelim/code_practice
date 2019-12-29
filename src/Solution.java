import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        for (int i = 1; i <= testCase; i++) {
            String answer = "";
            String temp = sc.next();
            temp = temp.substring(temp.length()-1, temp.length());
            int now = Integer.parseInt(temp);
            if(now%2==0)
                answer="Even";
            else
                answer="Odd";


            System.out.println("#"+i+" "+answer);
        }      
    }
}