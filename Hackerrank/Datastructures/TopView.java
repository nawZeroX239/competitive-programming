import java.util.*;

class Node {
    Node left;
    Node right;
    int data;
    
    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

class Solution {
	/* 
    
    class Node 
    	int data;
    	Node left;
    	Node right;
	*/

	public static void topView(Node root) {
        class Pair{
            int k;
            Node node;
        }

        TreeMap<Integer, Integer> map=new TreeMap<>();
        Queue<Pair> q=new LinkedList<>();
        Pair pair=new Pair();
        pair.node=root;
        pair.k=0;
        q.add(pair);
        while(q.size()>0){
            pair=q.poll();
            if(!map.containsKey(pair.k))
                map.put(pair.k, pair.node.data);
            if(pair.node.left!=null){
                Pair p=new Pair();
                p.k=pair.k-1;
                p.node=pair.node.left;
                q.add(p);
            }

            if(pair.node.right!=null){
                Pair p=new Pair();
                p.k=pair.k+1;
                p.node=pair.node.right;
                q.add(p);
            }

        }
        map.forEach((key, value)->System.out.print(value+" "));
    }


	public static Node insert(Node root, int data) {
        if(root == null) {
            return new Node(data);
        } else {
            Node cur;
            if(data <= root.data) {
                cur = insert(root.left, data);
                root.left = cur;
            } else {
                cur = insert(root.right, data);
                root.right = cur;
            }
            return root;
        }
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        Node root = null;
        while(t-- > 0) {
            int data = scan.nextInt();
            root = insert(root, data);
        }
        scan.close();
        topView(root);
    }	
}