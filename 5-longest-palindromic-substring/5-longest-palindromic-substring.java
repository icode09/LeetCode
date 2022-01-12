class Solution {
    public String longestPalindrome(String targetString) {
        int n = targetString.length();
        if(n == 0) return "";
        if(n == 1) return String.valueOf(targetString.charAt(0));
        int ls = 0 ,le = 0 , lPal = 1;
        for(int i = 0;i<n;i++){
            //  odd length palindrome
            int left = i - 1;
            int right = i + 1;
            int pal = 1;
            while(left >= 0 && right < n && targetString.charAt(left) == targetString.charAt(right)){
                pal += 2;
                if(pal > lPal){
                    lPal = pal;
                    ls = left;
                    le = right;
                }
                left--;
                right++;
            }

            // even length
            left = i;
            right = i + 1;
            pal = 0;
            while(left >= 0 && right < n && targetString.charAt(left) == targetString.charAt(right)){
                pal+=2;
                if(pal > lPal){
                    lPal = pal;
                    ls = left;
                    le = right;
                }
                left-- ; right++;
            }
        }
       return targetString.substring(ls,le+1);
    }
}