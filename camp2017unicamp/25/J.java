import java.io.*;
import java.util.*;
import java.math.*;

public class J {

    public static boolean hasDot(String x) {
        for(int i = 0; i < x.length(); i++)
            if(x.charAt(i) == '.') return true;
        return false;
    }

    public static int getDec(String x) {
        for(int i = 0; i < x.length(); i++) {
            if(x.charAt(i) == '.') return x.length() - i - 1;
        }
        return 0;
    }

    public static String f(String x, int n) {
        String ret = x;
        for(int i = 0; i < n; i++) ret += "0";
        return ret.replaceAll("\\.", "");
    }

    public static void main (String[] args) {
        Scanner in = new Scanner(System.in);
        String xS = in.next();
        String yS = in.next();
        if(!hasDot(xS)) xS += ".0";
        if(!hasDot(yS)) yS += ".0";
        int dotY = getDec(yS);
        int dotX = getDec(xS);
        BigInteger x = new BigInteger(f(xS, dotY - dotX));
        BigInteger y = new BigInteger(f(yS, dotX - dotY));
        System.out.println(x.divide(y));
    }
}
