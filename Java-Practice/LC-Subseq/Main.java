import java.io.*;
public class Main {
	public static void main(String[] args) throws IOException {
		File file = new File(args[0]);
		BufferedReader buffer = new BufferedReader(new FileReader(file));
		String line;
		boolean firstRun = true;	
		boolean lastLineEmpty = false;
		while((line = buffer.readLine()) != null) {
			if(firstRun == false && lastLineEmpty == false) {
				System.out.println("");
			} 
			firstRun = false;		
			lastLineEmpty = false;
			line = line.trim();
			if(line.equals("")){
				lastLineEmpty = true;
			} else {
				String tempS = findSequence(line);
				tempS = tempS.trim();
				if(tempS == "") {
					System.out.print(tempS);
					//lastLineEmpty = true;
				} else {
					System.out.print(tempS);
					//System.out.println(tempS.length());
				}
			}
		}
	}

	public static String findSequence(String s) {
		if(s.charAt(0) == ';') {
			return "";
		}
		
		String[] splitStrings = s.split(";");
		String firstWord, secondWord;
		String tfw, tsw;
		tfw = "";
		tsw = "";
		int colonIndex = s.indexOf(';');
		firstWord = splitStrings[0];
		secondWord = "";
		//firstWord = firstWord.toUpperCase();
		int numOfSegs = splitStrings.length;
		//System.out.println(numOfSegs);
		String sequence = "";

		for(int i = 0; i < numOfSegs - 1; i++) {
			tfw="";
			tsw="";
			for(int a = 0; a <= i; a++) {
				tfw+= splitStrings[a];
				if(a < i) {
					tfw+=";";
				}
			}

			for(int b = i + 1; b < numOfSegs; b++) {
				tsw+=splitStrings[b];
				if(b < numOfSegs - 1) {
					tsw+=";";
				}
				if(b == numOfSegs - 1) {
					if(s.charAt(s.length()-1) == ';') {
						//return "";
						tsw+=";";
					}				
				}

			}


			//System.out.println("first word " + tfw);
			//System.out.println("second word " + tsw);
			String currentSeq = getMaxString(tfw, tsw);

			int currentLen = currentSeq.length();
			int maxLen = sequence.length();
			if(currentLen > maxLen) {
				sequence = currentSeq;
			}

		}
/*
		for(int i = 1; i < splitStrings.length; i++) {
			String tempArrayString = splitStrings[i];
			//System.out.println(tempArrayString); 
			secondWord+=tempArrayString;
			if(i < splitStrings.length - 1) {
				secondWord+=";";
			}
			//System.out.println(secondWord);
		} */
		//secondWord = splitStrings[1];
		//secondWord = secondWord.toUpperCase();
				/*
		int sequenceLength = -1;
		int firstWordLength = firstWord.length();
		int secondWordLength = secondWord.length();
		int firstCounter = 0;
		int secondCounter = 0;
		for(int i = 0; i < firstWordLength;i++) {
			String tempString = "";	
			firstCounter = i;
			secondCounter = 0;
			int tempCounterSpot = 0;
			while((firstCounter < firstWordLength) && (secondCounter < secondWordLength)) {
				if(firstWord.charAt(firstCounter) == secondWord.charAt(secondCounter)) {

					tempString+=firstWord.charAt(firstCounter);
					firstCounter++;
					secondCounter++;
					tempCounterSpot = secondCounter;
				} else {
					secondCounter++;	
				}
				if(tempString.length() > sequenceLength) {
					sequence = tempString;
					sequenceLength = tempString.length();
				} 
				if(secondCounter > (secondWordLength - 1)) {
					firstCounter++;
					secondCounter = tempCounterSpot;
				}

			}
		}
		 */

		return sequence;
	}

	public static String getMaxString(String fw, String sw) {

		String firstWord = fw;
		String secondWord = sw;
		String sequence = "";
		int sequenceLength = -1;
		int firstWordLength = firstWord.length();
		int secondWordLength = secondWord.length();
		int firstCounter = 0;
		int secondCounter = 0;
		for(int i = 0; i < firstWordLength;i++) {
			String tempString = "";	
			firstCounter = i;
			secondCounter = 0;
			int tempCounterSpot = 0;
			while((firstCounter < firstWordLength) && (secondCounter < secondWordLength)) {
				if(firstWord.charAt(firstCounter) == secondWord.charAt(secondCounter)) {

					tempString+=firstWord.charAt(firstCounter);
					firstCounter++;
					secondCounter++;
					tempCounterSpot = secondCounter;
				} else {
					secondCounter++;	
				}
				if(tempString.length() > sequenceLength) {
					sequence = tempString;
					sequenceLength = tempString.length();
				} 
				if(secondCounter > (secondWordLength - 1)) {
					firstCounter++;
					secondCounter = tempCounterSpot;
				}

			}
		}

		return sequence;
	}
}
