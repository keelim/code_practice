package S.D3;

import java.util.ArrayList;
import java.util.Scanner;

public class S_3431 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());

        for (int t = 1; t <= test_case; t++) {
            ArrayList<Integer> inputList = new ArrayList<>();

            for(String temp_input : sc.nextLine().split(" ")) //리스트의 넣는다.
                inputList.add(Integer.parseInt(temp_input));

            int first = inputList.get(0);
            int second = inputList.get(1);
            int measurement = inputList.get(2);
            int answer = 0;


            if(first <=measurement){
                if(measurement<= second)
                    answer = 0;
                else
                    answer = -1;
            } else
                answer = first - measurement;


            System.out.println("#"+t+" " + answer);

        }
    }
}
