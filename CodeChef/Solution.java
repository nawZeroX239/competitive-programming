import java.util.*;

public class Solution {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		ArrayList<String> li = new ArrayList<>();
		int L = 7;
		int[] left = new int[L];
		int[] right = new int[L];
		
		for(int i = 0; i < L; i++) left[i] = right[i] = 0;
		for(int i = 0; i < N; i++){
			int Q = sc.nextInt();
			int[] arr = new int[Q];
			arr[0] = sc.nextInt();
			left[0]++;
			boolean skip = false;
			
			if(Q < 13) {
				li.add("no");
				continue;
			}
			for(int j = 1; j < Q; j++) {
				arr[j] = sc.nextInt();
				
				if(skip) continue;
				if(arr[j] >= 1 && arr[j] <= 7) {
					if(arr[j] != 7) {
						if(left[L-1] < 1 && right[L-1] < 1) {
							if(arr[j] < arr[j-1]) skip = true;
							else left[arr[j]-1]++;
							
						}if(left[L-1] > 0 && right[L-1] > 0 ) {
							if(arr[j] > arr[j-1]) skip = true;
							else right[arr[j]-1]++;
						}
					} else {
						left[arr[j]-1]++;
						right[arr[j]-1]++;
					}
					
//					if((count[k-1] <= 0 && arr[j] < arr[j-1]) &&
//							(count[k-1] > 0 && arr[j] > arr[j-1])){
//						skip = true;
//					}
					
				} else {
					skip = true;
				}
			
			}
			for(int j = 0; j < L-1; j++)
				if(left[j] != right[j]) {
					skip = true;
					break;
				}
			if(skip) li.add("no");
			else li.add("yes");
		}
//		for(int i=0; i < L; i++) System.out.println("R:"+right[i]+" L:"+left[i]);
		for(String i : li) {
			System.out.println(i);
		}
	}

}