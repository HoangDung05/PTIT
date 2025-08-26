package codeptit;

import java.math.BigInteger;
import java.util.Scanner;

public class J02008_Boisonhonhatcuansonguyenduongdautien {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            BigInteger ans = BigInteger.ONE;
            for (int i = 2; i <= n; i++) {
                ans = ans.multiply(BigInteger.valueOf(i)).divide(ans.gcd(BigInteger.valueOf(i)));
            }
            System.out.println(ans);
        }
    }
}
