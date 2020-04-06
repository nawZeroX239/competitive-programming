import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class UVAOJ661 {

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
		int seq=1;
		while(true) {
			int n=sc.nextInt();
			int m=sc.nextInt();
			int c=sc.nextInt();
			if(n==0 && m==0 && c==0) break;
//			System.out.println("n:"+n+" m:"+m+" c:"+c);
			boolean[] states=new boolean[n+1];
			int[] devices=new int[n+1];
			for(int i=1; i<=n; i++) {
				devices[i]=sc.nextInt();
			}
			int total=0;
			int best=0;
			boolean flag=false;
			for(int i=1; i<=m; i++) {
				int k=sc.nextInt();
//				System.out.println("k:"+k+" n:"+n+" m:"+m+" seq:"+seq);
				if(states[k]) {
					states[k]=false;
					total=total-devices[k];
				}else {
					states[k]=true;
					total=total+devices[k];
				}
				best=Math.max(total, best);
				if(total > c) flag=true;
			}
			System.out.println("Sequence "+seq);

			if(flag) {
				System.out.println("Fuse was blown.");
			} else {
				System.out.println("Fuse was not blown.");
				System.out.println("Maximal power consumption was "+best+" amperes.");
			}
			System.out.println();
			seq++;
		}

		sc.close();
	}

}
