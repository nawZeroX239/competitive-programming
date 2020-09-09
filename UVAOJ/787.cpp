import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static boolean LOCAL = false;
	public static int N=105;
	public static int ar[] = new int[N];
	
	public static void main(String args[]) {
		Scanner sc=new Scanner(System.in);
		if(LOCAL) {
			sc.close();
			try {
				if(args.length<1) throw new IllegalArgumentException();
				sc=new Scanner(new File(args[0]));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			} catch (IllegalArgumentException e){
				sc=new Scanner(System.in);
			}
		}
		
		BigInteger zero = BigInteger.valueOf(0);
		int n;
		while(sc.hasNextInt()) {
			n= -1;
			while(true) {
				ar[++n] = sc.nextInt();
				if(ar[n] == -999999) {
					break;
				}
			}
			
			BigInteger ans = BigInteger.valueOf(-999999);
			for(int i=0; i<n; ++i) {
				BigInteger prod= BigInteger.valueOf(1);
				
				for(int j=i; j <n; ++j) {
					prod = prod.multiply(BigInteger.valueOf(ar[j]));
					ans = maxBigInt(prod, ans);
					// System.out.println("prod: " + prod);
					if(prod.equals(zero)) {
						break;
					}
				}
				
			}
			
			System.out.println(ans);
		}
		
	}
	
	public static BigInteger maxBigInt(BigInteger left, BigInteger right) {
		return left.compareTo(right) < 0 ? right : left;
	}
}
