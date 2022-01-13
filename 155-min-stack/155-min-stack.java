class Node{
    Node next;
    int val;
    int minElement;

    public Node(int val,int minElement,Node next){
        this.minElement = minElement;
        this.val = val;
        this.next = next;
    }
}
class MinStack{

    private Node head;

    public MinStack() {
        head = null;
    }

    public void push(int val) {
        if(head == null)
            head = new Node(val,val, null);
        else
            head = new Node(val,Math.min(val,head.minElement), head);
    }

    public void pop() {
        head = head.next;
    }

    public int top() {
        return head.val;
    }

    public int getMin() {
        return head.minElement;
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(val);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */