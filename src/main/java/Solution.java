import java.util.ArrayList;

public class Solution {
    public int[] sortArrayByParity(int[] A) {
        ArrayList<Integer> temp1 = new ArrayList<>();
        ArrayList<Integer> temp2 = new ArrayList<>();
        int[] answer = new int [A.length];
        for (int a : A){
            if (a % 2 == 0) {
                temp2.add(a);
            } else{
                temp1.add(a);
            }
        }
        for(int a : temp1)
            temp2.add(a);

        for (int i = 0; i < answer.length ; i++) {
            answer[i] = temp2.get(i);
        }
        return answer;
    }
}