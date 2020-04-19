import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.TreeMap;

public class UVAOJ755 {
	public static void main(String[] args) throws IOException {
		boolean local=false;
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		if(local) {
			br.close();
			try {
				if(args.length<1) throw new IllegalArgumentException();
				br=new BufferedReader(new FileReader(args[0]));
				
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			} catch (IllegalArgumentException e){
				 br=new BufferedReader(new InputStreamReader(System.in));
			}
		}
//		A, B, and C map to 2
//		D, E, and F map to 3
//		G, H, and I map to 4
//		J, K, and L map to 5
//		M, N, and O map to 6
//		P, R, and S map to 7
//		T, U, and V map to 8
//		W, X, and Y map to 9
		HashMap<Character, Integer> map=new HashMap<>();
		String[] a= {"ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY"};
		for(int i=0, x=2; i<a.length; i++, x++)
			for(int  j=0; j<a[i].length(); j++)
				map.put(a[i].charAt(j), x);
		
		int set=Integer.parseInt(br.readLine());
		TreeMap<String, Integer> cnts=new TreeMap<>();
		while(set>0) {
			br.readLine();
			int n=Integer.parseInt(br.readLine().replaceAll("\\s",""));
			int X=0;
			for(int i=0; i<n; i++) {
				String s=br.readLine();
				String num="";
				char c;
				for(int k=0; k<s.length(); k++) {
					c=s.charAt(k);
					
					if(c=='-')
						continue;
					
					if(c>='0' && c<='9')
						num=num+c;
					else {
//						System.out.println(map.containsKey(c)+" "+c);
						if(map.containsKey(c))
							num=num+map.get(c);
					}
				}
				if(cnts.containsKey(num))
					cnts.put(num, cnts.get(num)+1);
				else {
					X++;
					cnts.put(num, 1);
				}
//				System.out.println(num);
			}
			
			if(X==n)
				System.out.println("No duplicates.");
			else
				cnts.forEach((k, c)->{
					if(c>1)
						System.out.println(k.substring(0, 3)+"-"+k.substring(3)+" "+c);
				});
			
			cnts.clear();
			set--;
			if(set>0)
				System.out.println();
		}
		
		br.close();
	}

}
