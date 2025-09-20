package codeptit;

import java.util.Scanner;

public class J03040_Biensodep {
    public static boolean check1(String s) {
        for (int i = 0; i < s.length() - 1; i++) {
            int temp = (int) s.charAt(i + 1) - (int) s.charAt(i);
            if (temp <= 0)
                return false;
        }
        return true;
    }

    public static boolean check2(String s) {
        for (int i = 0; i < 2; i++) {
            if (s.charAt(i) != s.charAt(i + 1))
                return false;
        }
        if (s.charAt(3) != s.charAt(4))
            return false;
        return true;
    }

    public static boolean check3(String s) {
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != '6' && s.charAt(i) != '8')
                return false;
        }
        return true;
    }

    public static boolean check4(String s) {
        for (int i = 0; i < s.length() - 1; i++) {
            if ((int) s.charAt(i + 1) != (int) s.charAt(i))
                return false;
        }
        return true;
    }


    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String s = sc.next();
            String s1 = s.substring(5, 8) + s.substring(9);
            if (check4(s1) || check3(s1) || check2(s1) || check1(s1))
                System.out.println("YES");
            else
                System.out.println("NO");
        }
    }
}






