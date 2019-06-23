package L;

import java.util.ArrayList;

public class L_922 {
    ArrayList<Integer> even = new ArrayList<>();
    ArrayList<Integer> odd = new ArrayList<>();
    ArrayList<Integer> answer = new ArrayList<>();



    public int[] sortArrayByParityII(int[] A) {
        int[] temp_answer = new int[A.length];
        for (int i = 0; i < A.length; i++)
            answer.add(0);

        for (int a : A) {
            if (a % 2 == 0) even.add(a);
            else odd.add(a);
        }
        for (int i = 0; i < even.size(); i++) 
            answer.set(2*i, even.get(i));
        for (int i = 0; i < odd.size(); i++)
            answer.set(2*i+1, odd.get(i));
        for (int i = 0; i < answer.size(); i++) {
            temp_answer[i] = answer.get(i);
        }


        return temp_answer;
    }
}