import java.util.Scanner;

public class Main {
    static int num = 0;
    static int[][] graph;
    static int[][] visited;
    static int dx[] = { -1, 1, 0, 0 };
    static int dy[] = { 0, 0, -1, 1 };

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cnt = 0;
        int max_val = 0;
        num = sc.nextInt();
        graph = new int[num][num];

        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                graph[i][j] = sc.nextInt();
                if (max_val < graph[i][j])
                    max_val = graph[i][j];
            }
        }
        int max_cnt = 1;

        for (int k = 1; k <= max_val; k++) {
            cnt = 0;
            visited = new int[num][num];
            for (int i = 0; i < num; i++) {
                for (int j = 0; j < num; j++) {
                    if (graph[i][j] >= k && visited[i][j] == 0) {
                        cnt++;
                        dfs(i, j, k);
                    }
                }
            }
            if (max_cnt < cnt)
                max_cnt = cnt;
        }
        System.out.println(max_cnt);
    }

    static void dfs(int x, int y, int aux) {
        visited[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= num || ny < 0 || ny >= num)
                continue;
            if (visited[nx][ny] == 0 && graph[nx][ny] >= aux) {
                dfs(nx, ny, aux);
            }

        }
    }

}
