import java.io.*;
import java.util.*;
import java.math.*;

public class b {
    int n;
    int fat[205];

    public static BigInteger dp(int size) {
        if (size == 0) return 1;
        if (me[size] != null) return -1;
        for (int i = 1; i <= size; i++) 
            me[size].add(((fat[size.subtract(i)].divide(fat[i.subtract(1)])).pow(i)).multiply(
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a = in.nextInt();
        System.out.println(
    }
}

