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

    public int findMax(int[] a, int left, int right) {
        int maxOfPart;
        if (left == right) {
            return a[left];
        } else {
            maxOfPart = findMax(a, left + 1, right);
            if (a[left] >= maxOfPart) {
                return a[left];
            } else {
                return maxOfPart;
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

    public void printlnReverse(char[] s, int from) {
        printlnReverse(s, from + 1);
        System.out.println(s[from]);
    }

    public int findMax2(int[] a, int left, int right) {
        int maxLeft;
        int maxRight;
        int mid;
        if (left == right) {
            return a[left];
        } else {
            mid = (left + right) / 2;
            maxLeft = findMax2(a, left, mid);
            maxRight = findMax2(a, mid + 1, right);
            if (maxLeft >= maxRight) {
                return maxLeft;
            } else {
                return maxRight;
            }
        }
    }

    public void quickSort(int[] a, int left, int right) {
        quickRecursively(a, left, right);
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
            } while (a[toRight] < a[pivot]);
            do {
                toLeft--;
            } while (a[toLeft] > a[pivot]);
            if (toRight < toLeft) {
                swap(a, toLeft, toRight);
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