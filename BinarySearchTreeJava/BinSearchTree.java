public class BinaryTrees {
    public static void main(String [] args) {

        BinarySearchTree binarySearchTree = new BinarySearchTree(1);


    }
}

class BinarySearchTree {

    // the base class init ing the binary search tree
    class Node {
        protected Node right;
        protected int data;
        protected Node left;

        public Node(int data) {
            this.left = null;
            this.data = data;
            this.right = null;
        }
    }
    protected Node root;

    public BinarySearchTree(int root) {
        this.root = new Node(root);
    }

    public BinarySearchTree() {
        this.root = null;
    }

    protected Node insertNewNode(Node root, int data) {
        if (root == null ) {
            root = new Node(data);
            return root;
        }

        else if (data < root.data) {
                root.left = insertNewNode(root.left, data);
        }

        else if (data > root.data) {
            root.right = insertNewNode(root.right, data);
        }

        return root;
    }

    protected Node deleteRecursive(Node current, int data) {
        if (current == null)
            return null;

        if ( data < current.data) {
            current.left = deleteRecursive(current.left, data);
            return current;
        }

        else if (data > current.data) {
            current.right = deleteRecursive(current.right, data);
            return current;
        }
        else {
            if (current.left == null)
                return current.right;
            else if (current.right == null)
                return current.left;
            int min = min(current);
            current.right = deleteRecursive(current.right, current.data);

        }
        return current;
    }

    protected int min(Node root) {
        int min = root.data;

        while (root.left != null) {
            min = root.left.data;
            root = root.left;
        }
        return min;
    }

    protected int max(Node root) {
        int max = root.data;

        while (root.right != null ) {
            max = root.right.data;
            root = root.right;
        }
        return max;
    }

    protected void inOrder(Node root) {
        if (root != null) {
            inOrder(root.left);
            System.out.print("\n" + root.data);
            inOrder(root.right);
        }
    }

    protected void preOrder(Node root) {
        if (root != null ) {
            System.out.print("\n " + root.data);
            preOrder(root.left);
            preOrder(root.right);
        }
    }

    protected void postOrder(Node root) {
        if (root != null) {
            postOrder(root.left);
            postOrder(root.right);
            System.out.print("\n " + root.data);
        }
    }

    boolean search(int key)  {
        root = search_Recursive(root, key);
        return root != null;
    }

    //recursive insert function
    Node search_Recursive(Node root, int key)  {
        // Base Cases: root is null or key is present at root
        if (root==null || root.data==key)
            return root;
        // val is greater than root's key
        if (root.data > key)
            return search_Recursive(root.left, key);
        // val is less than root's key
        return search_Recursive(root.right, key);
    }
}