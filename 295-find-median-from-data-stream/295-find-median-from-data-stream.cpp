class MedianFinder {
public:
    priority_queue<int> smaller;
    priority_queue<int,vector<int>,greater<int>> greater;
    MedianFinder() {
        
    }
     void addNum(int num) {
        if(smaller.empty()){
            smaller.push(num);
            return;
        }
        
        if(smaller.size() > greater.size()){
            if(num < smaller.top()){
                greater.push(smaller.top());
                smaller.pop();
                smaller.push(num);
            }
            else 
                greater.push(num);
        }
        else{
            if(num <= smaller.top())
                smaller.push(num);
            else{
                greater.push(num);
                smaller.push(greater.top());
                greater.pop();
            }
        }
    }
    
    double findMedian() {
        if(smaller.size() > greater.size()) return (double)smaller.top();
        else{
            return (smaller.top() + greater.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */