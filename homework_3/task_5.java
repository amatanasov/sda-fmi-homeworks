import java.io.*;
import java.util.StringTokenizer;

public class Solution implements Runnable {
    
    static class Item implements Comparable<Item> {
        
        int value;
        int weight;
        double diff;

        Item(int value, int weight) {
            this.value = value;
            this.weight = weight;
        }

        public void initDifference(double alpha) {
            this.diff = value - alpha * weight;
        }

        public int compareTo(Item other) {
            return Double.compare(diff, other.diff);
        }
    }

    static void kth(Item[] items, int left, int right, int what) {
        Item pivot = items[(left + right) >>> 1];
        int l = left, r = right;
        while (l <= r) {
            while (items[l].compareTo(pivot) < 0) ++l;
            while (items[r].compareTo(pivot) > 0) --r;
            if (l <= r) {
                Item tmp = items[l];
                items[l] = items[r];
                items[r] = tmp;
                ++l;
                --r;
            }
        }
        if (left < r && what <= r) {
            kth(items, left, r, what);
        } else if (l < right && what >= l) {
            kth(items, l, right, what);
        }
    }
    
    private void solve() throws IOException {
        
        int n = nextInt();
        int k = nextInt();

        Item[] items = new Item[n];

        double max = 0;
        double min = 1_000_000_009;
        
        for (int i = 0; i < n; ++i) {
            
            int v = nextInt();
            int w = nextInt();
            items[i] = new Item(v, w);
            
            double rate = (double) v / w;
            
            max = Math.max(max, rate + 1);
            min = Math.min(min, rate);
            
        }
        
        for (int t = 0; t < 64; ++t) { // Double bits count is enough :)
            double mid = min + ( max - min ) / 2;
            
            if (mid == min || mid == max) {
                break;
            }
            
            for (Item i : items) {
                i.initDifference(mid);
            }
            
            kth(items, 0, n - 1, n - k);
            
            int sumv = 0, sumw = 0;
            for (int i = n - k; i < n; ++i) {
                sumv += items[i].value;
                sumw += items[i].weight;
            }
            if (sumv >= sumw * mid) {
                min = mid;
            } else {
                max = mid;
            }
        }
        for (Item i : items) {
            i.initDifference(min);
        }
        kth(items, 0, n - 1, n - k);
        
        long sum = 0;
        
        for (int i = n - k; i < n; ++i) {
            sum += items[i].value;
        }

        writer.println(sum);
        
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



