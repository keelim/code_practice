import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();

        ArrayList<String> arrayList = new ArrayList<>();
        for (int i = 0; i < num; i++) {
            String s = sc.next();
            arrayList.add(s);
        }

        Collections.sort(arrayList);
    }
}