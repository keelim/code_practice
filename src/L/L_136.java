package L;

public class L_136 {

    public int singleNumber(int[] nums) {
        int count;
        for (int temp : nums) {
            count = 0;
            for (int i = 0; i < nums.length; i++) {
                if(temp == nums[i]){
                    count++;
                }
            }
            if(count == 1)
                return temp;
        }
        return 0;
    }


}
