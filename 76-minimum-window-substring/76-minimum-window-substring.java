class Solution {
    public String minWindow(String s, String p) {
       if(p.length() > s.length()) return "";

        HashMap<Character,Integer> hashMap = new HashMap<>();
        for(char ch: p.toCharArray()){
            hashMap.put(ch,hashMap.getOrDefault(ch,0) + 1);
        }

        int begin = 0 , end = 0;
        int counter = hashMap.size();
        int minStart = 0 , minLength = Integer.MAX_VALUE;

        while(end < s.length()){
            char windowEndChar = s.charAt(end);
            if(hashMap.containsKey(windowEndChar)){
                hashMap.put(windowEndChar,hashMap.get(windowEndChar) - 1);
                if(hashMap.get(windowEndChar) == 0){
                    counter--;
                }
            }
            end++;

            while(counter == 0){
                char windowBeginChar = s.charAt(begin);
                if(hashMap.containsKey(windowBeginChar)){
                    hashMap.put(windowBeginChar,hashMap.get(windowBeginChar) + 1);
                    if(hashMap.get(windowBeginChar) > 0){
                        counter++;
                    }
                }
                if(end - begin < minLength){
                    minStart = begin;
                    minLength = end - begin;
                }
                begin++;
            }
        }
        if(minLength == Integer.MAX_VALUE) return "";
        return s.substring(minStart, minLength + minStart);
    }
}