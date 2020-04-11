import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;

public class UVAOJ555 {
	
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
		
		// < T < J < Q < K < A
		String[] RANKS= {"2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"};
		String[] PLAYERS= {"S", "W", "N", "E"};
		String[] SUITS= {"C", "D", "S", "H"};
		HashMap<String, Integer> players=new HashMap<>();
		HashMap<String, Integer> suits=new HashMap<>();
		HashMap<String, Integer> ranks=new HashMap<>();
		for(int i=0; i<PLAYERS.length; i++) {
			players.put(PLAYERS[i], i);
			suits.put(SUITS[i], i);
		}
		
		for(int i=0; i<RANKS.length; i++)
			ranks.put(RANKS[i], i);
		
		while(sc.hasNext()) {
			int[][][] m=new int[4][4][13]; // [player][suits][ranks]
			
			
			String dealer=sc.nextLine();
			if(dealer.equals("#")) break;
			String ins="";
			for(int i=0; i<2; i++)
				ins=ins+sc.nextLine();
			int next=(players.get(dealer)+1)%4;
			for(int i=0; i<ins.length(); i+=2) {
				String s=ins.substring(i, i+1);
				String r=ins.substring(i+1, i+2);
				m[next][suits.get(s)][ranks.get(r)]++;
				next++;
				if(next>=4) next=0;
			}

			for(int i=0; i<PLAYERS.length; i++) {
				boolean before=false;
				System.out.print(PLAYERS[i]+": ");
				for(int j=0; j<SUITS.length; j++)
					for(int k=0; k<RANKS.length; k++)
						if(m[i][j][k]>0) {
							if(before) System.out.print(" ");
							System.out.print(SUITS[j]+RANKS[k]);
							before=true;
						}
				System.out.println();
				
			}
		}
		sc.close();
	}

}
