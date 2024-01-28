import java.util.Arrays;
import java.util.Comparator;

class LogComparator implements Comparator<String> {
    @Override
    public int compare(String a, String b){
        String[] a1 = a.split("-", 2);
        String[] b1 = b.split("-", 2);
        char ac = a1[1].charAt(0);
        char bc = b1[1].charAt(0);

        if(ac >= 'a' && bc >= 'a'){
            return a1[1].compareTo(b1[1]);
        }
        else if(ac >= 'a') return -1;
        else if(bc >= 'a') return 1;
        else return 0;

    }
}
public class Solution {
    public String[] reorderLogs(String[] A) {
        Arrays.sort(A, new LogComparator());

        return A;
    }
}
