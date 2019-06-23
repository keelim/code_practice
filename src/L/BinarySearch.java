package L; //BinartSearch


import H.Queue;
import jdk.nashorn.internal.ir.BinaryNode;

import java.util.LinkedList;

public class BinarySearch {

}

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class L938 {
    public int rangeSumBST(TreeNode root, int L, int R) {
        int sum = 0;
        if (root != null) {
            sum += this.rangeSumBST(root.left, L, R);
            sum += this.visit(root.val, L, R);
            sum += this.rangeSumBST(root.right, L, R);

        }
        return sum;
    }

    private int visit(int val, int L, int R) {
        int answer = 0;
        if (val >= L && val <= R) {
            answer = val;
        }
        return answer;
    }
}

class L700 {
    public TreeNode searchBST(TreeNode root, int val) {
        if (root == null)
            return root;
        if (root.val == val)
            return root;
        else if (root.val > val)
            return searchBST(root.left, val);
        else if (root.val < val)
            return searchBST(root.right, val);
        return null;
    }
}

