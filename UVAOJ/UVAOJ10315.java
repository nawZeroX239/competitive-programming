import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.StringTokenizer;

public class UVAOJ10315 {
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
		
		// ranks from 1 to 9, 1 lowest 9 highest
		String[] RANKS= {"2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"};
		int N=RANKS.length;
		HashMap<String, Integer> ranking=new HashMap<>();
		for(int i=0; i<RANKS.length; i++)
			ranking.put(RANKS[i], i+1);
		int I=0;
		// 0 black 1 white
		while(sc.hasNext()) {
			String line=sc.nextLine();
//			if(++I==58) System.out.println(line);
			StringTokenizer toks=new StringTokenizer(line);
			int[][] cnt=new int[2][N+1];
			boolean[] sorted= {true, true};
			boolean[] sameSuit= {true, true};
			int[] level=new int[2];

			for(int pass=0; pass<2; pass++) {
				String first="";
				int lastRank=-1;
				for(int i=0; i<5; i++) {
					String now=toks.nextToken();
					int rank=ranking.get(now.substring(0, 1));
					String suit=now.substring(1, 2);
					if(first.isEmpty() && lastRank==-1) {
						first=suit;
					}else {
						if(!first.equals(suit))
							sameSuit[pass]=false;

//						if(lastRank < rank && sorted[pass])
//							sorted[pass]=true;
//						else 
//							sorted[pass]=false;
					}
					cnt[pass][rank]++;
				}
			}
			
			{
				int a=-1;
				int b=-1;
				for(int i=1; i<=N; i++) {
					if(cnt[0][i]>1)
						sorted[0]=false;
					if(cnt[1][i]>1)
						sorted[1]=false;
					if(a<0 && cnt[0][i]>0) 
						a=i;
					if(b<0 && cnt[1][i]>0)
						b=i;
				}
				
				for(int i=a; i<a+5 && i<N; i++) {
					if(cnt[0][i]<1)
						sorted[0]=false;
				}
				for(int i=b; i<b+5 && i<N; i++)
					if(cnt[1][i]<1)
						sorted[1]=false;
				
				
			}
			
//			for(int pass=0; pass<2; pass++) {
//				for(int i=1; i<=N; i++)
//					System.out.print(cnt[pass][i]+" ");
//				System.out.println();
//			}
			
			for(int pass=0; pass<2; pass++)
				if(sameSuit[pass] && sorted[pass])
					level[pass]=9;
			
//			System.out.println(level[0]+" "+level[1]);
//			System.out.println(sameSuit[0]+" "+sameSuit[1]);
//			System.out.println(sorted[0]+" "+sorted[1]);

			int won=-1;
			// straight flush
			if(level[0]==9 && level[1]==9)
				won=highest(cnt, N);

			// if one of them is 9 then game is done
			if(level[0]==9 || level[1]==9) {
				if(level[0]>level[1])
					won=0;
				else if(level[0]<level[1])
					won=1;
			}
			
			if(won>-1) {
				out(won);
				continue;
			}
			
			
			// find duplicates
			HashMap<Integer, ArrayList<Integer>>[] dup=new HashMap[2];
			dup[0]=new HashMap<>();
			dup[1]=new HashMap<>();
			
			for(int i=1; i<=N; i++) {
				if(cnt[0][i]>1) {
					if(!dup[0].containsKey(cnt[0][i]))
						dup[0].put(cnt[0][i], new ArrayList<>());
					dup[0].get(cnt[0][i]).add(i);
					//dup[0].put(cnt[0][i], i);
				}
				
				if(cnt[1][i]>1) {
					if(!dup[1].containsKey(cnt[1][i]))
						dup[1].put(cnt[1][i], new ArrayList<>());
					dup[1].get(cnt[1][i]).add(i);
					//dup[1].put(cnt[1][i], i);
				}
			}
			
			// Four of a kind
			if(dup[0].containsKey(4) 
					&& dup[1].containsKey(4)) {

				if(dup[0].get(4).get(0)>dup[1].get(4).get(0))
					won=0;
				else if(dup[0].get(4).get(0)<dup[1].get(4).get(0))
					won=1;
				else
					won=2;
			}
			
			
			if(won<0 && dup[0].containsKey(4))
				won=0;
			if(won<0 && dup[1].containsKey(4))
				won=1;
			if(won>-1) {
				out(won);
				continue;
			}
			
			// full house
			if(dup[0].containsKey(3) && dup[0].containsKey(2)
					&& dup[1].containsKey(3) && dup[1].containsKey(2)) {
				if(dup[0].get(3).get(0)>dup[1].get(3).get(0))
					won=0;
				else if(dup[0].get(3).get(0)<dup[1].get(3).get(0))
					won=1;
				else
					won=2;
			}
			
			if(won<0 && dup[0].containsKey(3) && dup[0].containsKey(2))
				won=0;
			
			if(won<0 && dup[1].containsKey(3) && dup[1].containsKey(2))
				won=1;
			
			if(won>-1) {
				out(won);
				continue;
			}
			// flush
			if(sameSuit[0] && sameSuit[1]) {
				int i=N;
				// HIGH card rule
				while(cnt[0][i] == cnt[1][i] && i>0)
					i--;
				if(i<=1) 
					won=2;
				else if(cnt[0][i]>cnt[1][i]) 
					won=0;
				else
					won=1;
			}
			
			 if(won<0 && sameSuit[0])
				 won=0;
			 if(won<0 && sameSuit[1])
				 won=1;
			 if(won>-1) {
				 out(won);
				 continue;
			 }
			 
			 // Straight
			 if(sorted[0] && sorted[1]) {
//				 System.out.println("straight");
				 won=highest(cnt, N);
			 }
			 
			 if(won<0 && sorted[0])
				 won=0;
			 if(won<0 && sorted[1])
				 won=1;
			 if(won>-1) {
				 out(won);
				 continue;
			 }
			
			 // three of a kind
			 if(dup[0].containsKey(3)
					 && dup[1].containsKey(3)) {
				 if(dup[0].get(3).get(0)>dup[1].get(3).get(0))
					 won=0;
				 else if(dup[0].get(3).get(0)<dup[1].get(3).get(0))
					 won=1;
				 else
					 won=2;
			 }
			 
			 if(won<0 && dup[0].containsKey(3))
				 won=0;
			 if(won<0 && dup[1].containsKey(3))
				 won=1;
			 
			 if(won>-1) {
				 out(won);
				 continue;
			 }
			
			 // two pairs
			 if(dup[0].containsKey(2) && dup[0].get(2).size()==2
					 && dup[1].containsKey(2) && dup[1].get(2).size()==2) {
//				 System.out.println("two pair");
				 @SuppressWarnings("unchecked")
				ArrayList<Integer>[] ref=new ArrayList[2];
				 for(int i=0; i<2; i++) {
					 ref[i]=dup[i].get(2);
					 ref[i].sort((x, y)-> x-y);
				 }
//				 System.out.println(ref[0].toString());
//				 System.out.println(ref[1].toString());

				 won=2;
				 if(ref[0].get(1)==ref[1].get(1)) {
					 if(ref[0].get(0)>ref[1].get(0))
						 won=0;
					 else if(ref[0].get(0)<ref[1].get(0))
						 won=1;
					 else {
						 int x=-1;
						 int y=-1;
						 for(int i=1; i<=N; i++) {
							 if(x==-1 && cnt[0][i]==1)
								 x=i;
							 if(y==-1 && cnt[1][i]==1)
								 y=i;
						 }
						 
						 if(x>y) won=0;
						 else if(x<y) won=1;
					 }
				 } else {
					 if(ref[0].get(1)>ref[1].get(1))
						 won=0;
					 else if(ref[0].get(1)<ref[1].get(1))
						 won=1;
				 }
			 }

			 if(won<0 && dup[0].containsKey(2) && dup[0].get(2).size()==2)
				 won=0;
			 if(won<0 && dup[1].containsKey(2) && dup[1].get(2).size()==2)
				 won=1;
			 
			 if(won>-1) {
				 out(won);
				 continue;
			 }
			 
			 // Pair
			 if(dup[0].containsKey(2)
					 && dup[1].containsKey(2)) {

				int x=dup[0].get(2).get(0);
				int y=dup[1].get(2).get(0);
				won=2;
				if(x>y)
					won=0;
				else if(x<y)
					won=1;
				else
					for(int i=N; i>0 && won==2; i--) {
						if(x!=i && cnt[0][i]>cnt[1][i])
							won=0;
						
						if(y!=i && cnt[1][i]>cnt[0][i])
							won=1;
					}
			 }
			 
			 if(won<0&&dup[0].containsKey(2))
				 won=0;
			 if(won<0&&dup[1].containsKey(2))
				 won=1;
			 if(won>-1) {
				out(won);
				continue;
			 }
			 
			 won=highest(cnt, N);
			 out(won);
			
		}
		
		sc.close();
	}
	
	public static int highest(int[][] cnt, int N) {
		for(int i=N; i>0; i--)
			if(cnt[0][i] > cnt[1][i])
				return 0;
			else if(cnt[0][i] < cnt[1][i])
				return 1;
//			else if((cnt[0][i]==cnt[1][i]) 
//					&& (cnt[0][i]>0 && cnt[1][i]>0))
//				return 2; // tie
		return 2;
	}
	
	public static void out(int n) {
		if(n==0) System.out.println("Black wins.");
		else if(n==1) System.out.println("White wins.");
		else System.out.println("Tie.");
	}
}
