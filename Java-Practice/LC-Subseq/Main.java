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
					lastLineEmpty = true;
				} else {
					System.out.print(tempS);
				}
			}
		}
	}

	public static String findSequence(String s) {
		String firstWord, secondWord;
		int colonIndex = s.indexOf(';');
		firstWord = s.substring(0,colonIndex);
		//firstWord = firstWord.toUpperCase();
		secondWord = s.substring(colonIndex + 1, s.length());
		//secondWord = secondWord.toUpperCase();
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
