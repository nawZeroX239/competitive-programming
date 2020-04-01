
import java.util.Scanner;

public class UVAOJ12403 {
	public static int K = 20;
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int T=sc.nextInt();
		int bal = 0;
		while(T>0) {
			String opt = sc.next();
			
			if(opt.equals("donate")) {
				int amt = sc.nextInt();
				bal+=amt;
			} else {
				System.out.println(bal);
			}
			T--;
		}
	}
}
