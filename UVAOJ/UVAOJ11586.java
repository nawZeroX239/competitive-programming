import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class UVAOJ11586 {
	
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
		
		int T=Integer.parseInt(sc.nextLine());
		while(T>0) {
			int m=0;
			int n=0;
			String line=sc.nextLine();
			for(int i=0; i<line.length(); i++) {
				char c=line.charAt(i);
				if(Character.isAlphabetic(c)){
					if(c=='M')m++;
					else n++;
				}
			}
			
			
			if((m>1&&n>1) &&(m==n)) System.out.println("LOOP");
			else System.out.println("NO LOOP");
			
			T--;
		}
		
		sc.close();
	}
	

}
