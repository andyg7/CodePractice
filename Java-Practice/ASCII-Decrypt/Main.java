import java.io.*;
import java.util.*;
public class Main {
	public static void main (String[] args) throws IOException {
		File file = new File(args[0]);
		BufferedReader buffer = new BufferedReader(new FileReader(file));
		String line;
		boolean firstRun = true;
		while ((line = buffer.readLine()) != null) {
			line = line.trim();
			// Process line of input Here
			if(firstRun == true) {
				firstRun = false;
			} else {
				System.out.print('\n');
			}
			String[] initialSplit = line.split(" ");
			int lengthOfWord = Integer.parseInt(initialSplit[0]);
			String knownLetter = initialSplit[2];
			int[] codes = new int[initialSplit.length - 4];
			for(int i = 0 ; i < codes.length; i++) {
				codes[i] = Integer.parseInt(initialSplit[i+4]);	
			}			
			//printCodes(codes);
			int shift  = findMessage(codes, lengthOfWord, knownLetter);
			for(int i = 0; i < codes.length; i++) {
				char tc = (char)(codes[i] - shift);
				System.out.print(tc);
			}
			//System.out.print("abc");
		}
	}

	private static int findMessage(int[] arr, int len, String let) {

		ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();	
		int shifter = -1;
		char letChar = let.charAt(0);
		String word = "";
		for(int i = 0; i < (arr.length - len); i++) {
			for(int a = i + len; a < (arr.length - len); a++) {
				int counter = 0;
				boolean matching = true;
				while((counter < len) && (matching == true)) {
					int tempA = i + counter;
					int tempB = a + counter;
					if(arr[tempA] != arr[tempB]) {
						matching = false;
					}
					counter++;
				}
				if((matching == true)) {
					ArrayList<Integer> al = new ArrayList<Integer>();
					al.add(arr[i]);
					al.add(arr[i+1]);
					al.add(arr[i+2]);
					al.add(arr[i+3]);
					al.add(arr[i+4]);
					list.add(al);
					boolean foundWord = validDecrypt(al, i, a, arr, len, let);
					if(foundWord == true) {
						int offset = arr[i + len - 1] - letChar;
						return offset;
					}
				}
			}
		}

		return shifter;
	}

	private static int[] formatInput(String s) {

		String line = s;
		String message = line.substring(8, line.length());
		String[] codesA = message.split(" ");
		int[] codes = new int[codesA.length];
		for(int i = 0; i < codes.length; i++) {
			codes[i] = Integer.parseInt(codesA[i]);
		}
		s = "abc";
		return codes;
	}

	private static boolean validDecrypt(ArrayList<Integer> al, int index, int indexTwo,  int[]
	arr, int len, String let) {

		boolean valid = true;

		char letChar = let.charAt(0);
		int pivotIndex = index;
		int arrLen = arr.length;	
		int offset = arr[index + len - 1] - letChar;

		if(!isChar(arr[index + len - 1])) {
			valid = false;
			//System.out.println("offset means is space" + al);
		}

		boolean lastWord = false;
		if(index == 0) {
			pivotIndex = indexTwo;
			if((indexTwo + len) == (arrLen - 1)) {
				lastWord = true;
			}
		}
		int endIndex = pivotIndex + len;

		if((lastWord == false) && (valid == true)) {
			int prevChar = arr[pivotIndex - 1];
			int afterChar = arr[endIndex];
			//System.out.println("prev char " + prevChar);
			//System.out.println("last char " + afterChar);
			if(prevChar != afterChar) {
				valid = false;
				//System.out.println("prev and after dont match");
			} else{
				if((prevChar - offset) != ' ') {
					valid = false;
					//System.out.println("first and after arent space");
				} else {
					for(int i = 0; i < len; i++) {
						if((arr[pivotIndex + i] - offset) == ' ') {
							valid = false;
							//System.out.println("contaisn space");
						}
					}
				}
			}
		} else {
			return valid;
		}
		if(valid == true) {
			//System.out.println("valid word");
		} else {
			//System.out.println("invalid word");
		}
		return valid;
	}


	public static boolean isChar(int n) {

		if(n >= 72 && n <= 147) {
			return true;
		} else {
			return false;
		}
		//return false;
	}

	public static void printCodes(int[] arr) {
		for(int i = 0; i < arr.length; i++) {
			 System.out.print(arr[i] + " ");
		}
		System.out.println();
	}
}

