import java.io.*;
import java.util.*;
public class Main {

	private static ArrayList<Integer> inside = new ArrayList<Integer>();
	private static ArrayList<Integer> leftHouse = new ArrayList<Integer>();
	private static ArrayList<String> events; 

	public static void main (String[] args) throws IOException {
		File file = new File(args[0]);
		BufferedReader buffer = new BufferedReader(new FileReader(file));
		boolean firstRun = true;
		String line;
		while ((line = buffer.readLine()) != null) {
			line = line.trim();
			if(firstRun == false ) {
				System.out.print('\n');
			} else {
				firstRun = false;
			}
			// Process line of input Here
			events = new ArrayList<String>();
			int passes = getIntFromString(line);
			int startIndex = getStartIndex(line);
			String[] input = makeArray(line, startIndex);	
			String output =	determineCrime(input);	
			System.out.print(output);
		}
	}

	public static String determineCrime(String[] s) {

		boolean validSeq = true;

		ArrayList<String> list = new ArrayList<String>();
		for(int i = 0; i < s.length; i++) {
			list.add(s[i]);
			//System.out.println(s[i]);
		}
		for(int i = 0; i < list.size(); i++) {
			String elem = list.get(i);
			int elemLen = elem.length();
			String direction = elem.substring(0,1);
			String id = elem.substring(1, elemLen);
			String oppString = opposite(elem);
			//System.out.println(oppString);
			//System.out.println("Adding " + elem);
			boolean tempBool = addId(elem);
			if(tempBool == false) {
				validSeq = false;
			}
		}
		printEvents();
		if(validSeq == false) {
			String returnedString = "CRIME TIME";
			//System.out.println("CRIME TIME");
			return returnedString;
		}
		int criminalsInHouse = minimizeEvents();
		String crimes = Integer.toString(criminalsInHouse);
		return crimes;
	}

	private static int minimizeEvents() {

		int len = events.size();
		int firstCounter = entersNotZeroLeft();
		int zeroCounter = entersLeft() - firstCounter;
		//System.out.println("enters left " + firstCounter);
		int indexReached = len - 1;

		while(firstCounter > 0) {
			for(int i = indexReached; i>= 0; i--) {
				String elem = events.get(i);
				String dir = elem.substring(0,1);
				len = events.size();
				String id = elem.substring(1, elem.length());
				if(dir.equals("E") && !id.equals("0")) {
					//System.out.println("trying to rid " + elem);
					len = events.size();
					firstCounter--;
					String opp = opposite(elem);
					String oppDir = oppDirection(elem);
					String oppMask = oppDirection(elem);
					oppMask+="0";
					boolean foundExact = false;
					if(id.equals("0")) {
						for(int a = i + 1; a < len; a++) {
							String tempString = events.get(a);
							int tempLen = tempString.length();
							String tempDir = tempString.substring(0,1);
							String tempId = tempString.substring(1,
							tempLen);
							if(tempDir.equals(oppDir) &&
								!tempId.equals("0")) {
								events.remove(a);
								events.remove(i);
								a = len;
								foundExact = true;
							}
						}
					} else {
						for(int a = i + 1; a < len; a++) {
							if(events.get(a).equals(opp)) {
								events.remove(a);
								events.remove(i);
								a = len;
								foundExact = true;
							}
						}
					}

					if(foundExact == false) {

						for(int a = i + 1; a  < len; a++) {
							if(events.get(a).equals(oppMask)) {
								events.remove(a);
								events.remove(i);
								a = len;

							}
						}
					}
					len = events.size();
					//indexReached = i - 1;
					//i = -1;
				}
			}
		
		}

		while(zeroCounter > 0) {
			len = events.size();
			indexReached = len - 1;
			for(int i = indexReached; i >= 0; i--) {
				String elem = events.get(i);
				String dir = elem.substring(0,1);
				len = events.size();
				String id = elem.substring(1, elem.length());
				if(dir.equals("E") && id.equals("0")) {
					//System.out.println("trying to rid " + elem);
					len = events.size();
					zeroCounter--;
					String opp = opposite(elem);
					String oppDir = oppDirection(elem);
					String oppMask = oppDirection(elem);
					oppMask+="0";
					boolean foundExact = false;
					for(int a = i + 1; a < len; a++) {
						String tempString = events.get(a);
						String tempDir = tempString.substring(0,1);
						if(tempDir.equals("L")) {
							events.remove(a);
							events.remove(i);
							a = len;
							foundExact = true;
						}
					}
				}
			}
		}

		int entersLeft = entersLeft();
		//System.out.println("after minimizing we have enters left " + entersLeft);
		return entersLeft;
	}

	private static String opposite(String s) {
		String direction = s.substring(0,1);
		int len = s.length();
		String id = s.substring(1, len);
		if(direction.equals("E")) {
			String ts = "L";
			ts+=id;
			return ts;
		} else {
			String ts = "E";
			ts+=id;
			return ts;
		}
	}

	private static void printEvents() {
		//System.out.println("Printing events list");
		for(int i = 0; i < events.size(); i++) {
			//System.out.print(events.get(i) + " ");
		}
		//System.out.println();
	}

	private static int entersNotZeroLeft() {
		
		int counter = 0;
		int len = events.size();
		for(int i = 0; i < len; i++) {
			String event = events.get(i);
			int stringLen = event.length();
			String dir = event.substring(0,1);
			String id = event.substring(1, stringLen);
			if(dir.equals("E") && !id.equals("0")) {
				counter++;
			}
		}
		return counter;


	}

	private static int entersLeft() {
		int counter = 0;
		int len = events.size();
		for(int i = 0; i < len; i++) {
			String event = events.get(i);
			String dir = event.substring(0,1);
			if(dir.equals("E")) {
				counter++;
			}
		}
		return counter;
	}

	private static boolean addId(String s) {

		//System.out.println("Adding " + s);
		String oppId = opposite(s);
		int numEvents = events.size();
		int len = s.length();
		String direction = s.substring(0,1);
		String id = s.substring(1,len);
		if(id.equals("0")) {
			events.add(s);
			//System.out.println("actually adding " + s);
			return true;
		}

		for(int i = numEvents - 1; i >= 0; i--) {
			int index = i;
			if(events.get(index).equals(oppId)) {
				//events.remove(index);
				//System.out.println("adding " + s);
				events.add(s);
				return true;
			}
			if(events.get(index).equals(s)) {
				boolean foundMask = false;

				if(direction.equals("E")) {
					for(int a = index; a < numEvents; a++) {
						String mask = oppDirection(s);
						mask+="0";
						//System.out.println("looking for " + mask);
						if(events.get(a).equals(mask)) {
							events.remove(a);
							events.add(a, oppId);
							//events.remove(index);
							events.add(s);
							//System.out.println("adding " + s);
							foundMask = true;
							a = index - 1;
						}
					}
				} else {
					for(int a = numEvents - 1; a >= index; a--) {
						String mask = oppDirection(s);
						mask+="0";
						//System.out.println("looking for " + mask);
						if(events.get(a).equals(mask)) {
							events.remove(a);
							events.add(a, oppId);
							//events.remove(index);
							events.add(s);
							//System.out.println("adding " + s);
							foundMask = true;
							a = index - 1;
						}
					}
				}

				
				if(foundMask == false) {
					return false;
				} else {
					return true;
				}
			}
		}
		events.add(s);
		//System.out.println("adding " + s);
		return true;
	}

	private static String oppDirection(String s) {
		String dir = s.substring(0,1);
		if(dir.equals("E")) {
			String t = "L";
			return t;
		} else {
			String t = "E";
			return t;
		}
	}

	public static int getIntFromString(String s) {
		String str = "";
		int counter = 0;
		while(!(s.substring(counter,counter + 1).equals(";"))) {
			str += s.substring(counter,counter+1);
			counter++;
		}	
		int number = Integer.parseInt(str);
		return number;

	}
	public static int getStartIndex(String s) {
		int counter = 0;
		while(!(s.substring(counter,counter + 1).equals(" "))) {
			counter++;
		}		
		return counter;
	}
	public static String[] makeArray(String s, int index) {
		String str = s.substring(index+1, s.length());
		str = str.replaceAll("\\s","");
		//		System.out.println(str);
		String[] tmpArry = str.split("\\|");
		for(int i = 0; i < tmpArry.length; i++) {
			//System.out.println(tmpArry[i]);
		}
		return tmpArry;
	}

}

