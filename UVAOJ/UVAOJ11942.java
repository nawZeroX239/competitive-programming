import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class UVAOJ11942 {
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
		System.out.println("Lumberjacks:");
		while(T>0) {
			boolean flag=true;
			int x=sc.nextInt();
			int y=sc.nextInt();
			char operator = x > y ? '>' : '<';
			
			for(int i=3; i<=10; i++) {
				int t=sc.nextInt();
				if(test(operator, y, t)==false) 
					flag=false;
				y=t;
			}
			if(flag) System.out.println("Ordered");
			else System.out.println("Unordered");
			T--;
		}
		sc.close();
	}
	
	public static boolean test(char operator, int a, int b) {
		if(operator=='<') {
			return a < b;
		}
		return a > b;
	}
	
}
