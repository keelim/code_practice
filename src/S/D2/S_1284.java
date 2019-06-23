package S.D2;

import java.util.ArrayList;
import java.util.Scanner;

public class S_1284 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());

        for (int t = 1; t <= test_case; t++) {
            int answer = 0;
            ArrayList<Integer> list = new ArrayList<>();

            goList(sc, list);

            int p_a_charge, q_b_basic, r_b_statndard, s_b_overcharge, w_use, a_cost, b_cost;
            p_a_charge = list.get(0);
            q_b_basic = list.get(1);
            r_b_statndard = list.get(2);
            s_b_overcharge = list.get(3);
            w_use = list.get(4);
            a_cost = p_a_charge * w_use;

            answer = getAnswerfFnale(q_b_basic, r_b_statndard, s_b_overcharge, w_use, a_cost);

            System.out.println("#" + t + " " + answer);
        }
    }

    private static int getAnswerfFnale(int q_b_basic, int r_b_statndard, int s_b_overcharge, int w_use, int a_cost) {
        int b_cost;
        int answer;
        b_cost = getAnswer(q_b_basic, r_b_statndard, s_b_overcharge, w_use);
        answer = (a_cost > b_cost) ? b_cost : a_cost;
        return answer;
    }

    private static int getAnswer(int q_b_basic, int r_b_statndard, int s_b_overcharge, int w_use) {
        int b_cost;
        if (w_use <= r_b_statndard)
            b_cost = q_b_basic;
        else
            b_cost = q_b_basic + (w_use - r_b_statndard) * s_b_overcharge;
        return b_cost;
    }

    private static void goList(Scanner sc, ArrayList<Integer> list) {
        for (String s : sc.nextLine().split(" "))
            list.add(Integer.parseInt(s));
    }
}