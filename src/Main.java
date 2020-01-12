import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    static int node, edge, answer;
    static ArrayList<Integer>[] graph;
    static boolean[] visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        node = sc.nextInt();
        edge = sc.nextInt();

        graph = new ArrayList[node+1];

        for (int i = 1; i <= node; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < edge; i++) {
            int head = sc.nextInt(), tail = sc.nextInt();
            graph[head].add(tail);
            graph[tail].add(head);
        }

        for (int i = 1; i <= node; i++) {
            Collections.sort(graph[i]);
        }
        // 초기화
        visited = new boolean[node+1];
        for (int i = 1; i <= node; i++) {
            visited[i] = false;
        }

        for (int i = 1; i <= node ; i++) {
            if(!visited[i]){
                dfs(i);
                answer++;
            }
        }
        System.out.println(answer);
    }

    static void dfs(int x){
        visited[x] = true;

        for(int y: graph[x]){
            if(!visited[y]) dfs(y);
        }
    }

}