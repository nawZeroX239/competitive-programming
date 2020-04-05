import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class UVAOJ12468 {
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

		while(true) {
			int x=sc.nextInt();
			int y=sc.nextInt();
			if(x==-1 && y==-1) break;
			// three ways to go from channel x to y
			System.out.println(Math.min(Math.abs(x-y), Math.min(100-x+y, x+100-y)));
		}
		sc.close();
	}

}
