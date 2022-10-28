// Program of deleting a  node from circular linked list......
public class Main {  
      
    public class Node{  
        int info;  
        Node next;  
        public Node(int info) {  
            this.info = info;  
        }  
    }  
  
    
    public Node head = null;  
    public Node tail = null;  
  
    
    public void Add(int info){  
        
        Node newNode = new Node(info);  
    
        if(head== null) {  
             
            head = newNode;  
            tail = newNode;  
            newNode.next = head;  
        }  
        else {  
            
            tail.next = newNode;  
    
            tail = newNode;  
        
            tail.next = head;  
        }  
    }  
  

    public void DeleteEnd() {  

        if(head== null) {  
            return;  
        }  
        else {  
            
            if(head != tail ) {  
                Node current = head;  
                
                while(current.next != tail) {  
                    current = current.next;  
                }  
    
                tail = current;  
        
                tail.next = head;  
            }  
        
            else {  
                head= tail = null;  
            }  
        }  
    }  
  
    
    public void display() {  
        Node current = head;  
        if(head == null) {  
            System.out.println("List is empty");  
        }  
        else {  
             do{  
            
                System.out.print(" "+ current.info);  
                current = current.next;  
            }while(current != head);  
            System.out.println();  
        }  
    }  
  
    public static void main(String[] args) {  
        DeleteEnd obj = new DeleteEnd();  

        obj.add(1);  
        obj.add(2);  
        obj.add(3);  
        obj.add(4);  
        //Printing original list  
        System.out.println("Original List: ");  
        obj.display();  
        while(obj.head!= null) {  
            obj.deleteEnd();  
            //Printing updated list  
            System.out.println("Updated List: ");  
            obj.display();  
        }  
    }  
}  
