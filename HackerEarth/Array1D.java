import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Array1D {
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
		
		int N=sc.nextInt();
		int Q=sc.nextInt();
		int[] bits=new int[N+1];
		for(int i=1; i<=N; i++)
			bits[i]=sc.nextInt();
		
		while(Q>0) {
			int q=sc.nextInt();
			if(q==1) {
				int index=sc.nextInt();
				bits[index]= Math.abs(bits[index]-1);
			} else {
				int lo=sc.nextInt();
				int hi=sc.nextInt();
				if(bits[hi]>0) System.out.println("ODD");
				else System.out.println("EVEN");
					
			}
			Q--;
		}
		sc.close();
	}
	
}
