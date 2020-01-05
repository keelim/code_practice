
import java.util.Scanner;

public class Main {
	public static void main(String[] args) { 
		Scanner sc = new Scanner(System.in);
        String[] temp = sc.next().toLowerCase().split("");
        int[] answer = new int[26];
        for (int i = 0; i < answer.length; i++) {
            answer[i]=0;
        }

        for (int i = 0; i < temp.length; i++) {
            char s = temp[i].charAt(0);
            int pointer = s-97;
            answer[pointer]++;
        }

        for (int i = 0; i < answer.length; i++) {
            System.out.print(answer[i]+" ");
        }
	}
}