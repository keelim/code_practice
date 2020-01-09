import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {//4
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> arrayList = new ArrayList<>();
        int total = 0;
        for (int i = 0; i < 9; i++) {
            int temp=sc.nextInt();
            arrayList.add(temp);
            total+=temp;
        }
        int pointer1 = 0;
        int pointer2 = pointer1+1;
        while (total-(arrayList.get(pointer1)+arrayList.get(pointer2))!=100){
            pointer2++;
            if(pointer2 >= 9){
                pointer1++;
                pointer2 = pointer1+1;
            }
        }

        arrayList.remove(pointer1);
        arrayList.remove(pointer2-1);

        Collections.sort(arrayList);
        for (int i = 0; i < 7; i++) {
            System.out.println(arrayList.get(i));
        }
    }
}
