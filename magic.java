import java.io.*;
import java.util.*;

public class Main implements Runnable {

    private void solve() throws IOException {

        int K = nextInt();
        int N = nextInt();
        int[] arr = new int[N];
        for(int i = 0; i < N; ++i) {
            arr[i] = nextInt();
        }
        
        for(int i = 0; i < N / 2; ++i) {
            int temp = arr[i];
            arr[i] = arr[N - i - 1];
            arr[N-i-1] = temp;
        }

        boolean isFound = false;
        
        for(int i = 0; i < (1 << 5); ++i) {

            for(int a = 0; a < Math.min(N,( 1 << 11 )); ++a) {
                for(int b = a + 1; b < Math.min(N,(1 << 11)); ++b) {

                    if(arr[a] + arr[b] == K) {
                        isFound = true;
                    }
                }
            }
            
            
            for(int idx = 0; idx < N; ++idx) {
                int r = (int) (Math.random() * (idx + 1));
                int temp = arr[r];
                arr[r] = arr[idx];
                arr[idx] = temp;
            }
            
        }

        writer.println(isFound);
      
    }

    public static void main(String[] args) {

        new Main().run();
    }

    BufferedReader reader;
    StringTokenizer tokenizer;
    PrintWriter writer;

    public void run() {
        try {
            reader = new BufferedReader(new InputStreamReader(System.in));
//            reader = new BufferedReader(new FileReader("task_4b.txt"));
            tokenizer = null;
            writer = new PrintWriter(System.out);
//            writer = new PrintWriter("task_4b_out.txt");
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
        while(tokenizer == null || !tokenizer.hasMoreTokens()) {
            tokenizer = new StringTokenizer(reader.readLine());
        }

        return tokenizer.nextToken();
    }
}