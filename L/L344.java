package L;

import java.util.Arrays;

public class L344 {
    public void sortColors(int[] nums) {
        for (int a : nums) {
            System.out.println(a);
        }
        Arrays.sort(nums);
        System.out.println(nums);
        for (int a : nums) {
            System.out.println(a);
        }
    }
}