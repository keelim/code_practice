import java.util.Scanner;

public class Main {
    static int location;
    static int[] applicant;
    static int master_dectector;
    static int sub_detector;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        location = sc.nextInt();
        applicant = new int[location];
        for (int i = 0; i < location; i++) {
            applicant[i] = sc.nextInt();
        }
        master_dectector = sc.nextInt();
        sub_detector = sc.nextInt();
        long answer = location;
        for (int i = 0; i < location; i++) {
            int temp = applicant[i];
            temp -= master_dectector;
            answer+=(temp/sub_detector);
            if(temp%sub_detector>0) answer++;
        }
        System.out.println(answer);
    }
}