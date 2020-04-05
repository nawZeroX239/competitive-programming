import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class UVAOJ11764 {
	public static void main(String[] args){
		boolean local=false;
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
		
		int T=sc.nextInt();
		int I=1;
		while(T>0) {
			int hi=0;
			int lo=0;
			int N=sc.nextInt();
			int H=sc.nextInt();// previous wall1
			for(int i=1; i<N; i++) {
				int h=sc.nextInt();
				if(h>H) hi++;
				else if(h<H) lo++;
				H=h;
			}
			System.out.println("Case "+I+": "+hi+" "+lo);
			I++;
			T--;
		}
		sc.close();
	}
	
	
}
