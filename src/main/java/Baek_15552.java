import java.io.*;

public class Baek_15552 {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));

        int count, first, second = 0;
        String a;
        count = Integer.parseInt(reader.readLine());

        for (int i = 0; i < count; i++) {
            a = reader.readLine();
            first = Integer.parseInt(a.split(" ")[0]);
            second = Integer.parseInt(a.split(" ")[1]);

            writer.write(String.valueOf(first + second)+"\n");
        }
        writer.flush();

    }
}