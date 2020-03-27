import java.util.Stack;

public class Permutation {
    public static boolean[] x;
    public static Stack<Integer> aux = new Stack<Integer>();
    public static int N;

    public static void compute(int[] arr) {
        N = arr.length;
        x = new boolean[N];
        compute(arr, 0);
    }

    private static void compute(int[] arr, int i) {
        if(i >= N) {
            System.out.println(aux.toString());
            return ;
        }

        for(int j = 0; j < N; j++) {
            if(!x[j]) {
                x[j] = true;
                aux.push(arr[j]);
                compute(arr, i+1);
                aux.pop();
                x[j] = false;
            }
        }
    }
}
