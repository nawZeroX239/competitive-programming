
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public class UVAOJ12250 {
	
	public static void solve() throws IOException{
		BufferedReader br = new BufferedReader(
									new InputStreamReader(System.in));
		HashMap<String, String> map = new HashMap<String, String>();
		map.put("HELLO","ENGLISH");
		map.put("HOLA", "SPANISH");
		map.put("HALLO", "GERMAN");
		map.put("BONJOUR", "FRENCH");
		map.put("CIAO", "ITALIAN");
		map.put("ZDRAVSTVUJTE", "RUSSIAN");
		String L;
		int i = 1;
		while((L = br.readLine()) != null) {
			if(L.equals("#")) break;
			System.out.print("Case "+i+": ");
			if(map.containsKey(L)) {
				System.out.print(map.get(L));
			} else {
				System.out.print("UNKNOWN");
			}
			System.out.println();
			i++;
		}
		
	}
}
