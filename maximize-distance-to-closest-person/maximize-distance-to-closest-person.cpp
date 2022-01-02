class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int last = -1 , maxDistance = INT_MIN;
        int n = seats.size();
        for(int i = 0;i<n;i++){
            if(seats[i]){
                maxDistance = (last < 0) ? i : max(maxDistance , (i - last)/2);
                last = i;
            }
        }
        maxDistance = max(maxDistance , n - last - 1);
        return maxDistance;
    }
};