package practice_code;

public class Recursion {

    public int fact(int n) {
        if (n == 1) {
            return 1;
        } else {
            return n * fact(n - 1);
        }
    }

    public int fibonacci(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }
    }

    public int findMax1(int[] a, int left, int right) {
        int maxpart;
        if (left == right) {
            return a[left];
        } else {
            maxpart = findMax1(a, left + 1, right);
            if (a[left] > maxpart) {
                return a[left];
            } else {
                return maxpart;
            }
        }
    }

    public int findMax(int left, int[] a, int right) {
        int max = a[left];
        int currLoc = left + 1;
        while (currLoc <= right) {
            if (max < a[currLoc]) {
                max = a[currLoc];
            }
            currLoc++;
        }
        return max;
    }

    public void printReverse(char[] s, int from) {
        if (from < s.length) {
            printReverse(s, from + 1);
            System.out.println(s[from]);
        }
    }

    public int findMax2(int[] a, int left, int right) {
        int maxleft;
        int maxRight;
        int mid;

        if (left == right) {
            return a[left];
        } else {
            mid = (left + right) / 2;
            maxleft = findMax2(a, left, mid);
            maxRight = findMax2(a, mid + 1, right);
            if (maxleft >= maxRight) {
                return maxleft;
            } else {
                return maxRight;
            }
        }
    }

    private void quickRecursively(int[] a, int left, int right) {
        if (left < right) {
            int mid = partition(a, left, right);
            quickRecursively(a, left, mid - 1);
            quickRecursively(a, mid + 1, right);
        }
    }

    private int partition(int[] a, int left, int right) {
        int pivot = left;
        int toRight = left;
        int toLeft = right + 1;
        do {
            do {
                toRight++;
            } while (a[toRight] > a[pivot]);
            do {
                toLeft--;
            } while (a[toLeft] < a[pivot]);
            if (toRight < toLeft) {
                swap(a, toRight, toLeft);
            }
        } while (toRight < toLeft);
        swap(a, left, toLeft);
        return toLeft;
    }

    public void swap(int[] a, int left, int right) {
        int temp = a[left];
        a[left] = a[right];
        a[right] = temp;
    }
}
