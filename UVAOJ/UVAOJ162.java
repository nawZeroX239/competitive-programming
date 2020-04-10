import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Scanner;

public class UVAOJ162 {
	
	public static void main(String[] args){
		boolean local=true;
		Scanner sc=new Scanner(System.in);
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
		
		LinkedList<String> a=new LinkedList<>();
		LinkedList<String> b=new LinkedList<>();
		LinkedList<String> free=new LinkedList<>();
		
		while(true) {
		boolean stop=false;
		int count=26;
		while(count>0) {
			String s=sc.next();
			if(s.equals("#")) {
				stop=true;
				break;
			}
			a.addLast(s); // non dealer
			b.addLast(sc.next()); // dealer
			count--;
		}
		if(stop) break;
		int turn=1;
		int face=0;
		int n=0;
		String x;
		int k;
//		System.out.println(a.size() + " " +b.size());
		while(true) {

			if(turn==2) {
				if(b.size()==0) break;
				x=b.removeLast();
				k=isFaceCard(x);
				turn=1;
				if(k>0) {
					// this player has face card
					face=2;
					n=k;
				}else if(n>0) {
					n--;
					if(n>0)turn=2;
				}
				
			} else {
				if(a.size()==0) break;
				x=a.removeLast();
				k=isFaceCard(x);
				turn=2;
				if(k>0) {
					//this player is face
					n=k;
					face=1;
				} else if(n>0) {
					n--;
					if(n>0)turn=1;
				}
				
			}
			
			free.addLast(x); // free cards
			
//			if(!(n>0 && face==1 && a.size()==0)) break;
			
			if(n==0 && face>0) {
				if(face==1)
					while(free.size()>0) a.addFirst(free.removeFirst());
				else
					while(free.size()>0) b.addFirst(free.removeFirst());
				
				face=0;
			}
			
//			System.out.println("\n"+a.toString());
//			System.out.println(b.toString());
//			System.out.println(free.toString());
		}
		
		if(a.size()>0) System.out.println("2"+String.format("%3d",a.size()));
		else System.out.println("1"+String.format("%3d",b.size()));
		a.clear();
		b.clear();
		free.clear();
		}
		sc.close();
	}
	
	public static int isFaceCard(String s) {
		if(s.charAt(1)=='A') return 4;
		else if(s.charAt(1)=='K') return 3;
		else if(s.charAt(1)=='Q') return 2;
		else if(s.charAt(1)=='J') return 1;
		
		return -1;
	}

}
