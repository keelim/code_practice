package S.D2;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Scanner;

public class S_1959 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = Integer.parseInt(sc.nextLine());

        for (int t = 1; t <= testCase; t++) {
            int answer = 0, temp_size = 0;
            ArrayList<Integer> first = new ArrayList<>();
            ArrayList<Integer> second = new ArrayList<>();
            ArrayList<Integer> temp = new ArrayList<>();


            String[] s = sc.nextLine().split(" ");
            temp_size = (Integer.parseInt(s[0]) > Integer.parseInt(s[1])) ? Integer.parseInt(s[0]) : Integer.parseInt(s[1]);

            for (int i = 0; i < temp_size; i++) //리스트 변환
                temp.add(0);

            for (String a : sc.nextLine().split(" ")) //리스트 변환
                first.add(Integer.parseInt(a));

            for (String a : sc.nextLine().split(" ")) //리스트 변환
                second.add(Integer.parseInt(a));

            int answer_size = Math.abs(first.size() - second.size()); //사이즈 만큼의 횟수를 반복 한다. 2이면 0, 1, 2만큼

            for (int i = 0; i < answer_size; i++) {
                for(int a : )
            }


            System.out.println("#" + t + " " + answer); //정답을 만드는 함수
        }


    }
}
