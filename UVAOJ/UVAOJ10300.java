import java.util.Scanner;

public class UVAOJ10300 {
	public static void solve(){
		Scanner sc=new Scanner(System.in);
		int T = sc.nextInt();
		while(T>0) {
			int nF = sc.nextInt();
			long fS;
			long nA;
			long eS;
			long sum=0;
			while(nF > 0) {
				fS=sc.nextLong();
				nA=sc.nextLong();
				eS=sc.nextLong();
//				System.out.println((double)fS/nA);
//				System.out.println("fS:"+fS+" nA:"+nA+" eS:"+eS);
				if(nA!=0) sum=sum+(fS*eS);
				
				nF--;
			}
			System.out.println(sum);
			T--;
		}
	
		
	}
}
