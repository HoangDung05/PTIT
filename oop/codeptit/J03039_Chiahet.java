package codeptit;

import java.math.BigInteger;
import java.util.Scanner;

public class J03039_Chiahet {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            BigInteger a = sc.nextBigInteger(), b = sc.nextBigInteger();
            BigInteger k = a.gcd(b);
//            System.out.println(k);
            if (k.equals(a) || k.equals(b))
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}
