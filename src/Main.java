import java.util.Scanner;

public class Main {//4

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int E = sc.nextInt();
        int S = sc.nextInt();
        int M = sc.nextInt();

        int pointer1 = 1, pointer2 = 1, pointer3 = 1, answer = 1;
        while (!(pointer1 == E && pointer2 == S && pointer3 == M)) {
            pointer1++;
            pointer2++;
            pointer3++;
            answer++;
            if(pointer1>15) pointer1 = 1;
            if(pointer2>28) pointer2 =1;
            if(pointer3>19) pointer3 = 1;
        }

        System.out.println(answer);
    }
}
