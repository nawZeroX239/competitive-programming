
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class UVAOJ12157 {
public static void main(String[] args){
		boolean local=true;
		Scanner sc=new Scanner(System.in);
		if(local) {
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

		int T=sc.nextInt();
		for(int I=1; I<=T; I++) {
			int N=sc.nextInt();
			int c0=0; // Mile
			int c1=0; // Juice
			
			for(int i=0; i<N; i++) {
				int t=sc.nextInt();
				c0=c0+(t/30)*10+(t%30>=0?10:0);
				c1=c1+(t/60)*15+(t%60>=0?15:0);
			}
			if(c0<c1) {
				System.out.println("Case "+I+": Mile "+c0);
			} else if(c0>c1){
				System.out.println("Case "+I+": Juice "+c1);
			} else {
				System.out.println("Case "+I+": Mile Juice "+c1);

			}
			
			
		}
		sc.close();
	}

	public static boolean contains(int[] arr, int k) {
		int hi=arr.length-1;
		int lo=0;
		while(lo<=hi) {
			int mid=lo+(hi-lo)/2;
			if(arr[mid]==k) return true;
			else if(arr[mid] > k) hi=mid-1;
			else lo=mid+1;
		}
		
		return false;
	}
	
	public static boolean isLucky(int k) {
		while(k>0) {
			int r=k%10;
			if(r!=4 && r!=7) return false;
				
			k=k/10;
		}
		
		return true;
	}
	
}
