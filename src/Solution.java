import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] temp = sc.nextLine().split("");
        int answer = 0;
        for (int i = 0; i < temp.length; i++) {
            answer += Integer.parseInt(temp[i]);
        }
        System.out.println(answer);
    }
}