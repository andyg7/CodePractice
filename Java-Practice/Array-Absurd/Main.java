import java.io.*;
public class Main {

	public static void main(String [] args) throws IOException {

		File file = new File(args[0]);
		BufferedReader buffer = new BufferedReader(new FileReader(file));
		String line;
		boolean firstRun = true;
		while((line = buffer.readLine()) != null) {
			line = line.trim();
			//Process line of input here
			if(firstRun == false) {
				System.out.println();
			} else {
				firstRun = false;
			}
			//System.out.println("line: " + line);
			String[] stringPoints = line.split(",");
			int numOfPoints = stringPoints.length;
			double[] points = new double[numOfPoints];
			for(int i = 0; i < numOfPoints; i++) {
				double tempDouble = Double.parseDouble(stringPoints[i]);
				int tempInt =
				Integer.parseInt(stringPoints[i]);
				points[i] = tempDouble;
			}
			int pointsSize = points.length;
			boolean validInput = true;
			if(pointsSize != 8) {
				validInput = false;
			} 

			if(validInput == true) {
				//printArray(points);
				double ax1 = points[0];
				double ay2 = points[1];

				double ax2 = points[2];
				double ay1 = points[3];

				double bx1 = points[4];
				double by2 = points[5];

				double bx2 = points[6];
				double by1 = points[7];
				if(ax2 < bx1 || ax1 > bx2 || ay2 < by1 || ay1 > by2) {
					System.out.print("False");
				} else {
					System.out.print("True");
				}	}

		}
	}

	public static void printArray(double[] array) {
		
		for(int i = 0; i < array.length; i++) {
			System.out.println(array[i]);
		}
	}
}
