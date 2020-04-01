import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class UVAOJ11498 {
	
	public static void main() throws IOException{
		BufferedReader br = new BufferedReader(
									new InputStreamReader(System.in));
		int K;
		while((K=Integer.parseInt(br.readLine()))!=0) {
			StringTokenizer tr = new StringTokenizer(br.readLine());
			int dX = Integer.parseInt(tr.nextToken());
			int dY = Integer.parseInt(tr.nextToken());
			for(int i = 0; i < K; i++) {
				tr = new StringTokenizer(br.readLine());
				int x = Integer.parseInt(tr.nextToken());
				int y = Integer.parseInt(tr.nextToken());
				if(x == dX || y == dY) System.out.println("divisa");
				else if(x < dX && y > dY) System.out.println("NO");
				else if(x > dX && y > dY) System.out.println("NE");
				else if(x < dX && y < dY) System.out.println("SO");
				else System.out.println("SE");
				
			}
		}
		
	}
}
