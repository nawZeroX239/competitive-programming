import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class UVAOJ12554 {
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
		
		int N=sc.nextInt();
		String[] song = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", 
				"you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};
		
		int K=song.length;
		ArrayList<String> guests = new ArrayList<>();
		
		for(int i=0; i<N; i++){
			guests.add(sc.next());
		}
		
		boolean end=false;
		for(int i=0, person=0; i<K; i++) {
			System.out.println(guests.get(person)+": "+song[i]);
			
			if(person+1>=N) {
				person=-1;
				end=true;
			}
			
			if(person==-1 && !end) i=-1; // everyone has already sang
			if(i+1==K && end == false) i=-1; // not everyone has sang yet
			person++;
		}
		sc.close();
	}

}
