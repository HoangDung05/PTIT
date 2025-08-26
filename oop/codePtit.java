import java.math.BigInteger;
import java.util.Scanner;

public class codePtit {
    static BigInteger gcd(BigInteger num1, BigInteger num2) {
        if (num2.equals(BigInteger.ZERO))
            return num1;
        return num1.gcd(num2);
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < t; i++) {
            String s1 = sc.nextLine(), s2 = sc.nextLine();
            BigInteger num1 = new BigInteger(s1);
            BigInteger num2 = new BigInteger(s2);
            System.out.println((num1.multiply(num2)).divide(gcd(num1, num2)));
        }
        
    }
}