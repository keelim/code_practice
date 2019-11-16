import java.util.ArrayList;

class Solution {

    public int solution(int[] people, int[] tshirts) {
        ArrayList<Integer> peopleList = new ArrayList<>();
        ArrayList<Integer> shirtList = new ArrayList<>();
        int answer = 0;


        for (int person : people) {
            peopleList.add(person);
        }
        for (int tshirt : tshirts) {
            shirtList.add(tshirt);
        }
        for (int i = 0; i < peopleList.size(); i++) {
            int first = peopleList.get(i);
            for (int j = 0; j < shirtList.size(); j++) {
                int second = shirtList.get(j);
                if (second == first) {
                    peopleList.remove(i);
                    shirtList.remove(j);
                    answer++;
                } else {
                    for (int k = 0; k < shirtList.size(); k++) {
                        second++;
                        if (second == first) {
                            peopleList.remove(i);
                            shirtList.remove(k);
                            answer++;
                            break;
                        }
                    }
                }
            }
        }
        return answer;
    }
}
