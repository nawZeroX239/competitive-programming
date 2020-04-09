import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Array1D3 {
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
		int[] a=new int[N];
		int[] l=new int[N];
		for(int i=0; i<N; i++)
			a[i]=sc.nextInt();
		l[N-1]=a[N-1];
		for(int i=N-2; i>=0; i--)
			if(a[i]>l[i+1])
				l[i]=a[i];
			else
				l[i]=l[i+1];
		for(int i=0; i<N-1; i++)
			if(a[i]>= l[i])
				System.out.print(a[i]+" ");
		System.out.println(a[N-1]);
		sc.close();
	}
	
}
