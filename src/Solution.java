import java.util.Arrays;

class Solution {
    public int solution(int[] grade, int max_diff) {
        int[] grade_count = new int[grade.length];
        Arrays.fill(grade_count, 0);

        for (int i = 0; i < grade.length; i++) {
            int standard = grade[i];
            int count = 0;
            for (int value : grade) {
                if (value >= standard - max_diff && value <= standard + max_diff) {
                    count++;
                }
            }
            grade_count[i] = count;
        }


        int max = 0;
        for (int i = 0; i < grade_count.length; i++) {
            if (grade_count[i] >= max)
                max = grade_count[i];
        }
        return max;
    }
}