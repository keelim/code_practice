import java.util.*;

public class Main {
    static int max = 51;
    static int[][] map = new int[max][max];
    static boolean[][] visited = new boolean[max][max];
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};
    static int count,testCase, ;

    static void dfs(int x, int y) {
        visited[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int next_x = x + dx[i];
            int next_y = y + dy[i];

//            if() //범위 체크
            if (map[next_x][next_y] == 1 && !visited[next_x][next_y]){
                dfs(next_x,next_y);
            }
        }
    }

    static void init(){

    }

    public static void main(String[] args) {

    }
}
