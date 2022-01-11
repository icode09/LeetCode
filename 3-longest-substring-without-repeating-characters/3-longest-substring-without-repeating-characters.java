class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character,Integer> hashMap = new HashMap<>();
        int begin = 0 ,end = 0;
        int counter = 0;
        int maxLength = 0;
        while(end < s.length()){
            char windowEndChar = s.charAt(end);
            hashMap.put(windowEndChar,hashMap.getOrDefault(windowEndChar,0) + 1);
            if(hashMap.get(windowEndChar) > 1) counter++;

            end++;


            while(counter > 0){
                char windowStartChar = s.charAt(begin);
                if(hashMap.get(windowStartChar) > 1) counter--;
                hashMap.put(windowStartChar , hashMap.get(windowStartChar) - 1);
                begin++;
            }

            maxLength = Math.max(maxLength , end - begin);
        }

        return maxLength;
    }
}