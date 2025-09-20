package codeptit;

import java.util.HashMap;
import java.util.Scanner;

public class J03010_Diachiemail {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        HashMap<String, Integer> save = new HashMap<>();
        while (t-- > 0) {
            String[] s = sc.nextLine().trim().toLowerCase().split("\\s+");
            StringBuilder result = new StringBuilder();
            int len = s.length;
            result.append(s[len - 1].toLowerCase());
            for (int i = 0; i < len - 1; i++) {
                s[i].toLowerCase();
                result.append(s[i].charAt(0));
            }
            String user = result.toString();

            if (save.get(user) == null) {
                save.put(user, 1);
            } else {
                int time = save.get(user);
                save.put(user, time + 1);
                user += Integer.toString(time + 1);
            }
            System.out.println(user + "@ptit.edu.vn");
        }
    }
}


