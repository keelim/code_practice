import java.util.ArrayList;

public class Leet_942 {


    public int[] diStringMatch(String S) {
        ArrayList arrayList = new ArrayList();
        ArrayList answerTemp = new ArrayList();


        for (int i = 0; i < S.length() + 1; i++) {
            arrayList.add(i);
        }
        String[] temp = S.split("");

        for (String a : temp) {
            if (a.equals("I")) {
                answerTemp.add(arrayList.get(0));
                arrayList.remove(0);

            } else if (a.equals("D")) {
                answerTemp.add(arrayList.get(arrayList.size() - 1));
                arrayList.remove(arrayList.size() - 1);
            }

        }
        answerTemp.add(arrayList.get(0));
        int answer[] = new int[answerTemp.size()];
        for (int i = 0; i < answer.length; i++) {
            answer[i] = (int) answerTemp.get(i);
        }

        return answer;
    }


}
