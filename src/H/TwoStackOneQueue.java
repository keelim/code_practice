package H;

import java.util.Scanner;
import java.util.Stack;

public class TwoStackOneQueue {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Stack<Integer> stack1 = new Stack<>();
        Stack<Integer> stack2 = new Stack<>();
        Scanner sc = new Scanner(System.in);

        int testcase = Integer.parseInt(sc.nextLine());
        for (int i = 1; i <= testcase; i++) {
            String[] temp = sc.nextLine().split(" ");

            if (temp[0].equals("1")) {
                stack1.push(Integer.parseInt(temp[1]));

            } else if (temp[0].equals("2")) {
                for (int is : stack1) {
                    stack2.push(stack1.pop());
                }
                stack2.pop();

            } else {
                System.out.println(stack2.peek());
            }
        }
    }
}

