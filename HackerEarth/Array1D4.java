import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Array1D4 {
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
		
		int T=sc.nextInt();
		while(T>0) {
		int N=sc.nextInt();
		long ways=(long) Math.pow(2, N-1);
		long sum=0;
		long m=1000000007;
		
		for(int i=0; i<N; i++) {
			long q=sc.nextLong();
			if(q>=ways) {
				sum=sum%m+q%m;
			}
		}
		System.out.println(sum%m);
		
		T--;
		}
		
		sc.close();
	}
	
}
