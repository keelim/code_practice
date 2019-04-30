package H;

import java.util.Scanner;
import java.util.Stack;

public class Queue {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int test_case = Integer.parseInt(sc.nextLine());
        Stack<Integer> stack = new Stack<>();

        for (int t = 1; t <= test_case; t++) {
            String[] temp = sc.nextLine().split(" ");
            if (temp[0].equals("1")) {
                stack.push(Integer.parseInt(temp[1]));
            } else if (temp[0].equals("2")) {
                stack.pop();
            } else if (temp[0].equals("3")) {
                System.out.println(stack.peek());
            }

        }
    }
}
