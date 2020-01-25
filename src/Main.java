import java.util.Queue;
import java.util.Scanner;

public class Main{
    static int[] dx = {1,-1,0,0};
    static int[] dy = {0,0,1,-1};
    static int[][] graph;
    static boolean[][] visited;
    static int num;
    static Queue<Data> queue;
    static int max = 0;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        num = sc.nextInt();

        graph = new int[num][num];
        visited = new boolean[num][num];

        for (int i = 0; i < num; i++) {
            for (int j = 0; j < num; j++) {
                int temp = sc.nextInt();
                if(temp>=max) max = temp;
                graph[i][j] = temp;
                visited[i][j] = false;
            }
        } //최대값 구함

        for (int i = 2; i <= max; i++) {
            for (int j = 0; j < num; j++) {
                for (int k = 0; k < num; k++) {
                    if(!visited[j][k]){
                        bfs(j,k);
                    }
                }
            }

        }
    }

    class Data{
        int x;
        int y;
        Data(int x, int y){
            this.x = x;
            this.y = y;
        }
    }
}