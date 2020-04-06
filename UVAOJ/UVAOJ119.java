import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class UVAOJ119 {
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
		
		HashMap<String, Integer> map=new HashMap<>();
		ArrayList<String> li =new ArrayList<>();
		
		while(sc.hasNext()) {
			int N=sc.nextInt();
			for(int i=0; i<N; i++) {
				String name=sc.next();
				li.add(name);
				map.put(name, 0);
			}
			
			for(int i=0; i<N; i++) {
				String name=sc.next();
				int amt=sc.nextInt();
				int k=sc.nextInt();
				int gain=0;
				int lost=0;
				int gift=0;
				if(k==0) continue;
				gift=amt/k;
				gain=map.get(name);
				lost=-gift*k;
				map.put(name, gain+lost);
				
				for(int j=0; j<k; j++) {
					String receiver=sc.next();
					int v=map.get(receiver);
					map.put(receiver, gift+v);
				}
			}
			
			for(int i=0; i<N; i++)
				System.out.println(li.get(i)+" "+map.get(li.get(i)));
			
			li.clear();
			map.clear();
			if(sc.hasNext()) System.out.println();
			
		}
		
		sc.close();
	}
}
