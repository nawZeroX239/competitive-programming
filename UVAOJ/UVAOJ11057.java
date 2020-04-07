import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class UVAOJ11057 {
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
		
		while(sc.hasNext()) {
			int L=sc.nextInt();
			if(L==0) break;
			String p="+x";
			for(int i=1; i<L; i++) {
				String q=sc.next();
				if(q.equals("No")) continue;
				if(p.equals("+x")) {
					// +x trivia case
					p=q;
				}else if((eq(p, "+y") && eq(q, "+y"))
						|| (eq(p, "-y") && eq(q, "-y"))
						|| (eq(p, "+z") && eq(q, "+z"))
						|| (eq(p, "-z") && eq(q, "-z"))) {
					p="-x";
				}else if((eq(p, "+x") && eq(q, "-y"))
						|| (eq(p, "-y") && eq(q, "+y"))
						|| (eq(p, "+y") && eq(q, "-y"))
						|| (eq(p, "+z") && eq(q, "-z"))
						|| (eq(p, "-z") && eq(q, "+z"))) {
					p="+x";
				}else if((eq(p, "-x") && eq(q, "+y"))) {
					p="-y";
				}else if(eq(p, "-x") && eq(q, "-y")) {
					p="+y";
				}else if(eq(p, "-x") && eq(q, "+z")) {
					p="-z";
				}else if(eq(p, "-x") && eq(q, "-z")) {
					p="+z";
				}else if(eq(p, "+x") && eq(q, "+z")) {
					// doesn't change
				}else if(eq(p, "-y") && eq(q, "+z")) {
					// doesn't change
				}else if(eq(p, "+y") && eq(q, "+z")) {
					// doesn't change
				}else if(eq(p, "+z") && eq(q, "-y")) {
					// doesn't change
				}else if(eq(p, "+z") && eq(q, "+y")) {
					// doesn't change
				}
			}
			
			System.out.println(p);
		}
		
		sc.close();
	}
	
	public static boolean eq(String a, String b) {
		return a.equals(b);
	}
}
