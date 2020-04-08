import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class DP2 {
	
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
		
		int A=sc.nextInt();
		int B=sc.nextInt();
		long[] a=new long[A+1];
		long[] b=new long[B+1];
		long[] ab=new long[B+1];
		long[] ba=new long[B+1];
		
		for(int i=1; i<=A; i++)
			a[i]=sc.nextInt();
		for(int i=1; i<=B; i++)
			b[i]=sc.nextInt();
		boolean z=false;
		ab[1]=a[1];
		ba[1]=b[1];
		
		for(int i=2; i<=B; i++) {
			if(z) {
				ab[i]=a[i]+ab[i-1];
				ba[i]=b[i]+ba[i-1];
			} else {
				ab[i]=b[i]+ab[i-1];
				ba[i]=a[i]+ba[i-1];
			}
			z=!z;
		}
//		for(int i=1; i<=B; i++)
//			System.out.print(ab[i]+" ");
//		System.out.println();
//		for(int i=1; i<=B; i++)
//			System.out.print(ba[i]+" ");
//		System.out.println();
//
//		System.out.println();

		long[] temp;
		while(sc.hasNext()) {
			int select=sc.nextInt();
			int lo=sc.nextInt();
			int hi=sc.nextInt();
			if(select==1) {
			
				if(lo%2!=0) temp=ab;
				else temp=ba; 
			}else {
				if(lo%2!=0) temp=ba;
				else temp=ab;
			}
			lo--;
			System.out.println(temp[hi]-temp[lo]);
			
		}
		
		sc.close();
	}
	
}
