mport java.io.*;
import java.util.StringTokenizer;

public class Solution implements Runnable {

    private void solve() throws IOException {
        
        int N = nextInt();
        int[] heights = new int[N];
        int[] prices = new int[N];
        
        for(int i = 0; i < N; ++i) heights[i] = nextInt();
        for(int i = 0; i < N; ++i) prices[i] = nextInt();
      
        int low = 0;
        int high = 10001;
        while (low < high) {
            int mid = low + ( high - low ) / 2;
    
            if (computeCost(heights, prices, mid) < computeCost(heights, prices, mid + 1)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        
        long pointA = computeCost(heights, prices, low);
        long pointB = computeCost(heights, prices, low + 1);
        
        writer.println(Math.min(pointA, pointB));
    }
                                              
    private long computeCost(int[] heights, int[] prices, int desiredHeight) {
        long totalCost = 0;
        for(int i = 0; i < heights.length; i++) {
                totalCost += (long)prices[i] * (long)(Math.abs(heights[i] - desiredHeight));
        }
        return totalCost;
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



