package H;

import java.util.Scanner;
import java.util.Stack;

public class Maximum_Element {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */

        Scanner sc = new Scanner(System.in);
        Stack<Integer> stack = new Stack<>();
        int temp = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < temp; i++) {
            String a[] = sc.nextLine().split(" ");
            if (a[0].equals("1")) {
                stack.push(Integer.parseInt(a[1]));
            } else if (a[0].equals("2")) {
                stack.pop();
            } else if (a[0].equals("3")) {
                int max = 0;
                for (int as : stack) {
                    if (max < as) {
                        max = as;
                    }
                }
                System.out.println(max);
            }

        }
    }
}

