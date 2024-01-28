import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        System.out.println("Line 1 : A string array. First number is the size S of the array. Then S space separated strings follow which indicate the elements in the array.");

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        Solution solutionObj = new Solution();

        try {
            String line = reader.readLine();
            String[] params = line.split(" ", -1);
            String[] arrayInput = Arrays.stream(params, 1, params.length).toArray(String[]::new);
            String[] res = solutionObj.reorderLogs(arrayInput);

            System.out.println("sorted array is " + Arrays.toString(res));

        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }
}