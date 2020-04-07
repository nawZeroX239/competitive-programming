import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class UVAOJ10424 {
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
		
		while(sc.hasNext()) {
			String r=sc.nextLine();
			String s=sc.nextLine();
			int a=0;
			int b=0;
			int i, j;
			for(i=0; i<r.length(); i++) {
				char c=r.charAt(i);
				if(Character.isAlphabetic(c))
					a=a+Character.toLowerCase(c)-'a'+1;
	
			}
			for(j=0; j<s.length(); j++) {
				char c=s.charAt(j);
				if(Character.isAlphabetic(c))
					b=b+Character.toLowerCase(c)-'a'+1;
			}
			a=cal(a);
			b=cal(b);
			double ratio=(a>b?(double)b/a:(double)a/b);
//			System.out.println("a:"+a+" b:"+b);
			System.out.println(String.format("%.2f %%", 100.0*ratio));
		}
		
		sc.close();
	}
	
	public static int cal(int n) {
		while(n/10>0) {
			int sum=0;
			while(n>0) {
				sum+=n%10;
				n=n/10;
			}
			n=sum;
		}
		
		return n;
	}
}
