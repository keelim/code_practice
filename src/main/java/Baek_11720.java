import java.util.Scanner;

public class Baek_11720 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int anInt = sc.nextInt();
        sc.nextLine();
        String number = sc.nextLine();
        int[] ints = new int[anInt];
        int answer = 0;
        for (int i = 0; i < number.length(); i++) {
            answer += Integer.parseInt(number.substring(i, i + 1));
        }
        System.out.println(answer);

    }

}