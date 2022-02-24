struct Node{
  int key,value;
    Node* next;
    
    Node(int key,int value){
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};
class MyHashMap {
public:
    vector<Node*> buckets = vector<Node*>(10000, new Node(-1,-1));
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        int idx = getIndex(key);
        Node* prev = findPrev(buckets[idx],key);
        if(!prev->next)
            prev->next = new Node(key,value);
        else 
            prev->next->value = value;
    }
    
    int get(int key) {
        int idx = getIndex(key);
        Node* prev = findPrev(buckets[idx],key);
        if(prev && prev->next)
            return prev->next->value;
        
        return -1;
    }
    
    void remove(int key) {
        int idx = getIndex(key);
        Node* prev = findPrev(buckets[idx],key);
        if(prev && prev->next){
            Node* temp = prev->next;
            prev->next = prev->next->next;
            temp->next = NULL;
            delete temp;
        }
    }
    
    int getIndex(int key){
        return key%10000;
    }
    
    Node* findPrev(Node* head, int key){
        Node* curr = head, *prev = NULL;
        while(curr && curr->key != key){
            prev = curr;
            curr = curr->next;
        }
        
        return prev;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */