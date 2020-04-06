import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class UVAOJ573 {
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
		
		while(sc.hasNext()) {
			int H=sc.nextInt();
			int U=sc.nextInt();
			int S=sc.nextInt();
			int F=sc.nextInt();
			if(H==0) break;
			double k=U*(F/100.0);
			double dF=0;
			double climb=U;
			int day;
			for(day=1; true; day++) {
				if(climb>0) {
					dF=dF+climb;
					if(dF>H) break;
				}
				climb=climb-k;
				dF=dF-S;
				if(dF<0) break;
			}
			if(dF<=0) System.out.println("failure on day "+day);
			else System.out.println("success on day "+day);
		}

		sc.close();
	}
}
