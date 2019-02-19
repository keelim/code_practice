public class L1 {

    public int[] twoSum(int[] nums, int target) {
        int[] answer = new int[2];
        boolean temp_boolean = false;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                int temp = nums[i] + nums[j];
                if (temp == target) {
                    answer[0] = i;
                    answer[1] = j;
                    temp_boolean = true;
                }

                if (temp_boolean == true)
                    break;

            }
            if (temp_boolean == true)
                break;

        }

        return answer;
    }

    public static void main(String[] args) {
        L1 l1 = new L1();
        l1.twoSum(new int[]{2, 7, 11, 15}, 9);

    }
}