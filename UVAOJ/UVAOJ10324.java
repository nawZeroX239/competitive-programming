import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class UVAOJ10324 {
	
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
		
		int[] v=new int[1000001];
		int T=1;
		while(sc.hasNext()) {
			System.out.println("Case "+T+":");
			String str=sc.next();
			char x=str.charAt(0);
			int N=str.length();
			v[0]=1;
			for(int i=1; i<N; i++) {
				if(x == str.charAt(i))
					v[i]=v[i-1] + 1;
				else
					v[i]=1;
				x=str.charAt(i);
			}
			int n=sc.nextInt();
			for(int i=0; i<n; i++) {
				int k=sc.nextInt();
				int l=sc.nextInt();
				int lo=Math.min(k, l);
				int hi=Math.max(k, l);
				if(hi-lo == v[hi]-v[lo]){
					System.out.println("Yes");
				} else {
					System.out.println("No");
				}
			}
//			for(int i=0; i<N; i++) System.out.print(v[i] +" ");
//			System.out.println();
			T++;
		}
		
		sc.close();
	}
}
