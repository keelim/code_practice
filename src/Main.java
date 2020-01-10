import java.util.*;

public class Main {
    static ArrayList<Integer>[] graph;
    static boolean[] visited;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int node = sc.nextInt(), edge = sc.nextInt(), start = sc.nextInt();
        graph = new ArrayList[node + 1]; // 그래프 만들기 ArrayList으로 이루어진 배열

        for (int i = 1; i < node + 1; i++) { //배열안에 객체 생성
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < edge; i++) { //그래프 초기화
            int head = sc.nextInt(), tail = sc.nextInt();

            graph[head].add(tail);
            graph[tail].add(head);
        }
        for (int i = 1; i < node + 1; i++) { //그래프 정렬
            Collections.sort(graph[i]);
        }
        visited = new boolean[node + 1];
        dfs(start);
        System.out.println();

        visited = new boolean[node + 1];
        bfs(start);
        System.out.println();
    }

    private static void dfs(int x) { //깊이 탐색
        if (visited[x]) {
            return;
        }
        visited[x] = true;
        System.out.print(x + " ");
        for (int y : graph[x]) {
            if (!visited[y])
                dfs(y);
        }

    }

    private static void bfs(int start) { //너비 탐색
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        visited[start] = true;
        while (!queue.isEmpty()) {
            int x = queue.poll();
            System.out.print(x + " ");
            for (int y : graph[x]) {
                if (!visited[y]) {
                    visited[y] = true;
                    queue.add(y);
                }
            }
        }
    }
}
