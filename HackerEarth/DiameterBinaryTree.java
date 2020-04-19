import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class DiameterBinaryTree {
	static class Node{
		int v, u;
		
		Node r;
		Node l;
		public Node(int v) {
			this.v=v;
			r=null;
			l=null;
		}
	}
	
	public static void main(String[] args){
		Scanner sc;
		boolean local=true;
		sc=new Scanner(System.in);
		if(local) {
			sc.close();
			try {
				if(args.length<1) throw new IllegalArgumentException();
				sc=new Scanner(new File(args[0]));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			} catch (IllegalArgumentException e){
				sc=new Scanner(System.in);
			}
		}
		
		int N=sc.nextInt();
		int x=sc.nextInt();
		Node root=new Node(x);
		while(N>1) {
			String s=sc.next();
			int L=s.length();
			int k=sc.nextInt();
			Node itr=root;
//			System.out.println(s);
			for(int i=0; i<L-1; i++)
				if(s.charAt(i)=='L') {
					if(itr.l==null)
						itr.l=new Node(-1);
					itr=itr.l;
				}else {
					if(itr.r==null)
						itr.r=new Node(-1);
					itr=itr.r;
				}
			
			if(s.charAt(L-1)=='L') {
				if(itr.l==null)
					itr.l=new Node(k);
				else
					itr.l.v=k;
			} else {
				if(itr.r==null)
					itr.r=new Node(k);
				else
					itr.r.v=k;
			}
			
			N--;
		}
		int[] ans= new int[1];
		magic(root);
		magicPhase2(root, ans);
		// Time complexity ~2N, N=total node
//		debug(root);
		System.out.println(ans[0]);
		
		sc.close();
	}
	
	
	public static void debug(Node root) {
		// do simple bfs
		if(root==null)
			return;
		Queue<Node> q=new LinkedList<>();
		q.add(root);
		String s="";
		while(!q.isEmpty()) {
			Node n=q.poll();
			s=s+" u:"+n.u+" v:"+n.v;
			if(n.l!=null)
				q.add(n.l);
			if(n.r!=null)
				q.add(n.r);
		}
		
		System.out.println(s.substring(1));
	}
	
	public static int magic(Node root) {
		if(root==null)
			return 0;
		root.u=1+Math.max(root.l==null?0:magic(root.l), root.r==null?0:magic(root.r));
		return root.u;
	}
    
	public static void magicPhase2(Node root, int[] ans) {
		if(root==null)
			return;
		if(root.r!=null && root.l!=null)
			ans[0]=Math.max(root.u+Math.min(root.l.u, root.r.u), ans[0]);
		if(root.l!=null)
			magicPhase2(root.l, ans);
		if(root.r!=null)
			magicPhase2(root.r, ans);
	}
	
}
