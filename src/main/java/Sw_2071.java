import java.util.ArrayList;
import java.util.Scanner;

public class Sw_2071 {
    public static void main(String[] args) {
        int Sum = 0;
        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());
        for (int t = 1; t <= test_case; t++) {
            ArrayList<Integer> arrayList = new ArrayList<>();
            String[] temp = sc.nextLine().split(" ");
            for (String s : temp) {
                int change_s = Integer.parseInt(s);
                arrayList.add(change_s);
            }
            for (int a : arrayList)
                Sum += a;

            float a = (float) Sum / (float) arrayList.size();

            System.out.println("#" + t + " " + Math.round(a*10/10.0));

            Sum = 0;

        }


    }

}
