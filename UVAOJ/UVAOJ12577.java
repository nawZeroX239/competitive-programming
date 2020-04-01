
import java.util.Scanner;

public class UVAOJ12577 {
	public static void solve(String[] args){
		Scanner sc = new Scanner(System.in);
		int __=1;
		while(sc.hasNext()) {
			String s="";
			String tok =sc.next();
			if(tok.equals("*")) break;
			if(tok.equals("Hajj")) 
				s="Hajj-e-Akbar";

			else
				s="Hajj-e-Asghar";

			
			System.out.println("Case "+__+": "+s);
			__++;
		}
	}
}
