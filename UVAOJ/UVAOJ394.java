import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashMap;
import java.util.Scanner;

public class UVAOJ394 {
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
		
		HashMap<String, int[]> map=new HashMap<>();
		int N=sc.nextInt();
		int R=sc.nextInt();
		for(int i=0; i<N; i++) {
			String name=sc.next();
			int base=sc.nextInt();
			int size=sc.nextInt();
			int dim=sc.nextInt();
			int[][] u=new int[dim+1][2];
			for(int j=1; j<=dim; j++) {
				u[j][0]=sc.nextInt();
				u[j][1]=sc.nextInt();
			}
			int[] c=new int[dim+1];
			c[dim]=size;
			c[0]=base-c[dim]*u[dim][0];
			
			for(int j=dim-1; j>0; j--) {
				c[j]=c[j+1]*(u[j+1][1]-u[j+1][0]+1);
				c[0]-=c[j]*u[j][0];
			}
//			System.out.println(Arrays.toString(c));
			map.put(name, c);
			
		}
		for(int i=0; i<R; i++) {
			String name=sc.next();
			int[] c=map.get(name);
			int dim=c.length-1;
			int addr=c[0];
			name+="[";
			for(int j=1; j<=dim; j++) {
				int k=sc.nextInt();
				addr+=c[j]*k;
				name+=k+", ";
			}
		
			System.out.println(name.substring(0, name.lastIndexOf(','))+"] = "+addr);
		}
		sc.close();
	}
	
}
