import java.io.File;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Array1D6 {
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
		
		int N=sc.nextInt();
		int[] p=new int[N];
		Queue<Integer> q=new LinkedList<>();
		for(int i=0; i<N; i++)
			q.add(sc.nextInt());
		
		for(int i=0; i<N; i++)
			p[i]=sc.nextInt();
		int cnt=0;
		int k=0;
		while(q.size()>0) {
			if(q.peek()==p[k]) {
				q.remove();
				k++;
			} else {
				q.add(q.remove());
			}
			cnt++;
		}
		System.out.println(cnt);
		sc.close();
	}
}
