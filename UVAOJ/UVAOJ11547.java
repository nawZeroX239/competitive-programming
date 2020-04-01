import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class UVAOJ11547 {
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(
									new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		while(T > 0) {
			long n = Integer.parseInt(br.readLine());
			n*=567;
			n/=9;
			n+=7492;
			n*=235;
			n/=47;
			n-=498;
			n = n%100;
			n = (n-n%10)/10;
			System.out.println(Math.abs(n));
			T--;
		}
		
	}
}
