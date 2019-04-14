import java.util.*;
import java.math.BigInteger;

public class LEC01_02 {
    public static void main (String[] args) {
        BigInteger f1 = BigInteger.ZERO;
        BigInteger f2 = BigInteger.ONE;
        BigInteger f3 = new BigInteger("0");
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        if (n == 0) 
            f3 = new BigInteger("0");
        else if (n == 1)
            f3 = new BigInteger("1");
        for (int i = 2; i <= n; ++i) {
            f3 = f1.add(f2);
            f1 = f2;
            f2 = f3;
        }
        System.out.println(f3);
    }
}
