import java.util.Scanner;

public class UVAOJ10114 {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		while(true) {
			int m=sc.nextInt();
			double d=sc.nextDouble();
			double l=sc.nextDouble();
			int dR=sc.nextInt();
			double C=d+l;
			
			if(m<0) break;
			int[] a=new int[dR];
			double[] b=new double[dR];
			for(int i=0; i<dR; i++) {
				a[i]=sc.nextInt();
				b[i]=sc.nextDouble();
			}
			int k=0;
			int cur=0;
			double r=1.0;
			double minus=l/m;
//			System.out.println(minus);
			while(true) {
				if(cur<dR&&a[cur]==k) r=b[cur++];
				C=(1.0-r)*C;
//				System.out.println("k:"+k+" r:"+r+" C:"+C+" l:"+l);
				if(l<C) break;
				l -= minus;

				k++;
			}
			
			if(k==1) System.out.println(k + " month");
			else System.out.println(k+" months");
		}
	
		
	}
}
