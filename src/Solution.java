import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        for (int i = 1; i <= testCase; i++) {
            int answer = 0;
            for (int j = 0; j < 10; j++) {
                int temp = sc.nextInt();
                if(temp>= answer)
                    answer=temp;
            }


        }
        char[] name = new char[100];
        for (int i = 0; i < name.length; i++) {
            name[i] = '\0';
        }
        
    }
}