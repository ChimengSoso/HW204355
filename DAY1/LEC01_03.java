import java.util.*;
import java.math.BigInteger;

public class LEC01_03 {
    public static void main (String[] args) {
        BigInteger f = BigInteger.ONE;
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 1; i <= n; ++i) {
            f = f.multiply(new BigInteger(i+""));
        }
        System.out.println(f);
    }
}
