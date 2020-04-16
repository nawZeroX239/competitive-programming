import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class UVAOJ414 {
	public static void main(String[] args){
		boolean local=false;
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
		
		while(true) {
			int row=Integer.parseInt(sc.nextLine());
			if(row==0)
				break;
			boolean xx=false;
			int[][] ptrs=new int[row][2];
			int right=Integer.MAX_VALUE;
			int left=0;
			ArrayList<String> li=new ArrayList<>();
			for(int i=0; i<row; i++){
				String line=sc.nextLine();
				int state=-1;
				for(int k=0; k<line.length(); k++)
					if(state==-1 && line.charAt(k)==' ') {
						ptrs[i][0]=k-1;
						state=0;
					}else if(line.charAt(k)!=' ' && state==0) {
						ptrs[i][1]=k;
						state=2;
					}
				left=Math.max(left, ptrs[i][0]);
				if(ptrs[i][1]>0)
					right=Math.min(right, ptrs[i][1]);
				if(state==-1)
					xx=true;
				li.add(line);
			}
			

			if(right==Integer.MAX_VALUE) {
				System.out.println(0);
				continue;
			}
//			System.out.println(left+" "+right);
//
//			for(int i=0; i<row; i++)
//				System.out.println(Arrays.toString(ptrs[i]));
			if(right>left && !xx)
			for(int i=0; i<row; i++) {
				ptrs[i][0]+=(right-left-1);
//				System.out.println(li.get(r).substring(ptrs[r][0]-1));

			}
			
			int r=0;
			while(li.get(r).charAt(ptrs[r][0]+1)==' ') {
//				System.out.println(li.get(r).substring(ptrs[r][0], ptrs[r][1]+1));
				ptrs[r][0]++;
				r++;
				if(r>=li.size())
					r=0;
			}
			
			
			if(r>0)
				for(r-=1;r>=0; r--)
					ptrs[r][0]--;
			
			int ans=0;
			for(int i=0; i<row; i++)
				if(ptrs[i][1]-ptrs[i][0]>0)
					ans+=ptrs[i][1]-ptrs[i][0]-1;
			
			System.out.println(ans);
			
		}
		
		sc.close();
	}
	
}
