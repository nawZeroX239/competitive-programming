import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;

public class UVAOJ10205 {
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
		
//		Clubs 2,3,4, Ace
//		Diamonds 2,3,4, Ace
//		Hearts 2,3,4, Ace
//		Spades 2,3,4, Ace
		//  Jack, Queen, King, Ace.
		HashMap<Integer, String> map=new HashMap<>();
		
		String[] SUITS= {"Clubs", "Diamonds", "Hearts", "Spades"};
		String[] RANKS= {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
		int TOTAL=52;
		int T=Integer.parseInt(sc.nextLine());
		sc.nextLine();
		while(T>0) {
			if(!sc.hasNext()) break;
			int N=Integer.parseInt(sc.nextLine());
			String[] deck=new String[TOTAL+1];
			int idx=1;
			for(int i=0; i<SUITS.length; i++)
				for(int j=0; j<RANKS.length; j++, idx++)
					deck[idx]=RANKS[j]+" of "+SUITS[i];
			

			int[][] x=new int[N+1][TOTAL+1];
			for(int i=1; i<=N; i++)
				for(int j=1; j<=TOTAL; j++)
					x[i][j]=sc.nextInt();
			sc.nextLine();
			
			while(sc.hasNextLine()) {
				String[] aux=new String[TOTAL+1];
				String line=sc.nextLine();
				if(line.isEmpty()) break;
				int k=Integer.parseInt(line);
				for(int i=1; i<=TOTAL; i++) {
					idx=x[k][i];
					if (idx == i)
						continue;

					if (deck[i] != null) {
						String temp=deck[i];

						if (map.containsKey(idx))
							deck[i] = map.remove(idx);
						else {
							deck[i] = deck[idx];
							deck[idx] = null;
						}
						map.put(i, temp);
					} else {
						if (map.containsKey(idx))
							deck[i] = map.remove(idx);
						else {
							deck[i] = deck[idx];
							deck[idx] = null;
						}

					}
				}
			}
			
			for(int i=1; i<=TOTAL; i++)
				System.out.println(deck[i]);
			T--;
			if(T>0)	System.out.println();

		}

		sc.close();
	}
}
