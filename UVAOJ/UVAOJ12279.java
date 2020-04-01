
import java.util.Scanner;

public class UVAOJ12279 {
	
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		int T=1;
		while(sc.hasNext()) {
			int N = sc.nextInt();
			if(N==0) break;
			int i = 0;
			int j = 0;
			for(int k = 0; k < N; k++) {
				if(sc.nextInt() > 0)
					i++;
				else 
					j++;
			}
			System.out.println("Case "+T+": "+(i-j));
			
			T++;
		}
		
		sc.close();
		
	}
}
