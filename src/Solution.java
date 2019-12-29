import java.util.ArrayList;
import java.util.Collection;
import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int testCase = sc.nextInt();
        for (int i = 1; i <= testCase; i++) {
            int first = sc.nextInt();
            int second = sc.nextInt();
            int answer = 0;
            ArrayList<Integer> array = new ArrayList<>();
            for (int j = 1; j <= first; j++) {
                array.add(sc.nextInt());
            }
            Collections.sort(array, Collections.reverseOrder());

            for (int j = 0; j < second; j++) {
             answer+=array.get(j);
            }
        
            System.out.println("#"+i+" "+answer);
        }
    }
}