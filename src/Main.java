import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int first;
    static int second;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    static int[][] graph;
    static boolean[][] visited;
    static int wall;
    static Queue<Pair<Integer, Integer>> queue;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        first = sc.nextInt();
        second = sc.nextInt();

        graph = new int[first][second];
        visited = new boolean[first][second];

        for (int i = first - 1; i >= 0; i--) {
            String[] temp = sc.next().split("");
            for (int j = 0; j < second; j++) {
                graph[i][j] = Integer.parseInt(temp[j]);
            }
        } // 그래프 초기화

        bfs();
        System.out.println(wall);
    }

    static void bfs() {
        queue = new LinkedList<>();

        queue.add(new Pair(0, 0));

        while (!queue.isEmpty()) {
            Pair<Integer, Integer> element = queue.poll();
            visited[element.left][element.right] = true;
            for (int i = 0; i < 4; i++) {
                int nx = element.left + dx[i];
                int ny = element.right + dy[i];

                if (nx < 0 || nx >= first || ny < 0 || ny >= second) continue;
                if (visited[nx][ny]) continue;

                queue.add(new Pair<>(nx, ny));
            }
        }
    }

    static class Pair<L, R> {
        L left;
        R right;

        public Pair(L left, R right) {
            this.left = left;
            this.right = right;
        }
    }
}