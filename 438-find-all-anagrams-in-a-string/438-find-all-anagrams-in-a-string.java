class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> result = new LinkedList<>();
        if(p.length() > s.length()) return result;

        HashMap<Character,Integer> hashMap = new HashMap<>();
        for(char ch : p.toCharArray()){
            hashMap.put(ch , hashMap.getOrDefault(ch , 0) + 1);
        }

        int begin = 0 , end = 0 ;
        int counter = hashMap.size();

        while(end < s.length()){
            char ch = s.charAt(end);
            if(hashMap.containsKey(ch)){
                hashMap.put(ch,hashMap.get(ch) - 1);
                if(hashMap.get(ch) == 0) counter--;
            }
            end++;

            while(counter == 0){
                char startWindow = s.charAt(begin);
                if(hashMap.containsKey(startWindow)){
                    hashMap.put(startWindow,hashMap.get(startWindow) + 1);
                    if(hashMap.get(startWindow) > 0){
                        counter++;
                    }
                }
                if(end - begin == p.length()){
                    result.add(begin);
                }
                begin++;
            }
        }
        return result;
    }
}