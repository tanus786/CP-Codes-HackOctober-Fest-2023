import java.io.*;
import java.util.*;
class Node{
    Node left,right;
    int data;
    Node(int data){
        this.data=data;
        left=right=null;
    }
}
class Solution{

	static void levelOrder(Node root){
        List<Integer> kk=new ArrayList<>();
        Queue<Node> nm=new LinkedList<>();
        if(root==null)
        {
            return;
        }
        nm.offer(root);
        while(!nm.isEmpty())
        {
            int k=nm.size();
            for(int i=0;i<k;i++)
            {
                if(nm.peek().left!=null)
                {
                    nm.offer(nm.peek().left);
                }
                if(nm.peek().right!=null)
                {
                    nm.offer(nm.peek().right);
                }
                kk.add(nm.poll().data);
            }
        }
        for(int i=0;i<kk.size();i++)
        {
            System.out.print(kk.get(i)+" ");
        }
    }

	public static Node insert(Node root,int data){
        if(root==null){
            return new Node(data);
        }
        else{
            Node cur;
            if(data<=root.data){
                cur=insert(root.left,data);
                root.left=cur;
            }
            else{
                cur=insert(root.right,data);
                root.right=cur;
            }
            return root;
        }
    }
    public static void main(String args[]){
            Scanner sc=new Scanner(System.in);
            int T=sc.nextInt();
            Node root=null;
            while(T-->0){
                int data=sc.nextInt();
                root=insert(root,data);
            }
            levelOrder(root);
        }	
}