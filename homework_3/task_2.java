import java.io.*;
import java.util.StringTokenizer;

public class Solution implements Runnable {

    private void solve() throws IOException {
        
        int N = nextInt();
        long[] arr = new long[N];
        
        for(int i = 0; i < N; ++i) {
            arr[i] = nextLong();
        }
        
        int Q = nextInt();
        for(int q = 0; q < Q; ++q) {
            long target = nextLong();
            int leftId = doLeftBoundBinarySearch(arr,target);
            int rightId = doRightBoundBinarySearch(arr, target);
            writer.println(leftId + " " + rightId);
        }
    }
    
    private static int doLeftBoundBinarySearch(long[] arr, long target) {
        int leftId = -1;
        
        int low = 0;
        int high = arr.length - 1;
        
        while(low <= high) {
            int mid = low + ( high - low ) / 2;
            if(arr[mid] == target) {
                leftId = mid + 1;
                high = mid - 1;
            } else if(arr[mid] > target) {
                high = mid - 1;
            } else low = mid + 1;
        }
        return leftId;
    }
    
    private static int doRightBoundBinarySearch(long[] arr, long target) {
        int rightId = -1;
        
        int low = 0;
        int high = arr.length - 1;
        
        while(low <= high) {
            int mid = low + ( high - low ) / 2;
            if(arr[mid] == target) {
                rightId = mid + 1;
                low = mid + 1;
            } else if(arr[mid] > target) {
                high = mid - 1;
            } else low = mid + 1;
        }
        return rightId;
    }
    
    

    public static void main(String[] args) {

        new Solution().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;
    //    BufferedWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
//                                             reader = new BufferedReader(new FileReader("input.txt"));
            tokenizer = null;
            writer = new PrintWriter(System.out);
//            writer = new PrintWriter("output.txt");
//                            writer = new BufferedWriter(System.out);
//                        writer = new BufferedWriter(new OutputStreamWriter(System.out));
            solve();
            reader.close();
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.exit(1);
        }
    }

    int nextInt() throws IOException {

        return Integer.parseInt(nextToken());
    }

    long nextLong() throws IOException {
        return Long.parseLong(nextToken());
    }

    double nextDouble() throws IOException {
        return Double.parseDouble(nextToken());
    }

    String nextToken() throws IOException {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }

        return tokenizer.nextToken();
    }

}



