import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.StringTokenizer;

public class UVAOJ482 {
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
		
		int T=Integer.parseInt(sc.nextLine());
		while(T>0) {
			sc.nextLine();
			StringTokenizer[] toks=new StringTokenizer[2];
			toks[0]=new StringTokenizer(sc.nextLine());
			toks[1]=new StringTokenizer(sc.nextLine());
			
			int N=toks[0].countTokens();
			String[] arr=new String[N+1];
			for(int i=1; i<=N; i++) 
				arr[Integer.parseInt(toks[0].nextToken())]=toks[1].nextToken();
			
			for(int i=1; i<=N; i++)
				System.out.println(arr[i]);
			
			T--;
			if(T>0)
				System.out.println();
		}

		sc.close();
	}
}
