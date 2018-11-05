import java.io.*;
import java.util.StringTokenizer;

public class Solution implements Runnable {

    private void solve() throws IOException {
        
        int T = nextInt();
        for(int t = 0; t < T; ++t) {
            int N = nextInt();
            int res = 0;
            while(N > 0) {
                N /= 2;
                ++res;
            }
            writer.println(res);
        }
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



