import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class UVAOJ272 {
	public static void solve() throws IOException{
		BufferedReader br = new BufferedReader(
									new InputStreamReader(System.in));
		
		boolean fp = true;
		String L = null;
		while((L = br.readLine()) != null) {
			int N = L.length();
			for(int i = 0; i < N; i++) {
				char c = L.charAt(i);
				if(c == '\"') {
					if(fp) {
						System.out.print("``");
					} else {
						System.out.print("''");
					}
					fp = !fp;
				} else {
					System.out.print(c);
				}
			}
			
			System.out.println();
		}
		
		
	}
}
