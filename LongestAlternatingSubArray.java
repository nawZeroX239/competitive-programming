
public class LongestAlternatingSubArray {
	public static void solve(){
		int[] a= {1, -1, 1, -1, 1, -1, 1, -1, 1};
		int N=a.length;
		int l=1;
		int c=1;
		int high=0;
		for(int i=1; i<N; i++) {
			int x=a[i-1];
			int y=a[i];
			if((x>=0&&y>=0)||(x<0&&y<0)) {
				if(l>c) {
					c=l;
					high=i-1;
				}
				l=1;
			} else l++;
		}
		if(l>c) {
			c=l;
			high=N-1;
		}	
		System.out.println(c+" low:"+(high-c+1)+" high:"+high);
	}
}
