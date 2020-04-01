import java.util.Scanner;

public class UVAOJ621 {
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		int __=sc.nextInt();
		String R=null;
		while(__>0) {
			String s=sc.next();
			int N=s.length();
			if(s.equals("1") || s.equals("4") || s.equals("78"))
				System.out.println("+");
			else if(s.substring(N-2, N).equals("35"))
				System.out.println("-");
			else if(s.substring(0, 1).equals("9") &&
					s.substring(N-1,N).equals("4"))
				System.out.println("*");
			else if(s.substring(0, 3).equals("190"))
				System.out.println("?");
			
			__--;
		}
	}
}
