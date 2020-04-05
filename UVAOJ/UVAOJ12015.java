import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class UVAOJ12015 {
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

		int T=sc.nextInt();
		Queue<String> q = new LinkedList<>();
		for(int I=1; I<=T; I++) {

			String s=sc.next();
			int largest=sc.nextInt();
			q.add(s);
			System.out.println("Case #"+I+":");
			for(int i=1; i<10; i++) {
				s=sc.next();
				int temp=sc.nextInt();
				if(temp>largest) {
					q.clear();
					largest=temp;
					q.add(s);
				} else if(temp==largest) q.add(s);
			}
			
			while(q.size()>0)
				System.out.println(q.remove());
			
		}
		sc.close();
	}


}
