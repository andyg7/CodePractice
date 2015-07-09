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
			char charSize = line.charAt(0);
			int officeSize = charSize - '0';
			System.out.println(officeSize);
			int[] office  = new int[officeSize];
			Worker aWorker = new Worker();
			processInput(line, office);
		}
	}
	private static void processInput(String s, int[] ar) {
		

	}

class Worker {

	private int age = 10;
	ArrayList<Integer> preferences = new ArrayList<Integer>();

	public Worker() {
	}	

	public Worker(String s) {

	}

	public int getNumberOfPreferences() {
		return preferences.size();
	}

}
