package Hackers;

import java.util.*;

public class SockMerchant {
    static int sockMerchant(int n, int[] ar) {
        int answer = 0;
        Set<Integer> answerSet = new HashSet<>();
        for(int element : ar){
            answerSet.add(element);
        }
        Map<Integer, Integer> answerMap = new HashMap<>(); //set을 만든다.


        for(int temp : answerSet){
            int count = 0;
            for (int i = 0; i < ar.length; i++) {
                if(ar[i] == temp){
                    count++;
                }
            }
            answerMap.put(temp, count);
        } //map을 만든다.

        for(int temp : answerSet){
            int temp_pair_count = answerMap.get(temp); //개수를 가지고 순회를 돈다.
            answer+= temp_pair_count/2; //2로 나누어 pair를 저장하고 결과값을 준다.
        }
        return answer;
    }
}
