import java.io.*;
import java.lang.Math;
import java.text.DecimalFormat;
public class Main {
	public static void main (String[] args) throws IOException {
		File file = new File(args[0]);
		BufferedReader buffer = new BufferedReader(new FileReader(file));
		String line;
		int lineCounter = 0;
		boolean firstRun = true;
		while ((line = buffer.readLine()) != null) {

			line = line.trim();
			// Process line of input Here
			int numberOfPoints = Integer.parseInt(line);
			if(numberOfPoints == 0){
				break;
			}
			if(firstRun == false){
				System.out.print('\n');
			} else {
				firstRun = false;
			}
			double[][] points = new double[numberOfPoints][2];
			for(int i = 0; i < numberOfPoints; i++) {
				line = buffer.readLine();
				line = line.trim();
				String[] pt  = line.split(" ");
				points[i][0] = Double.parseDouble(pt[0]);
				points[i][1] = Double.parseDouble(pt[1]);
			}
			double minimumDistance = getDistance(points,0);
			if(minimumDistance < 10000) {
				int multipliedDis = (int)(minimumDistance * 100000);
				//System.out.println(multipliedDis);
				if((multipliedDis % 10) >= 5) {
					multipliedDis++;
					//System.out.println("fogggg");
				}
				minimumDistance = (double) multipliedDis / 100000;
				if(minimumDistance - multipliedDis == 0.0) {
					System.out.print(multipliedDis);
			//	System.out.println("heee");
				} else {
					//System.out.print(minimumDistance);
									DecimalFormat df = new DecimalFormat("#0.0000");
									System.out.print(df.format(minimumDistance));
				}	
			}
			else {
				System.out.print("INFINITY");
			}	
		}
	}
	public static double getDistance(double[][] arr, int index) {
		double min = -1;
		//System.out.println("o");
		if((index - arr.length) == -2){
			//System.out.println("o");
			double x1 = arr[index][0];
			double y1 = arr[index][1];
			double x2 = arr[index+1][0];
			double y2 = arr[index+1][1];
			return Math.sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
		}
		for(int i = index; i < arr.length - 1; i++) {
			//System.out.println("o");
			double x1 = arr[index][0];
			double y1 = arr[index][1];
			double x2 = arr[i+1][0];
			double y2 = arr[i+1][1];
			double tempMin = Math.sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
			if(min == -1 || tempMin < min){
				min = tempMin;
			}
		}

		double returnedMin = getDistance(arr, index + 1);
		if(returnedMin < min) {
			return returnedMin;
		}
		return min;
	}	
}
