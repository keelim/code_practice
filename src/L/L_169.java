package L;

import java.util.ArrayList;
import java.util.HashSet;

public class L_169 {
    public int majorityElement(int[] nums) {
        ArrayList<Integer> arrayList = new ArrayList<>();
        ArrayList<Integer> temp1 = new ArrayList<>();
        ArrayList<Integer> temp2 = new ArrayList<>();

        for (int a : nums)
            arrayList.add(a);

        HashSet<Integer> hashSet = new HashSet<>(arrayList);
        for (int a : hashSet) {
            int b = 0;
            temp1.add(a); // element
            for (int count : arrayList) {
                if (a == count) {
                    b += 1;
                }
            }
            temp2.add(b);
        }

        int answer = 0;
        return answer;
    }
}