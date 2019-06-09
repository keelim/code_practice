package src.H;

import java.util.LinkedList;
import java.util.Queue;

public class Tree {
}


class Node {
    Node left;
    Node right;
    int data;



    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class Solution {

    /*

    class Node
        int data;
        Node left;
        Node right;
    */
    public static void levelOrder(Node root) {
        Queue<Node> queue = new LinkedList<>();
        queue.add(root);
        Node nextNode;
        while (!queue.isEmpty()) {
            nextNode = queue.remove();
            System.out.print(nextNode.data + " ");
            if (nextNode.left != null) {
                queue.add(nextNode.left);
            }
            if (nextNode.right != null) {
                queue.add(nextNode.right);
            }
        }
    }
}
