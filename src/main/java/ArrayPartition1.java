import java.util.Arrays;
import java.util.Collections;

public class ArrayPartition1 {
    public int arrayPairSum(int[] nums) {
        int answer = 0;
        int  temp_n;
        Arrays.sort(nums);

        temp_n = nums.length/2;
        for(int i=0; i<temp_n; i++){

            answer += nums[2*i];

        }

        return answer;
    }
}
