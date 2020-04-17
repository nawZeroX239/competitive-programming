import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class UVAOJ591 {
	public static void main(String[] args){
		boolean local=false;
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
		int set=1;
		while(true) {
			int n=sc.nextInt();
			if(n==0)
				break;
			int[] arr=new int[n];
			int sum=0;
			for(int i=0; i<n; i++) {
				arr[i]=sc.nextInt();
				sum+=arr[i];
			}
			int avg=sum/n;
			int cost=0;
			for(int i=0; i<n; i++)
				if(arr[i]>avg)
					cost=cost+Math.abs(avg-arr[i]);
			System.out.println("Set #"+set);
			System.out.println("The minimum number of moves is "+cost+".\n");
			set++;
		}

		sc.close();
	}
    
}
