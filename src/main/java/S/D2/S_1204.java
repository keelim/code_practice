package S.D2;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class S_1204 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());

        for (int t = 1; t <= test_case; t++) {
            int selected_case = Integer.parseInt(sc.nextLine());

            ArrayList<Integer> arrayList = new ArrayList<>();
            //원본 리스트
            String[] temp_array = sc.nextLine().split(" ");

            for (String s : temp_array)
                arrayList.add(Integer.parseInt(s)); //원본의 사용되는 리스트

            HashSet<Integer> set = new HashSet<>(); //셋은 순서가 없어서 안된다.

            for (String s : temp_array)         //원소만 나타낸느 해쉬셋
                set.add(Integer.parseInt(s));

            //원소를 저장 하는 해쉬 셋
            ArrayList<Integer> answer_list = new ArrayList<>();
            //숫자를 셋는 리스트
            //해쉬셋과 크기가 같아야 한다. 각각의 크기의 맞추어서






        }
    }
}
