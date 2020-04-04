import java.util.Scanner;

public class UVAOJ11332 {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		long N=sc.nextLong();
		while(N!=0) {
			while(N/10>0) {
				long sum=0;
				while(N>0) {
					sum+=N%10;
					N=N/10;
				}
				N=sum;
			}
			System.out.println(N);
			N=sc.nextLong();
		}
		sc.close();
	}
	
}
