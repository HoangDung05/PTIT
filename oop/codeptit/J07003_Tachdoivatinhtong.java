package codeptit;

import java.io.File;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.Scanner;

public class J07003_Tachdoivatinhtong {
    public static void solve(String s) {
        int len = s.length();
        BigInteger tong = BigInteger.ZERO;
        while (len > 1) {
            BigInteger x = new BigInteger(s.substring(0, len / 2));
            BigInteger y = new BigInteger(s.substring(len / 2));
            tong = x.add(y);
            s = tong.toString();
            len = (s).length();
            System.out.println(s);
        }
    }

    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(new File("DATA.in"));
            while (sc.hasNextLine()) {
                String s = sc.nextLine();
                solve(s);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }


    }
}
