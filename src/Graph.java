public class Graph {


    private void dfs(int tailVertex) { //matrix
        this._visited[tailVertex] = true;
        this.visit(tailVertex);
        for (int headVertex = 0;
             headVertex < this._numberOfVertices; headVertex++) {
            if (this._adjacency[tailVertex][headVertex] != 0
                    && !this._visited[headVertex]) {
                this.dfs(headVertex);
            }
        }
    }

    private void dfs(int tailVertex) {
        int headVertex;
        this._visited[tailVertex] = true;
        this.visit(tailVertex);
        Node adjacentNode = this._adjacency[tailVertex];
        while (adjacentNode != null) {
            headVertex = adjacentNode.vertex();
            if (!this._visited[headVertex]) {
                dfs(headVertex);
            }
            adjacentNode = adjacentNode.next();
        }
    }
}
