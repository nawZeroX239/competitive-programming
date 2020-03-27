import java.util.Stack;

public class Subset {
    public static int N;
    public static Stack<Integer> aux = new Stack<Integer>();

    public static void compute(int[] arr) {
        N = arr.length;
        compute(arr, 0);
    }

    private static void compute(int[] arr, int i) {
        if(i >= N) return;
        aux.push(arr[i]);
        System.out.println(aux.toString());
        compute(arr, i+1);
        aux.pop();
        compute(arr, i+1);
    }
}
