package practice_code;

public class Recursion<E> {
    //    factorial
    public int factorial(int n) {
        if (n == 1) {
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    }

    //    fibonacci
    public int fibonacci(int n) {
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        } else {
            return fibonacci(n - 1) + fibonacci(n - 2);
        }


    }

    public void printreverse(char[] a, int from) {
        if (from < a.length) {
            printreverse(a, from + 1);
            System.out.println(a);
        }
    }

    public int findMax(int[] a, int left, int right) {
        if (left == right) {
            return a[left];
        } else {
            int findMax = findMax(a, left + 1, right);
            if (a[left] >= findMax) {
                return a[left];
            } else {
                return findMax;
            }
        }
    }

    public int findMax2(int[] a, int left, int right) {
        if (left == right) {
            return a[left];
        } else {
            int mid = (left + right) / 2;
            int maxLeft = findMax2(a, left, mid);
            int maxRight = findMax2(a, mid + 1, right);
            if (maxLeft >= maxRight) {
                return maxLeft;
            } else {
                return maxRight;
            }
        }
    }

    public int findMax3(int[] a, int left, int right) {
        int culloc = left;
        int max = a[left];

        culloc = left + 1;
        while (culloc <= right) {
            if (max < a[culloc]) {
                max = a[culloc];

            }
            culloc++;

        }
        return max;

    }

    public void quickSort(int[] a, int left, int right){
        quickRecurively(a, left, right);
    }

    private void quickRecurively(int[] a, int left, int right) {
        if(left<right){
            int mid = partition(a, left, right);
            quickRecurively(a, left, mid-1);
            quickRecurively(a, mid+1, right);
        }
    }

    private int partition(int[] a, int left, int right) {
        int pivot=left;
        int toRight = left;
        int toLeft = right+1;

        do {
            do{toLeft--;} while(a[toLeft]>a[pivot]);
            do{toRight++;} while(a[toRight]<a[pivot]);
            if(toRight<toLeft){
                swap(a, toLeft, toRight);
            }

        } while (toRight<toLeft);
        swap(a, left, toLeft);
        return toLeft;
    }

    private void swap(int[] a, int toLeft, int toRight) {
        int temp = a[toLeft];
        a[toLeft] = a[toRight];
        a[toRight] = temp;
    }


}


