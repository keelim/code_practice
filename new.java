class Solution {
    public int maxScore(int[] cardPoints, int k) {
        int answer1 = 0;
        int answer2 = 0;
        int final_answer = 0;

        //first 
        for(int i=0;i<k;i++) answer1 += cardPoints[i];

        for(int i= cardPoints.length-1;i>cardPoints.length-k-1;i--) answer2 += cardPoints[i];

        final_answer = (answer1>=answer2) ? answer1:answer2;
        
    }
}