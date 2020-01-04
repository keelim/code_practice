import java.util.Scanner;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        for (int i = 0; i < testCase; i++) {
            String[] temp = sc.next().split("");
            int count = 0;
            int total = 0;
            for (int j = 0; j < temp.length; j++) {
                if (temp[j].equals("O")) {
                    count++;
                    total += count;
                } else {
                    count = 0;
                }
            }
			System.out.println(total);
        }
    }
}