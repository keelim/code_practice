package Hackers;

import java.util.Arrays;

public class LeftRotation {
    static int[] rotLeft(int[] a, int d) { //d는 반복
        int[] answer = Arrays.copyOf(a, a.length);
        for (int i = 0; i < d; i++) {
            int ar_temp = answer[0];
            System.arraycopy(answer, 1, answer, 0, answer.length - 1);
            answer[answer.length-1] = ar_temp;
        }
        return answer;
    }

}
