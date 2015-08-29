import java.io.*;
import java.util.*;
public class Main {
	public static void main (String[] args) throws IOException {
		File file = new File(args[0]);
		BufferedReader buffer = new BufferedReader(new
				FileReader(file));
		String line;
		while ((line = buffer.readLine()) != null) {
			line = line.trim();
			// Process line of input Here
			System.out.println(line);
			int[][] arr = new int[5][6];
			int numOfJobs = Character.getNumericValue(line.charAt(0));
			int[][] graph = new int[numOfJobs + 2][numOfJobs + 2];
			String nodeInfo = line.substring(3, line.length());
			//System.out.println(nodeInfo);
			processInput(nodeInfo, graph, numOfJobs);
		}
	}

	private static void processInput(String s, int[][] ar, int jobs) {

		int jobsCounter = 0;
		int counter = 0;
		while(jobsCounter < jobs) {
			if(s.substring(counter, counter + 1).equals("[")) {
				counter++;
				jobsCounter++;
				int num = 0;
				String number = "";
				while(!s.substring(counter, counter + 1).equals("]")) {
					if(s.substring(counter, counter + 1).equals(",")) {
						System.out.println(number);
						number = "";
						counter++;
					} else {
						number+=s.substring(counter, counter + 1);
					}
					counter++;
				}
				System.out.println(number);
			}
			counter++;
		}
	}
}
