class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};
        int elementsHavingMaxFreq = 0;
        int maxFreq = 0;
        for(int i = 0;i<tasks.size();i++){
            freq[tasks[i] - 'A']++;
            if(maxFreq == freq[tasks[i] - 'A']){
                elementsHavingMaxFreq++;
            }
            else if(maxFreq < freq[tasks[i] - 'A']){
                maxFreq = freq[tasks[i] - 'A'];
                elementsHavingMaxFreq = 1;
            }
        }
        // cout<<maxFreq<<" "<<elementsHavingMaxFreq<<endl;
        
        int partCount = maxFreq - 1;
        int partLength = n - (elementsHavingMaxFreq - 1);
        int totalEmptySlots = partCount*partLength;
        int availableTasks = tasks.size() - elementsHavingMaxFreq*maxFreq;
        
        int idles = max(0, totalEmptySlots - availableTasks);
        
        return tasks.size() + idles;
        
    }
};

