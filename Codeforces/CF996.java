import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class CF996 {
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
		int n=sc.nextInt();
		int min=0;
		if(n>=100) {
			min+=n/100;
			n%=100;
		}
		
		if(n>=20) {
			min+=n/20;
			n%=20;
		}
		
		if(n>=10) {
			min+=n/10;
			n%=10;
		}
		
		if(n>=5) {
			min+=n/5;
			n%=5;
		}
		min+=n;
		System.out.println(min);
		sc.close();
	}
	
}
