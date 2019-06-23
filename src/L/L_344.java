package L;

import java.util.Arrays;

class L75 {
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

    public static void main(String[] args) {
        new L75().sortColors(new int[]{1, 2, 3, 4});


    }
}