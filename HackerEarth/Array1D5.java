import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Array1D5 {
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
			int i;
			int N=sc.nextInt();
			long sum=0;
			int[] a=new int[N];
			for(i=0; i<N; i++) {
				a[i]=sc.nextInt();
				sum+=a[i];
			}
			
			for(i=0; i<N; i++) {
				if(a[i]>=(sum-a[i])) {
					break;
				}
			}
			if(i<N) System.out.println("No");
			else System.out.println("Yes");
			T--;
		}
		
		sc.close();
	}
	
}
