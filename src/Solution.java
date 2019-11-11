import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int pass = sc.nextInt(), input = sc.nextInt();
        System.out.println(pass - input + 1);
    }
}

