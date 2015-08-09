import java.io.*;
public class Main {
	public static void main(String[] args) throws IOException {
		File file = new File(args[0]);
		BufferedReader buffer = new BufferedReader(new FileReader(file));
		String line;
		boolean firstRun = true;
		while((line = buffer.readLine()) != null) {
			line = line.trim();
			//Process line of input here
			if(firstRun == true) {
				firstRun = false;
			} else {
				System.out.println();
			}
			boolean validInput = true;
			String[] strings = line.split(",");
			if(strings.length != 2) {
				validInput = false;
			}

			if(validInput == true) {
				//System.out.println("valid input");	
				String firstString = strings[0];
				String secondString = strings[1];
				int string2Len = secondString.length();
				boolean foundSubString = false;
				foundSubString = foundSubString(firstString, secondString);
				System.out.print(foundSubString);
			}


		}
	}

	public static boolean foundSubString(String string1, String
			string2) {

		int s1Len = string1.length();
		int s2Len = string2.length();
		int counter1 = 0;
		int counter2 = 0;
		int lastIndex = s1Len - s2Len;
		boolean substringFound = false;	

		while(counter1 <= lastIndex && substringFound
			== false) {

			int tempCounter = counter1;
			counter2 = 0;
			boolean possibleMatch = true;

			while(possibleMatch == true && counter2 < s2Len) {
				char char1 = string1.charAt(counter1);
				char char2 = string2.charAt(counter2);
				if(char2 == '\\') {
					counter2++;
					char2 = string2.charAt(counter2);
					if(char1 == char2) {
						counter1++;
						counter2++;
					} else {
						possibleMatch = false;
					}
				} else {
					
					if(char2 == '*') {
						if(counter2 == s2Len - 1) {
							counter2++;
						} else {
							int index = lastSubMatch(string1, string2, counter2 + 1,
							string2.length() - 1);
							if(index == - 1) {
								possibleMatch = false;
							} else {
								if(index >= counter1) {
									possibleMatch = true;
									counter2 = s2Len;
								}
							}
/*							char nextChar = string2.charAt(counter2 + 1);
							while(counter1 < s1Len && string1.charAt(counter1) != nextChar) {
								counter1++;
							}
							if(counter1 == s1Len) {
								possibleMatch = false;
							} else {
								counter2++;
							}

							*/
						}
					} else {
						if(char1 != char2) {
							possibleMatch = false;
						} else {
							counter1++;
							counter2++;
						}
					}
				}
			}

			if(possibleMatch == true) {
				substringFound = true;
			}
			counter1++;
		}
		//System.out.println("Found substring");
		return substringFound;
	}

	public static int lastSubMatch(String string1, String string3, int r1, int r2) {

		String string2 = "";
		for(int i = r1; i <= r2; i++) {
			string2 += string3.charAt(i);
		}

		int lastIndex1 = string1.length() - 1;
		int lastIndex2 = string2.length() - 1;
	
		int counter1 = lastIndex1;
		int counter2 = lastIndex2;
		boolean foundMatch  = false;

		while(counter1 >= lastIndex2 && foundMatch == false) {
			int tempC1 = counter1;
			int tempC2 = counter2;

			boolean possibleMatch = true;
			for(int i = tempC2; i >= 0; i--) {
				if(string2.charAt(i) == string1.charAt(tempC1)) {
					tempC1--;
				} else {
					possibleMatch = false;
				}
			}

			if(possibleMatch == true) {
				foundMatch = true;
				counter1 = tempC1;
			} else {
				counter1--;
			}
			
		}

		if(foundMatch == true) {
			return counter1;
		} else {
			return -1;
		}
	}


}
