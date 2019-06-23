package S.D2;

import java.util.*;

public class S_1204 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());

        for (int t = 1; t <= test_case; t++) {
            int input = sc.nextInt(); // 케이스를 입력 받는다.
            ArrayList<Integer> arrayList = new ArrayList<>();

            for (String a : sc.nextLine().split(" "))
                arrayList.add(Integer.parseInt(a));
            Collections.sort(arrayList); //arrayList 를 정렬을 시킨다.

            HashSet<Integer> hashSet = new HashSet<>();
            HashMap<Integer, Integer> map = new HashMap<>();

            hashSet.addAll(arrayList);

            for (int a : hashSet) {
                int count = 0;
                for (int i = 0; i < arrayList.size(); i++) {
                    if (arrayList.get(i) == a)
                        count++;
                }
                map.put(a, count);
            }






            int answer = 0;


            System.out.println("#" + input + " " + answer);
        }
    }
}
