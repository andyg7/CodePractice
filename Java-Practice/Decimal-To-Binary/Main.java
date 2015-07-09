import java.io.*;
import java.lang.Math;
public class Main {
	public static void main (String[] args) throws IOException {
		File file = new File(args[0]);
		BufferedReader buffer = new BufferedReader(new
				FileReader(file));
		String line;
		boolean firstRun = true;
		while ((line = buffer.readLine()) != null) {
			line = line.trim();
			if(firstRun == true) {
				firstRun = false;
			} else {
				System.out.print('\n');
			}
			// Process line of input Here
			//System.out.println(line);
			int decimalNumber = Integer.parseInt(line);
			String x = convertToBinary(decimalNumber);
			System.out.print(x);
		}
	}
	private static String convertToBinary(int i) {

		double decimalNum = (double) i;
		if(i == 0) {
			return "0";
		}
		
		double counter = 0;
		int num = 1;
		while(num <= i) {
			counter++;
			num = num * 2;
		}
		num = num / 2;
		String binaryString = "";
		while(counter > 0) {
			if(num <= decimalNum) {
				binaryString+="1";
				decimalNum = decimalNum - num;
				num = num / 2;
			} else {
				binaryString+="0";
				num = num / 2;
			}
			counter--;
		}	
		return binaryString;

	}
}

