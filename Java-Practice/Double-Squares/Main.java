import java.io.*;
import java.lang.Math;
public class Main {
	public static void main(String[] args) throws IOException {
		File file = new File(args[0]);
		BufferedReader buffer = new BufferedReader(new FileReader(file));
		String line;
		boolean firstRun = true;
		line = buffer.readLine();
		while((line = buffer.readLine()) != null) {
			line = line.trim();
			//Process line of input here
			if(firstRun == true) {
				firstRun = false;
			} else {
				System.out.println();
			}
			//System.out.println(line);
			int num = Integer.parseInt(line);
			if(isPerfectSquare(num) == true) {
				//System.out.println("is a perfect square");
			}

			int startingInt = startingInt(num);
			int lastInt = lastInt(num);
			//System.out.println("starting int: " + startingInt);
			//System.out.println("last int " + lastInt);
			int tally = findDoubleSquares(num,
			startingInt, lastInt);
			System.out.print(tally);
		}
	}


	public static int findDoubleSquares(int sum, int firstNum, int
	lastNum) {
		
		int tally = 0;
		for(int i = firstNum; i >= lastNum; i--) {
			int tempNum = i * i;
			int result = sum - tempNum;
			if(isPerfectSquare(result) == true) {
				tally++;
			}
		}

		return tally;
	}

	public static boolean isPerfectSquare(int n) {
		if(n == 0) {
			return true;
		}
		double dn = (double) n;
		double root = Math.sqrt(dn);
		int intRoot = (int) root;
		double cast = (double) intRoot;
		if(cast == root) {
			return true;
		} else {
			return false;
		}
	}

	public static int startingInt(int n) {

		double dn = (double) n;
		double root = Math.sqrt(dn);
		int intRoot = (int) root;
		return intRoot;
	}

	public static int lastInt(int n) {

		switch(n) {

			case 0:
			return 0;

			case 1:
			return 1;

			case 2:
			return 1;

			case 3:
			return 2;

			case 4:
			return 2;

			default:
			break;
		}

		double halfSum = (double) n;
		halfSum = halfSum / 2;
		double startInt = Math.sqrt(halfSum);
		int result = (int) startInt;
		result++;
		return result;
	}
}
