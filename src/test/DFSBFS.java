package test;

import java.util.*;

public class DFSBFS {
    static boolean visited[];
    static ArrayList<Integer>[] adj;
    static Queue<Integer> Q; // BFS에서 사용하는 것

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int node = sc.nextInt(), edge = sc.nextInt(), start = sc.nextInt();
        adj = new ArrayList[node + 1];
        for (int i = 1; i <= node; i++) {
            adj[i] = new ArrayList<>();
        }

        for (int i = 0; i < edge; i++) {
            int head = sc.nextInt(), tail = sc.nextInt();
            adj[head].add(tail);
            adj[tail].add(head);
        } //초기화

        for (int i = 1; i <= node; i++) Collections.sort(adj[i]);
        visited = new boolean[node + 1];
        Q = new LinkedList<>();
        DFS(start);
        System.out.println();
        reset(node);
        BFS(start);
        System.out.println();
        sc.close();
    }

    static void DFS(int x) { //깊이 우선 탐색
        visited[x] = true;
        System.out.print(x + " ");
        for (int y : adj[x]) {
            if (!visited[y]) {
                DFS(y);

            }
        }
    }

    static void BFS(int x) { //코드 엄청 간단하다.
        Q.add(x);
        visited[x] = true;
        while (!Q.isEmpty()) {
            int element = Q.poll();
            System.out.print(element + " ");
            for (int y : adj[x]) {
                if (!visited[y]) {
                    visited[y] = true;
                    Q.add(y);
                }
            }
        }
    }

    static void reset(int n) {
        for (int i = 1; i <= n; i++) {
            visited[i] = false;
        }
    }


}
