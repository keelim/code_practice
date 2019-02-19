import java.io.*;
import java.util.*;

public class baek_10989 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
        ArrayList<String> list = new ArrayList();

        int count, nums = 0;
        count = Integer.parseInt(reader.readLine());

        for (int i = 0; i < count; i++) {
            nums = Integer.parseInt(reader.readLine());
            list.add(String.valueOf(nums));
        }
        Collections.sort(list);
        for (int i = 0; i <list.size(); i++) {
            writer.write(list.get(i));
        }
        writer.flush();
        String a = "3";

    }
}