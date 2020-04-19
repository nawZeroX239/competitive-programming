import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class UVAOJ10038 {
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
		
		while(sc.hasNext()) {
			int n=sc.nextInt();
			int[] a=new int[n];
			boolean[] b=new boolean[n];
			for(int i=0; i<n; i++)
				a[i]=sc.nextInt();
			b[0]=true;
			for(int i=1; i<n && b[0]; i++) {
				int abs=Math.abs(a[i]-a[i-1]);
				if(abs>n-1)
					b[0]=false;
				else
					b[abs]=true;
			}

			for(int i=1; i<n && b[0]; i++)
				if(b[i]==false)
					b[0]=false;
			if(b[0])
				System.out.println("Jolly");
			else
				System.out.println("Not jolly");
		}
		
			
		sc.close();
	}
    
}
