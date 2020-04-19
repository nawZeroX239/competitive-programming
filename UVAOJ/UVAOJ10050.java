import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;

public class UVAOJ10050 {
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
			int P=sc.nextInt();
			int[] p=new int[P];
			for(int i=0; i<P; i++)
				p[i]=sc.nextInt();
			HashSet<Integer> set=new HashSet<>();
			for(int i=0; i<P; i++) {
				int loop=N/p[i];
				// 0 sunday 1 monday ... 6 Saturday
//				System.out.println("loop:"+loop);
				for(int j=1; j<=loop; j++) {
					int day=(j*p[i]-1)%7;
					if(day!=5 && day!=6)
						set.add(p[i]*j);
				}
					
			}
			System.out.println(set.size());
			T--;
		}
		
			
		sc.close();
	}

}
