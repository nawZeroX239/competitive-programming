import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class DP1 {
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
		
		String s=sc.next();
		
		int N=s.length();
		int[] x=new int[N];
		x[N-1]=((s.charAt(N-1)-'0')%2==0? 1 : 0);
		
				
		for(int i=N-2; i>=0; i--)
			if((s.charAt(i)-'0')%2==0)
				x[i] = x[i+1]+1;
			else
				x[i] = x[i+1];
		for(int i=0; i<N; i++)
			System.out.print(x[i]+" ");
		
		sc.close();
	}
	
	
}
