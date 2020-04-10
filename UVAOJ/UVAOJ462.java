import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class UVAOJ462 {
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
		
		while(sc.hasNext()) {
			int[] cnt=new int[4], suits=new int[4]; // 0 spades 1 heart 2 diamond 3 clubs
			boolean[] stops=new boolean[4];// 0 spades 1 heart 2 diamond 3 clubs
			int _567=0;
			int pts=0;
			for(int i=0; i<13; i++) {
				String q=sc.next();
				char suit=q.charAt(1);
				char rank=q.charAt(0);
				
				pts+=getPoint(rank);
				if(suit=='S') {
					cnt[0]++;
					suits[0]=flipBit(suits[0], rank);
				}else if(suit=='H') {
					suits[1]=flipBit(suits[1], rank);
					cnt[1]++;
				}else if(suit=='D') {
					suits[2]=flipBit(suits[2], rank);
					cnt[2]++;
				}else {
					// clubs
					suits[3]=flipBit(suits[3], rank);
					cnt[3]++;
				}
			}
			
			int p;
			for(int i=0; i<4; i++) {
				// #2
				p=getPos('K');
				if(cnt[i]<2 && (suits[i]&(1<<p))> 0)
					pts--;
			
				// #3
				p=getPos('Q');
				if(cnt[i]<=2 && (suits[i]&(1<<p))> 0)
					pts--;
		
				// #4
				p=getPos('J');
				if(cnt[i]<=3 && (suits[i]&(1<<p))> 0)
					pts--;
				
				// #5
				if(cnt[i]==2) _567++;
				else if(cnt[i]<=1) _567+=2;
				// last 
				stops[i]=isSuitStops(suits[i], cnt[i]);

			}

//			System.out.println("pts:"+pts+" _567:"+_567);
//			System.out.println("suit stops "+stops[0]+" "+stops[1]+" "+stops[2]+" "+stops[3]);
			if(isAllSuitStops(stops) && pts>=16) {
				System.out.println("BID NO-TRUMP");
				continue;
			}
			pts+=_567;
			if(pts>=14) 
				System.out.println("BID "+getLongestSuit(cnt));
			else 
				System.out.println("PASS");
		}
		sc.close();
	}
	public static String getLongestSuit(int[] cnt) {
		int maxIndex=0;
		for(int i=1; i<4; i++)
			if(cnt[i]>cnt[maxIndex])
				maxIndex=i;
		if(maxIndex==1) return "H";
		else if(maxIndex==2) return "D";
		else if(maxIndex==3) return "C";
		return "S";
	}
	
	public static boolean isAllSuitStops(boolean[] suits) {
		return suits[0]==true && suits[1]==true && suits[2]==true && suits[3]==true;
	}
	
	public static boolean isSuitStops(int suit, int cnt) {
		int a=suit&(1<<getPos('A'));
		if(a>0) return true;
		int b=suit&(1<<getPos('K'));
		if(b>0 && cnt>1) return true;
		int c=suit&(1<<getPos('Q'));
		if(c>0 && cnt>2) return true;
		
		return false;
	}
	
	public static int getPoint(char c) {
		int pt=0;
		if(c=='A') {
			pt=4;
		}else if(c=='K') {
			pt=3;
		}else if(c=='Q') {
			pt=2;
		}else if(c=='J') {
			pt=1;
		}
		
		return pt;
	}
	
	public static int getPos(char c) {
		int pos=0;
		if(c=='A') {
			pos=12;
		}else if(c=='K') {
			pos=11;
		}else if(c=='Q') {
			pos=10;
		}else if(c=='J') {
			pos=9;
		}else if(c=='T') {
			pos=8;
		}else {
			pos=c-'2';
		}
		
		return pos;
	}
	
	public static int flipBit(int n, char c) {
		return n|(1<<getPos(c));
	}
}
