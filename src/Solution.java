import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testNum = sc.nextInt();
        ArrayList<Integer> arrayList = new ArrayList<>();
        for (int i = 0; i < testNum; i++) {
            arrayList.add(sc.nextInt());
        }
        Collections.sort(arrayList);
        int answer = arrayList.get(testNum/2);
        System.out.println(answer);
    }
}