import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class UVAOJ11172 {
	
	public static void solve() throws IOException{
		BufferedReader br = new BufferedReader(
									new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		
		while(T > 0) {
			
			StringTokenizer tr = new StringTokenizer(br.readLine());
			long x = Integer.parseInt(tr.nextToken());
			long y = Integer.parseInt(tr.nextToken());
			if(x>y) System.out.println(">");
			else if(x < y) System.out.println("<");
			else System.out.println("=");
			
			T--;
		}
		
	}
}
