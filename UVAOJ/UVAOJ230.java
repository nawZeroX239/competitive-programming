import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.TreeSet;

class Book{
	int state; // 0 available 1 borrowed 2 ready for collecting
	String title;
	public Book(String title, int state) {
		this.title=title;
		this.state=state;
	}
}

public class UVAOJ230 {
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
		// authors -->books
		TreeMap<String, TreeSet<String>> map=new TreeMap<>();
		while(sc.hasNext()) {
			String input=sc.nextLine();
			if(input.equals("END")) 
				break;
			// "The C Programming Language" by Kernighan, B. and Ritchie, D.
			int lo=1;
			int hi=lo;
			while(input.charAt(hi)!='\"')
				hi++;
			String book=input.substring(lo, hi);
			String auth=input.substring(hi+5);
//			System.out.println(book+":"+auth);
			if(!map.containsKey(auth))
				map.put(auth, new TreeSet<>());
			map.get(auth).add(book);
		}
		
		ArrayList<Book> ordering=new ArrayList<>();
		HashMap<String, Integer> index=new HashMap<>();
		{
		int x=0;
		for(Map.Entry<String, TreeSet<String>> i: map.entrySet())
			for(String v:i.getValue()) {	
				ordering.add(new Book(v, 0));
				index.put(v,x);
				x++;
			}
		
		}
		
//		 for(Book b:ordering)
//			 System.out.println(b.title);
//				
		while(sc.hasNext()){
			String input=sc.nextLine();
			if(input.equals("END"))
				break;
			if(input.equals("SHELVE")) {
				Book last=null;
				for(int i=0; i<ordering.size(); i++) {
					Book now=ordering.get(i);
					if(now.state==2) {
						if(i==0 || last==null)
							System.out.println("Put \""+now.title+"\" first");
						else
							System.out.println("Put \""+now.title+"\" after \""+last.title+"\"");
						now.state=0;
					}
					
					if(now.state==0)
						last=now;
				}
				System.out.println("END");
				continue;
			}
			
			int x=input.indexOf("RETURN");
			String title=input.substring(8, input.length()-1);
//			System.out.println("title:"+title);
			int k=index.get(title);
			if(x>-1)
				ordering.get(k).state=2;
			else
				ordering.get(k).state=1;
			
		}
		sc.close();
	}
	

}
