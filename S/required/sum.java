import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;

public class sum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for (int i = 0; i < 10; i++) {
            HashSet<Integer> set = new HashSet<>();
            int testCase = sc.nextInt();
            int[][] array = new int[100][100];

            for (int j = 0; j < 100; j++) {
                for (int k = 0; k < 100; k++) {
                    array[j][k] = sc.nextInt();
                }
            } //변수 넣기
            int a = 0, b = 0, c = 0, d = 0;

            for (int j = 0; j < 100; j++) {
                c += array[j][j];
                d += array[j][99 - j];
                for (int k = 0; k < 100; k++) {
                    a += array[j][k];
                    b += array[k][j];
                }
                set.add(a);
                set.add(b);
                set.add(c);
                set.add(d);
                a = 0;
                b = 0;
                c = 0;
                d = 0;
            }// 각행, 각열, 대각선, 다른 대각선

            int answer = Collections.max(set);
            System.out.println("#" + testCase + " " + answer);
        }
    }
}
