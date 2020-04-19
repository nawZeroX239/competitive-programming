import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;

public class UVAOJ10260 {
	public static void main(String[] args){
		Scanner sc;
		boolean local=false;
		sc=new Scanner(System.in);
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
		
		String[] a= {"BFPV", "CGJKQSXZ", "DT", "L", "MN", "R"};
		HashMap<Character, Integer> map=new HashMap<>();
		for(int i=1; i<=a.length; i++)
			for(int k=0; k<a[i-1].length(); k++)
				map.put(a[i-1].charAt(k), i);
//		System.out.println(map);
		while(sc.hasNext()) {
			String s=sc.next();
			int last=-1;
			String ans="";
			for(int i=0; i<s.length(); i++) {
				char key=s.charAt(i);
				if(map.containsKey(key)){
					int v=map.get(key);
					if(last!=v)
						ans+=v;
					
					last=v;
				}else
					last=-1;
			}
			System.out.println(ans);
		}
		
		sc.close();
	}
}
