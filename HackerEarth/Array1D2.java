import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Array1D2 {
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
			int K=sc.nextInt();
			long min=Long.MAX_VALUE;
			for(int i=0; i<N; i++)
				min=Math.min(min, sc.nextLong());
			if(K>min)System.out.println(K-min);
			else System.out.println("0");
			
			
			T--;
		}
		
		
		sc.close();
	}
	
}
