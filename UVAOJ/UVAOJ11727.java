import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class UVAOJ11727 {
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(
									new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		int[] x = new int[3];
		for(int i=1; i <= T; i++) {
			StringTokenizer tr = new StringTokenizer(br.readLine());
			x[0] = Integer.parseInt(tr.nextToken());
			x[1] = Integer.parseInt(tr.nextToken());
			x[2] = Integer.parseInt(tr.nextToken());
			Arrays.sort(x);
			System.out.println("Case " + i+": " + x[1]);
		}
		
	}
}
