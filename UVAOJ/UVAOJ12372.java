
import java.util.Scanner;

public class UVAOJ12372 {
	public static int K = 20;
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		int T=sc.nextInt();
		for(int t=1; t<=T; t++){
			int L = sc.nextInt();
			int W = sc.nextInt();
			int H = sc.nextInt();
			String res = "";
			if(L<=K&&W<=K&&H<=K) res="good";
			else res="bad";
			System.out.println(String.format("Case %d: %s", t, res));
		}
		
	}
}
