import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.StringTokenizer;

public class UVAOJ11340 {
	public static void main(String[] args) throws IOException {
//		Scanner sc;
		boolean local=true;
//		sc=new Scanner(System.in);
//		if(local) {
//			sc.close();
//			try {
//				if(args.length<1) throw new IllegalArgumentException();
//				sc=new Scanner(new File(args[0]));
//			} catch (FileNotFoundException e) {
//				e.printStackTrace();
//			} catch (IllegalArgumentException e){
//				sc=new Scanner(System.in);
//			}
//		}
//		
		
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
		
		
		int T=Integer.parseInt(br.readLine());
		while(T>0) {
			HashMap<Character, Integer> charValue=new HashMap<>();
			int K=Integer.parseInt(br.readLine());
			
			for(int i=0; i<K; i++) {
				StringTokenizer toks=new StringTokenizer(br.readLine());
				charValue.put(toks.nextToken().charAt(0), Integer.parseInt(toks.nextToken()));
			}
			int M=Integer.parseInt(br.readLine());
			int ans=0;
			
			for(int i=0; i<M; i++) {
				String line=br.readLine();
				for(int k=0; k<line.length(); k++)
					if(charValue.containsKey(line.charAt(k)))
						ans=ans+charValue.get(line.charAt(k));
			}
			System.out.printf("%.2f$\n", ans/100.0);
			T--;
		}
		
		br.close();
	}
}
