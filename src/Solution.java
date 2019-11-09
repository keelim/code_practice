import java.util.ArrayList;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        ArrayList<Character> list = new ArrayList<>();
        String[] temp = sc.nextLine().split("");

        for (int i = 0; i < temp.length; i++) {
            list.add(temp[i].charAt(0));
        }

        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i)-64 + " ");
        }
    }
}


