package codeptit;

import java.math.BigInteger;
import java.util.Scanner;

public class J03011_Uocsochunglonnhatcuasonguyenlon {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            BigInteger a = sc.nextBigInteger(), b = sc.nextBigInteger();
            BigInteger result = a.gcd(b);
            if (result == a || result == b)
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}
