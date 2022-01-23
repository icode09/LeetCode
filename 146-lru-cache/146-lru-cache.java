class DoublyLinkedListNode{
    DoublyLinkedListNode next;
    DoublyLinkedListNode prev;
    int key, value;

    public DoublyLinkedListNode(int key, int value) {
        this.key = key;
        this.value = value;
    }
}
class LRUCache{
    HashMap<Integer,DoublyLinkedListNode> hashMap;
    int capacity;
    DoublyLinkedListNode head;
    DoublyLinkedListNode tail;

    public LRUCache(int capacity) {
        hashMap = new HashMap<>();
        this.capacity = capacity;
        head = new DoublyLinkedListNode(-1,-1);
        tail = new DoublyLinkedListNode(-1,-1);

        head.next = tail;
        tail.prev = head;
    }
    public int get(int key) {
        if(hashMap.containsKey(key)){
            DoublyLinkedListNode node = hashMap.get(key);
            removeNode(node);
            insertAtBegin(node);
            return node.value;
        }
        else{
            return -1;
        }
    }

    public void put(int key, int value) {
        if(hashMap.containsKey(key)){
            removeNode(hashMap.get(key));
        }
        if(hashMap.size() == capacity){
            removeNode(tail.prev);
        }
        insertAtBegin(new DoublyLinkedListNode(key,value));
    }
    /*
    * This will remove the node
    * */
    private void removeNode(DoublyLinkedListNode node){
        hashMap.remove(node.key);
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }
    /*
    * This will insert Node after head node.
    * */
    private void insertAtBegin(DoublyLinkedListNode node){
        hashMap.put(node.key,node);
        node.next = head.next;
        head.next.prev = node;
        node.prev = head;
        head.next = node;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */



