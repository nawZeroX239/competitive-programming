
import java.util.Scanner;

public class UVAOJ12289 {
	
	public static void solve(){
		Scanner sc = new Scanner(System.in);
		String[] a = {"one", "two", "three"};
		int T=sc.nextInt();
		while(T>0) {
			String s = sc.next();
			for(int i=0; i < 3; i++) {
				int diff=0;
				
				if(a[i].length() == s.length()) {
					if(a[i].equals(s)) {
						System.out.println(i+1);
						break;
					}
					for(int l=0; l<a[i].length(); l++)
						if(a[i].charAt(l) != s.charAt(l))
							diff++;
				}
				if(diff == 1) {
					System.out.println(i+1);
					break;
				}
				
			}
			
			T--;
		}
		
	}
}
