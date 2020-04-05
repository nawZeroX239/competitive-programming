import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class UVAOJ12503 {
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
		
		int T=sc.nextInt();
		
		while(T>0) {
			int N=sc.nextInt();
			int[] x=new int[N+1];
			int pos=0;
			for(int i=1; i<=N; i++) {
				String ins=sc.next();
				if(ins.equals("LEFT")) {
					x[i]=-1;
					pos--;
				} else if(ins.equals("RIGHT")) {
					x[i]=1;
					pos++;
				} else {
					sc.next();
					int index=sc.nextInt();
					x[i]=x[index];
					pos=pos+x[i];
				}
			}
			
			System.out.println(pos);
			T--;
		}
		
		sc.close();
	}

}
