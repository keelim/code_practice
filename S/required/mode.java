import java.util.Scanner;

public class mode {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        for (int i = 0; i < testCase; i++) {
            int maxCount = 0;
            int maxScore = 0;
            int[] student = new int[101];
            for (int j = 0; j < 1000; j++) {
                int score = sc.nextInt();
                student[score]++;
            }

        }
    }
}
