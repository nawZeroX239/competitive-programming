import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class UVAOJ11956 {
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
		
		int N=100;
		int T=Integer.parseInt(sc.nextLine());
		int I=1;
		while(T>0) {
			int[] a=new int[N];
			int ptr=0;
			String commands=sc.nextLine();
			for(int i=0; i<commands.length(); i++) {
				char c=commands.charAt(i);
				if(c=='>') {
					ptr++;
					if(ptr>=N) ptr=0;
				}else if(c=='<') {
					ptr--;
					if(ptr<0) ptr=N-1;
				}else if(c=='+') {
					a[ptr]++;
					if(a[ptr]>255) a[ptr]=0;
				}else if(c=='-') {
					a[ptr]--;
					if(a[ptr]<0) a[ptr]=255;
				}else {
					//System.out.print(String.format("%02x ", a[ptr]));
				}
			}
			System.out.print("Case "+I+": ");
			for(int i=0; i<N; i++) {
				
				System.out.print(String.format("%02X", a[i]).toUpperCase());
				if(i+1<N) System.out.print(" ");
			}
				System.out.println();
			T--;
			I++;
		}
		sc.close();
	}
}
