import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.StringTokenizer;

public class UVAOJ10141 {
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
		int T=1;
		while(sc.hasNext()) {
			StringTokenizer toks=new StringTokenizer(sc.nextLine());
			
			int n=Integer.parseInt(toks.nextToken());
			int p=Integer.parseInt(toks.nextToken());
			if(n==0 && p==0) break;
			if(T>1) System.out.println();
			for(int i=0; i<n; i++) {
				sc.nextLine();
			}
			ArrayList<String> bests=new ArrayList<>();
			double price=-1.0;
			int met=0;
			for(int i=0; i<p; i++) {
				String proposal=sc.nextLine();
				toks=new StringTokenizer(sc.nextLine());
				double d=Double.parseDouble(toks.nextToken());
				int r=Integer.parseInt(toks.nextToken());
				for(int j=0; j<r; j++)
					sc.nextLine();
				if(bests.size()==0) {
					bests.add(proposal);
					price=d;
					met=r;
				} else if((r==met && d<price) || r>met){
					price=d;
					met=r;
					bests.clear();
					bests.add(proposal);
				} else if(r==met && price==d) {
					bests.add(proposal);
				}
			}
			System.out.println("RFP #"+T);
			System.out.println(bests.get(0));
			T++;
		}
		
		sc.close();
	}
}
