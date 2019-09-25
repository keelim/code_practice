package L;

import javax.swing.tree.TreeNode;

class L938 {
    public int rangeSumBST(TreeNode root, int L, int R) {
        int sum = 0;
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
