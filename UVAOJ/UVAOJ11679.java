import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class UVAOJ11679 {
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
		
		while(true) {
			int B=sc.nextInt();
			int N=sc.nextInt();
			if(B==0 && N==0) break;
			int[] R=new int[B+1];
			for(int i=1; i<=B; i++)
				R[i]=sc.nextInt(); // reserves for 'i' bank
			for(int i=1; i<=N; i++) {
				int D=sc.nextInt(); // debtor bank
				int C=sc.nextInt(); // creditor bank
				int V=sc.nextInt(); // debenture value
				R[D]=R[D]-V;
				R[C]=R[C]+V;
			}
			
			boolean flag=true;
			for(int i=1; i<=B; i++)
				if(R[i]<0) {
					flag=false;
					break;
				}
			if(flag) System.out.println("S");
			else System.out.println("N");
			
		}
		sc.close();
	}
}
