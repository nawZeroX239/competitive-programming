import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
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
		for(int I=1; I<=T; I++) {
			HashMap<Integer, Queue<String>> map=new HashMap<>();

			int largest=1;
			System.out.println("Case #"+I+":");
			for(int i=0; i<10; i++) {
				String s=sc.next();
				int V=sc.nextInt();
				if(V>largest) largest=V;
				if(map.get(V)==null) {
					map.put(V, new LinkedList<String>());
				}
				map.get(V).add(s);
			}
			Queue<String> q=map.get(largest);
			while(q.size()>0) {
				System.out.println(q.remove());
			}
		}
		sc.close();
	}

}
