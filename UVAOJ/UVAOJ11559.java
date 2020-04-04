import java.util.Scanner;

public class UVAOJ11559 {
	public static void solve(){
		Scanner sc=new Scanner(System.in);
		while(sc.hasNextInt()) {
			int N=sc.nextInt();
			int B=sc.nextInt();
			int H=sc.nextInt();
			int W=sc.nextInt();
			int ans=Integer.MAX_VALUE;
			
			for(int i=0; i<H; i++) {
				int P=sc.nextInt(); // price per person
				int cost=Integer.MAX_VALUE;
				for(int j=0; j<W; j++) {
					int bed=sc.nextInt(); //number of bed available
					if((P*N)<=B && (bed>=N)) cost=P*N;
				}
				ans=Math.min(cost, ans);
				
			}
			if(ans<Integer.MAX_VALUE) System.out.println(ans);
			else System.out.println("stay home");
			
		}
		sc.close();
	}
	
	
}
