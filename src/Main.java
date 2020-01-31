import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int first = sc.nextInt();
        int second = sc.nextInt();

        if(first - second>0){
            System.out.println(">");
        } else if(first-second == 0){
            System.out.println("==");
        } else{
            System.out.println("<");
        }
    }
}