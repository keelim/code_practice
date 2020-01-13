import java.util.*;

public class Main {

    static int[][] array;
    static boolean[][] visited;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};
    static int first;
    static int second;

    public static void main(String args[]) throws Exception {
        // Scanner sc = new Scanner(System.in);
        Scanner sc = new Scanner(System.in);

        first = sc.nextInt();
        second = sc.nextInt();
        sc.nextLine();
        array = new int[first][second];
        visited = new boolean[first][second];
        for (int i = 0; i < first; i++) {
            String str = sc.nextLine();
            for (int j = 0; j < second; j++) {
                array[i][j] = str.charAt(j) - '0';
                visited[i][j] = false;
            }
        }
        visited[0][0] = true;
        BFS(0, 0);
        System.out.println(array[first - 1][second - 1]);
    }

    static public void BFS(int x, int y) {

        Queue<Dot> q = new LinkedList<Dot>();
        q.add(new Dot(x, y));
        //큐가 끝날때 까지
        while (!q.isEmpty()) {
            Dot d = q.poll();
            for (int i = 0; i < 4; i++) {
                //다음 방문할 좌표 nextX, nextY
                int nextX = d.x + dx[i];
                int nextY = d.y + dy[i];

                //다음 좌표가 범위를 넘어갈때 건너뛰기
                if (nextX < 0 || nextY < 0 || nextX >= first || nextY >= second) {
                    continue;
                }
                //이미 방문했던 점이면 건너뛰기
                if (visited[nextX][nextY] || array[nextX][nextY] == 0) {
                    continue;
                }
                //다음에 방문할 좌표를 큐에 넣는다.
                q.add(new Dot(nextX, nextY));
                //배열안에 다음 방문할 곳은 현재 방문했던 점보다 1칸 더 가야하므로 +1
                array[nextX][nextY] = array[d.x][d.y] + 1;
                //다음 좌표는 방문했음으로 표시
                visited[nextX][nextY] = true;
            }
        }
    }
}

class Dot {
    int x;
    int y;

    Dot(int x, int y) {
        this.x = x;
        this.y = y;
    }
}