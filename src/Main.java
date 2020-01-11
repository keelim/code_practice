import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    static ArrayList<Integer>[] graph; // 양방향 그래프
    static boolean[] visited; // 노드 기준
    static int answer = 0;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int node = sc.nextInt(), edge = sc.nextInt(), start = 1;
        graph = new ArrayList[node + 1];

        for (int i = 1; i < node + 1; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < edge; i++) {
            int head = sc.nextInt(), tail = sc.nextInt();

            graph[head].add(tail);
            graph[tail].add(head);
        }

        for (int i = 1; i < node + 1; i++) {
            Collections.sort(graph[i]);
        }

        visited = new boolean[node + 1];
        dfs(start);
        System.out.println(answer - 1);

    }

    static void dfs(int start) {
        if (visited[start])
            return;

        visited[start] = true;
        answer++;
        for (int y : graph[start]) {
            if (!visited[y])
                dfs(y);
        }
    }
}