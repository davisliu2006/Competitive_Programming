import java.io.*;
import java.util.*;

/*Class-Based Version*/
class FastScanner {
    BufferedReader br;
    StringTokenizer st;

    FastScanner(InputStream in) {
        br = new BufferedReader(new InputStreamReader(in));
    }
    FastScanner(File file) {
        try {
            br = new BufferedReader(new FileReader(file));
        } catch (FileNotFoundException e) {}
    }

    String next() {
        try {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine().trim());
            return st.nextToken();
        } catch (IOException e) {return "";}
    }
    int nextInt() {return Integer.parseInt(next());}
    long nextLong() {return Long.parseLong(next());}
    double nextDouble() {return Double.parseDouble(next());}
    String nextLine() {
        try {return br.readLine().trim();}
        catch (IOException e) {return "";}
    }

    void close() {
        try {br.close();}
        catch (IOException e) {}
    }
}

/*Main*/
public class BufferedReaderTemplate {
    public static void main(String[] args) throws IOException {
        int n = readInt();
    }

    /*Standard BufferedReader Template*/
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
    static long readLong() throws IOException {
        return Long.parseLong(next());
    }
    static int readInt() throws IOException {
        return Integer.parseInt(next());
    }
    static double readDouble() throws IOException {
        return Double.parseDouble(next());
    }
    static char readCharacter() throws IOException {
        return next().charAt(0);
    }
    static String readLine() throws IOException {
        return br.readLine().trim();
    }
}
