package codeptit;

import java.util.*;

public class J03009_Tapturiengcuahaixau {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- > 0) {
            TreeSet<String> st = new TreeSet<>();
            String[] s1 = sc.nextLine().split("\\s");
            String[] s2 = sc.nextLine().split("\\s");
            Set<String> set2 = new HashSet<>(Arrays.asList(s2));
            for (String word : s1) {
                if (!set2.contains(word))
                    st.add(word);
            }
            for (String word : st)
                System.out.print(word + " ");
            System.out.println();
        }
    }
}


