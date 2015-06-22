import java.io.*;
import java.util.*;
public class Main {

	private static ArrayList<Integer> inside = new ArrayList<Integer>();
	private static ArrayList<Integer> leftHouse = new ArrayList<Integer>();

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
			int passes = getIntFromString(line);
			//System.out.println("Passes: " + passes);
			//System.out.println("Start index: " + getStartIndex(line));	
			int startIndex = getStartIndex(line);
			String[] input = makeArray(line, startIndex);	
			/*System.out.println(input.length);
			  System.out.println(input[0]);
			  System.out.println(input[1]);
			  System.out.println(input[2]);*/
			determineCrime(input);	
		}
	}


	public static String findPasses(String[] s) {

		for(int i = 0; i < s.length ; i++) {
			String pass = s[i];
			if(pass.substring(0,1).equals("E")) {
				int idToAdd = Integer.parseInt(pass.substring(1,pass.length));
			} else {

			}	
		}

		return "s";
	}

	public static boolean validEntry(int n) {
		if(inside.contains(n)) {
			if(leftHouse.contains(n)) {
				leftHouse.remove(n);
				inside.add(n);
				return true;
			} else if(leftHouse.contains(0)) {
				leftHouse.remove(0);
				inside.add(n);
				return true;
			}
			return false;
		} else if(leftHouse.contains(n)) {
			leftHouse.remove(n);
			inside.add(n);
			return true;
		} else {
			inside.add(n);
			return true;
		}
	}

	public static boolean validExit(int n) {
		if(leftHouse.contains(n)) {
			if(inside.contains(0)) {
				inside.remove(0);
				leftHouse.add(n);
				return true;
			} 
			if(inside.contains(n)) {
				inside.remove(n);
				leftHouse.add(n);
				return true;
			}
			return false;
		}
		if(inside.contains(n)) {
			inside.remove(n);
			leftHouse.add(n);
			return true;
		}
		leftHouse.add(n);
		return true;
	}

	public static void determineCrime(String[] s) {

		ArrayList<String> list = new ArrayList<String>();
		for(int i = 0; i < s.length; i++) {
			list.add(s[i]);
		}

		for(int i = 0;i < list.size();i++) {
			String ts = list.get(i);
			if(ts.substring(0,1).equals("E") && (!ts.substring(1,ts.length()).equals("0"))) {
				String ss = "L";
				ss+=ts.substring(1,ts.length());
				//System.out.println("SS" + ss);
				for(int a = i;a < list.size();a++) {
					if(list.get(a).equals(ss)) {
						list.remove(a);
						list.remove(i);
						a = list.size();
						i--;	
					}
				}
			}
		}
		for(int i = 0; i < list.size();i++) {
			String ts = list.get(i);
			//System.out.println("ts"+ts);
			if(ts.equals("E0")) {
				for(int a = i;a < list.size();a++) {
					String ss = list.get(a);
					if(ss.substring(0,1).equals("L")) {
						list.remove(a);
						list.remove(i);
						a = list.size();
						i--;	
					}
				}
			}
		}	
		for(int i = 0; i < list.size();i++) {
			String ts = list.get(i);
			if(ts.equals("L0")) {
				for(int a = 0;a < i;a++) {
					if(list.get(a).substring(0,1).equals("E")) {
						list.remove(i);
						list.remove(a);
						a = i;
						i--;	
					}
				}
			}

		}
		boolean doublePasses = false;
		for(int i = 0; i < list.size();i++) {
			String ts = list.get(i);
			if(!(ts.substring(1,ts.length()).equals("0"))){
				for(int a = i + 1; a < list.size();a++) {
					if(list.get(a).equals(ts)) {
						doublePasses = true;
						a = list.size();
						i = list.size();
					}	
				}
			}
		}
		//System.out.print(doublePasses);
		if(doublePasses == true) {
			System.out.print("CRIME TIME");
		} else {
			int counter = 0;
			for(int b = 0; b < list.size(); b++) {
				if(list.get(b).substring(0,1).equals("E")) {
					counter++;
				}
			}
			System.out.print(counter);
		}
		for(int i = 0; i < list.size();i++) {
			//System.out.print(list.get(i));
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

