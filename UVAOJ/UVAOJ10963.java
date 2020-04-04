
import java.util.Scanner;

public class UVAOJ10963 {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int T=sc.nextInt();
		while(T>0) {
			int col=sc.nextInt();
			int a=sc.nextInt();
			int b=sc.nextInt();
			int dY=Math.abs(a-b);
			boolean flag=true;
			for(int i=1; i<col; i++) {
				a=sc.nextInt();
				b=sc.nextInt();
				if(dY!=Math.abs(a-b)) flag=false;
			}
			if(flag)System.out.println("yes");
			else System.out.println("no");
			T--;
			if(T!=0) System.out.println();
		}
		
		sc.close();
	}
	
}
