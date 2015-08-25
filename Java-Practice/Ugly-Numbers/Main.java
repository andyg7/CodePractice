import java.io.*;
import java.util.ArrayList;
public class Main {

	public static void main(String[] args) throws IOException {

		File file = new File(args[0]);
		BufferedReader buffer = new BufferedReader(new FileReader(file));
		String line;
		int number;
		boolean firstRun = true;
		while((line = buffer.readLine()) != null) {
			if(firstRun == true) {
				firstRun = false;
			} else {
				System.out.print('\n');
			}
			ArrayList<Integer> nums = new ArrayList<Integer>();
			line = line.trim();
			//Process line of input here
			number = Integer.parseInt(line);
			int numOfUglyNums = parseNum(line, nums);
			System.out.print(numOfUglyNums);

		}

	}

	private static int parseNum(String s, ArrayList<Integer> al) {

		int stringLen = s.length();	

		ArrayList<Integer> individualDigits = new ArrayList<Integer>();

		for(int i = 0; i < stringLen; i++) {
			String sub = s.substring(i, i + 1); 
			int n = Integer.parseInt(sub);
			individualDigits.add(n);
		}
		int startingIndex = s.length() - 1;
		int startingIndexBack = s.length() - 1;
		int initialSum = 0;
		int uglyNumCounter = 0;
		calcPoss(individualDigits, al, startingIndex, startingIndexBack, initialSum);  
		for(int i = 0; i < al.size(); i++) {
			int currentInt = al.get(i);
			if(isUglyNum(currentInt) == true) {
				uglyNumCounter++;
			}
		}

		return uglyNumCounter;

	}

	private static void printAl(ArrayList<Integer> a) {
		System.out.println("Printing List: ");
		for(int i = 0; i < a.size(); i++) {
			System.out.println(a.get(i));
		}
	}

	private static void calcPoss(ArrayList<Integer> digits,
			ArrayList<Integer> poss, int indexL, int indexR ,int sum) {

		assert indexL >= 0;

		int num1 = makeInt(digits, indexL, indexR);

		int sum1 = sum + num1;
		int sum2 = sum - num1;
		if(indexL == 0) {
			poss.add(sum1);
			//poss.add(sum2);
		} else {
			//calcPoss(digits, poss, nextIndex, sum1);
			//calcPoss(digits, poss, nextIndex, sum2);
			calcPoss(digits, poss, indexL - 1, indexL - 1,
					sum1);
			calcPoss(digits, poss, indexL - 1, indexL - 1,
					sum2);
			calcPoss(digits, poss, indexL - 1, indexR,
					sum);

		}

	}

	private static boolean isUglyNum(int n) {
		if(n % 2 == 0) {
			return true;
		}
		if(n % 3 == 0) {
			return true;
		}
		if(n % 5 == 0) {
			return true;
		}
		if(n % 7 == 0) {
			return true;
		}
		return false;
	}

	private static int makeInt(ArrayList<Integer> al, int indexL, int
			indexR) {
		assert indexL <= indexR;
		int result = 0;
		for(int i = indexL; i <= indexR; i++) {
			result = result * 10;
			result = result + al.get(i);
		}

		return result;

	}
}
