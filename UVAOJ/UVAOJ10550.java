import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class UVAOJ10550 {
	public static int K = 9;
	
	public static void solve() throws IOException{
		BufferedReader br = new BufferedReader(
									new InputStreamReader(System.in));
		String L = null;
		while((L=br.readLine())!=null) {
			StringTokenizer tr = new StringTokenizer(L);
			int P = Integer.parseInt(tr.nextToken());
			int A = Integer.parseInt(tr.nextToken());
			int B = Integer.parseInt(tr.nextToken());
			int C = Integer.parseInt(tr.nextToken());
			int x = 1080;
//			System.out.println(P + " " + A + " " + B + " " + C);
			if(P == 0 && A == 0 && B == 0 && C == 0) break;
			x += right(A, P);
			x += left(B, A);
			x += right(C, B);
			System.out.println(x);
		}
		
	}
	
	public static int right(int d, int dI) {
		if(d == dI) return 360;
		if(d > dI) return (dI + 40-d)*K;
		
		return (dI-d)*K;
	}
	
	public static int left(int d, int dI) {
		if(d == dI) return 360;
		if(d < dI) return (d + 40-dI)*K;
		
		return (d-dI)*K;
	}
}
