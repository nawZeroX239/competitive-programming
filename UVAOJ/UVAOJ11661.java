import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class UVAOJ11661 {
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
			String q=sc.next();
			boolean z=false;
			int x0,y0, x, y;
			x0=y0=x=y=-1;
			for(int i=0; i<L; i++) {
				char c=q.charAt(i);
				
				if(c=='D') {
					if(x==-1||y==-1) x0=x=i;
					else if(Math.abs(y-i)<Math.abs(x-y)) x=i;
					if((x0>0&&y0>0)&& (Math.abs(y0-i)<Math.abs(x-y))) {
						y=y0;
					}
					x0=i;
				}else if(c=='Z') {
					z=true;
					break;
				}else if(c=='R') {
					if(y==-1||x==-1) y=i;
					else if(Math.abs(x-i)<=Math.abs(x-y)) y=i;
					if((x0>0&&y0>0)&& (Math.abs(x0-i)<Math.abs(x-y))) {
							x=x0;
					}
					y0=i;
				}
				
				if(Math.abs(x0-y0)<Math.abs(x-y)) {
					x=x0;
					y=y0;
				}
			}
			if(z) System.out.println("0");
			else System.out.println(Math.abs(x-y));
		}
		sc.close();
	}
	

}
