Node* reverseDLL(Node * head)
{
    //Your code here
    Node* temp = head; //used for traversing
    Node* ptr =NULL; //used in swapping
    while(temp)
    {
        
           ptr = temp->prev;
           temp->prev = temp->next; //swap prev and next of each node
           temp->next = ptr;
           head = temp; //point head to each node you encounter along the way till the last node
           temp = temp->prev;
          
    }
    
    return head;
}
