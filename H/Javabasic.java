package Hackers;

import java.text.SimpleDateFormat;
import java.util.*;

public class Javabasic {
    int N = 2;

    public void javaloop1() {
        for (int i = 0; i < 11; i++) {
            int answer = N * i;
            System.out.println(N + " x " + i + " = " + "answer");
        }
    }

    public void javaloop2() {
        int a, b, n;
        a = 5;
        n = 10;
        int temp = a;
        for (int i = 0; i < n; i++) {
            temp += Math.pow(2, i) * 2;
            System.out.println(temp + " ");
        }
    }

    public void convertString(int n) {
        String s = String.valueOf(n);
    }

    public void pandliomeCheck(String s) {
        char[] temp = s.toCharArray();
        int temp_long = temp.length;

        for (int i = 0; i < temp_long / 2; i++) {
            if (temp[i] == temp[temp_long - 1 - i])
                System.out.println("Yes");
        }
    }


    public String getDateDay(String date, String dateType) throws Exception {

        String day = "";
        SimpleDateFormat dateFormat = new SimpleDateFormat(dateType);
        Date nDate = dateFormat.parse(date);

        Calendar cal = Calendar.getInstance();
        cal.setTime(nDate);

        int dayNum = cal.get(Calendar.DAY_OF_WEEK);

        switch (dayNum) {
            case 1:
                day = "일";
                break;
            case 2:
                day = "월";
                break;
            case 3:
                day = "화";
                break;
            case 4:
                day = "수";
                break;
            case 5:
                day = "목";
                break;
            case 6:
                day = "금";
                break;
            case 7:
                day = "토";
                break;

        }
        return day;
    }


    public void making_array() {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();

        scan.close();

        // Prints each sequential element in array a
    }

    public void sub_string() {
        Scanner in = new Scanner(System.in);
        String S = in.next();
        int start = in.nextInt();
        int end = in.nextInt();
        System.out.println(S.substring(start, end));
    }

    public void introduction_string() {
        Scanner sc = new Scanner(System.in);
        String A = sc.next();
        String B = sc.next();

        System.out.println(A.length() + B.length());
        if (A.compareTo(B) >= 0) {
            A = A.substring(0, 1).toUpperCase() + A.substring(1);
            B = B.substring(0, 1).toUpperCase() + B.substring(1);
            System.out.println("Yes");
            System.out.print(B + " " + A);
        } else {
            System.out.println("No");
            A = A.substring(0, 1).toUpperCase() + A.substring(1);
            B = B.substring(0, 1).toUpperCase() + B.substring(1);
            System.out.print(A + " " + B);

        }
        sc.nextLine().trim();
        sc.close();
    }

    public void formatter() {
        Scanner scanner = new Scanner(System.in);
        double payment = scanner.nextDouble();
        scanner.close();

        // Write your code here.


//        System.out.println("US: " + us);
//        System.out.println("India: " + india);
//        System.out.println("China: " + china);
//        System.out.println("France: " + france);
    }

    public void list() {
        Scanner sc = new Scanner(System.in);
        String[] element = sc.nextLine().split(" ");
        ArrayList<String> list = new ArrayList<>(Arrays.asList(element));

        int test_case = sc.nextInt();
        for (int i = 0; i < test_case; i++) {
            if (sc.nextLine().equals("Insert")) {
                String[] temp = sc.nextLine().split(" ");
                list.add(Integer.parseInt(temp[0]), temp[1]);
            } else if (sc.nextLine().equals("Delete")) {
                String[] temp = sc.nextLine().split(" ");
                list.remove(Integer.parseInt(temp[0]));
            }
        }
        System.out.println(list);
    }
}
