import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;

public class UVAOJ10919 {
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
		
		while(sc.hasNext()) {
			int k=sc.nextInt();
			if(k==0) break;
			int m=sc.nextInt();
			HashSet<Integer> taken=new HashSet<>();
			boolean pass=true;
			for(int i=0; i<k; i++) 
				taken.add(sc.nextInt());
			
			for(int i=0; i<m; i++) {
				int c=sc.nextInt();
				int r=sc.nextInt();
				for(int j=0; j<c; j++)
					if(taken.contains(sc.nextInt()))
						r--;
				if(r>0) pass=false;
			}
			
			if(pass) System.out.println("yes");
			else System.out.println("no");
			taken.clear();
		}
		
		sc.close();
	}
}
