import java.util.Arrays;

public class MaxLengthSubsequence {
	public static void solve() {
		// can be further optimized using hashset
		int[] a= {2, 0, 6, 1, 5, 3, 7};
		int N=a.length;
		Arrays.sort(a);
		int l=1;
		int c=1;
		for(int i=1; i<N; i++) {
			if(Math.abs(a[i]-a[i-1])==1) {
				l++;
				if(l>c) c=l;
			} else l=1;
		}
		System.out.println(c);
	}
}
