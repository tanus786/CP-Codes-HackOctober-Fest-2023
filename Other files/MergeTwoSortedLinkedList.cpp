// problem from GFG SDE sheet : https://practice.geeksforgeeks.org/problems/merge-two-sorted-linked-lists/1

// Solution: 
// Time complexity: O(n+m)

Node* sortedMerge(Node* head1, Node* head2)  
{  
    Node *ptr = new Node(0);
        Node *curr = ptr;
        
        while(head1 != NULL && head2 != NULL)
        {
            if(head1->data <= head2->data)
            {
                curr -> next = head1;
                head1 = head1 -> next;
            }
            else
            {
                curr -> next = head2;
                head2 = head2 -> next;
            }
        curr = curr ->next;
        }
        
        if(head1 != NULL)
        {
            curr -> next = head1;
            head1 = head1->next;
        }
        if(head2 != NULL)
        {
            curr -> next = head2;
            head2 = head2 ->next;
        }
        return ptr->next;
}  