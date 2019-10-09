import java.util.Base64;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = Integer.parseInt(sc.nextLine().trim());
        for (int i = 1; i <= testCase; i++) {
            String answer = sc.nextLine();
            answer = new String(Base64.getDecoder().decode(answer.getBytes()));
            System.out.println("#" + i + " " + answer);
        }
    }
}
