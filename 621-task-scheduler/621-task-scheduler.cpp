class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int counter[26] = {0};
        for(int i = 0;i<tasks.size();i++){
            counter[tasks[i] - 'A']++;
        }
        
        priority_queue<int> pq;
        for(int i = 0;i<26;i++){
            if(counter[i])
                pq.push(counter[i]);
        }
        int time = 0;
        while(!pq.empty()){
            int all = n + 1;
            vector<int> remaining;
            
            while(all && !pq.empty()){
                int counter = pq.top();
                pq.pop();
                
                counter--;
                
                if(counter)
                    remaining.push_back(counter);
                
                all--;
                time++;
            }
            
            for(auto val : remaining){
                pq.push(val);
            }
            
            if(pq.empty()) break;
            
            time += all;
        }
        
        return time;
    }
};