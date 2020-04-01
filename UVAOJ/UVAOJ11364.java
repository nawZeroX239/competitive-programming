import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class UVAOJ11364 {
	
	public static void main() throws IOException{
		BufferedReader br = new BufferedReader(
									new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		while(T>0) {
			int N = Integer.parseInt(br.readLine());
			StringTokenizer tr = new StringTokenizer(br.readLine());
			int[] p = new int[N];
			for(int i = 0; i < N; i++)
				p[i] = Integer.parseInt(tr.nextToken());
			Arrays.sort(p);
			int d = 0;
			for(int i = 1; i < N; i++)
				d+=p[i]-p[i-1];
			System.out.println(d * 2);
			T--;
		}
	}
}
