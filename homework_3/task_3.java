import java.io.*;
import java.util.StringTokenizer;

public class Solution implements Runnable {

    private void solve() throws IOException {
        
        int n = nextInt();
        
        
        int k = nextInt();
        
        int[] arr = new int[n];
        int low = 0;
        int high = 0;
        
        for (int i = 0; i < n; i++) {
            arr[i] = nextInt();
            high = Math.max(high, arr[i]);
        }
        

        if (k != 1) {
            while (high - low > 1) {
                int possibleTime = low + (high - low ) / 2;
                long timeNeeded = 0;
                for (int i = 0; i < n; i++) {
                    if (arr[i] > possibleTime) {
                        timeNeeded += (arr[i] - possibleTime + (k - 2)) / (k - 1);
                    }
                }
                if (timeNeeded > possibleTime) {
                    low = possibleTime;
                } else {
                    high = possibleTime;
                }
            }
        }
        writer.println(high);
        
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



