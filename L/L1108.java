package L;


class L1108 {
    public static String defangIPaddr(String address) {
        String[] split = address.split("\\.");
        StringBuilder answer = new StringBuilder();

        for(int i=0; i<split.length;i++){
            answer.append(split[i]);
            if(split.length-1 != i){
                answer.append("[.]");
            }
        }
        return answer.toString();
    }

}
