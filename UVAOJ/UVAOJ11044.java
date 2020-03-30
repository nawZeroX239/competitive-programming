import java.util.Scanner;

public class UVAOJ11044 {
	public static void solve() {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		while(T > 0) {
			int N = sc.nextInt();
			int M = sc.nextInt();
			
			if((N-2)%3 != 0) N = N + 3-(N-2)%3;
			else N-=2;
			if((M-2)%3 != 0) M = M + 3-(M-2)%3;
			else M-=2;
			System.out.println((N/3)*(M/3));
			
			
			T--;
		}
	}
}
