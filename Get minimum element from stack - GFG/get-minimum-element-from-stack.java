// { Driver Code Starts
import java.util.*;



class Get_Min_From_Stack
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while(T>0)
		{
			int q = sc.nextInt();
			GfG g = new GfG();
			while(q>0)
			{
				int qt = sc.nextInt();
				
				if(qt == 1)
				{
					int att = sc.nextInt();
					g.push(att);
					//System.out.println(att);
				}
				else if(qt == 2)
				{
					System.out.print(g.pop()+" ");
				}
				else if(qt == 3)
				{
					System.out.print(g.getMin()+" ");
				}
			
			q--;
			}
			System.out.println();
		T--;
		}
		
	}
}


// } Driver Code Ends

class Node{
    int val;
    int minEle;
    Node next;
    
    Node(int val , int minEle , Node next){
        this.val = val;
        this.minEle = minEle;
        this.next = next;
    }
}
class GfG
{
    
    Node head;
    
    GfG(){
        head = null;
    }


    /*returns min element from stack*/
    int getMin()
    {
	// Your code here
	if(head != null){
	    return head.minEle;
	}
	    return -1;
    }
    
    /*returns poped element from stack*/
    int pop()
    {
	// Your code here
	    if(head != null){
	         int val = head.val;
	    head = head.next;
	    return val;
	    }
	   return -1;
    }

    /*push element x into the stack*/
    void push(int x)
    {
	// Your code here	
	    if(head == null){
	        head = new Node(x,x,null);
	    }else{
	        head = new Node(x,Math.min(x,head.minEle) , head);
	    }
    }	
}

