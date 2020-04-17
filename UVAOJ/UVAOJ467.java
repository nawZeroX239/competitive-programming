import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.StringTokenizer;

public class UVAOJ467 {
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
		while(sc.hasNextLine()) {
			StringTokenizer toks=new StringTokenizer(sc.nextLine());
			int N=toks.countTokens();
			int[] d=new int[N];
			int l=Integer.MAX_VALUE;
			for(int i=0; i<N; i++) {
				d[i]=Integer.parseInt(toks.nextToken());
				l=Math.min(l, d[i]);
			}
			
			int timer=l*2;
			while(timer<=3600) {
				boolean g=true;
				for(int i=0; i<N&&g; i++)
					if(timer%(d[i]*2)>=(d[i]-5))
						g=false;
				if(g==true)
					break;
				timer++;
			}
			
			if(timer>3600)
				System.out.println("Set "+set+" is unable to synch after one hour.");
			else
				System.out.println("Set "+set+" synchs again at "+(timer/60)+" minute(s) and "+ (timer%60)+" second(s) after all turning green.");
			
			set++;
		}
		

		sc.close();
	}
    
}
