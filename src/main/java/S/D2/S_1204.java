package S.D2;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class S_1204 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());

        for (int t = 1; t <= test_case; t++) {
            int input = sc.nextInt(); // 케이스를 입력 받는다.
            ArrayList<Integer> arrayList = new ArrayList<>();
            HashSet<Integer> hashSet = new HashSet<>();

            arrayList.containsAll()

            for (String a : sc.nextLine().split(" "))
                arrayList.add(Integer.parseInt(a));

           int answer = 0;

            System.out.println("#" + input + " " + answer);
        }
    }
}
