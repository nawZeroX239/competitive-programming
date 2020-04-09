import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class UVAOJ11683 {
	
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
			int H=sc.nextInt();
			if(H==0) break;
			int L=sc.nextInt();
			int h=sc.nextInt();
			int cnt=H-h;
			for(int i=1;  i<L; i++) {
				int y=sc.nextInt();
				if(y<h) {
					cnt+=(h-y);
				}
				h=y;
			}
			System.out.println(cnt);
		}	
		sc.close();
	}
	

}
