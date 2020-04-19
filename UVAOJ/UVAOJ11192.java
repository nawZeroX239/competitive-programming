import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class UVAOJ11192 {
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
		
		
		while(true) {
			StringTokenizer toks=new StringTokenizer(br.readLine());
			int n=Integer.parseInt(toks.nextToken());
			if(n==0)
				break;
			
			String s=toks.nextToken();
			String ans="";
//			System.out.println(s);
			int N=s.length();
			n=N/n;
			for(int i=0; i<N; i+=n) {
//				System.out.println(s.substring(i, i+n));
				StringBuilder reverse=new StringBuilder(s.substring(i, i+n));
				ans=ans+reverse.reverse().toString();
			}
			System.out.println(ans);
		}
		
		
		br.close();
	}
}
