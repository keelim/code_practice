package L;

import java.util.ArrayList;

class L_500 {
    public String[] findWords(String[] words) {
        String[] answer = new String[0];

        String[] allow_array = new String[] {"A", "S", "D", "F", "G", "H", "J", "K","L",
                "a", "s", "d", "f", "g", "h", "j", "k", "l"};

        ArrayList<String> arrayList = new ArrayList<>();
        ArrayList<String> word_list = new ArrayList<>();

        for(String allow : allow_array)
            arrayList.add(allow);


        for(String word : words)
            word_list.add(word);


        return answer;
    }

    public static void main(String[] args) {
        L_500 l_500 = new L_500();
        l_500.findWords(new String[] {"Hello", "Alaska","Dad", "Peace" });


    }
}