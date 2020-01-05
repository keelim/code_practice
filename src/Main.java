import java.util.Scanner;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        for (int i = 0; i < testCase; i++) {
            int repeat = sc.nextInt();
            String[] line = sc.next().split("");
            for (int j = 0; j < line.length; j++) {
                for (int k = 0; k < repeat; k++) {
                    System.out.print(line[j]);
                }
            }
            System.out.println();
        }
    }
}