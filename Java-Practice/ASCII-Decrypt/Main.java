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
			//System.out.println("length of word: " + lengthOfWord);
			String knownLetter = initialSplit[2];
			//System.out.println("known letter: " + knownLetter);
			int[] codes = new int[initialSplit.length - 4];
			for(int i = 0 ; i < codes.length; i++) {
				codes[i] = Integer.parseInt(initialSplit[i+4]);	
			}			
			for(int i = 0; i < codes.length; i++) {
				//System.out.println(codes[i]);
			}
			int shift  = findMessage(codes, lengthOfWord, knownLetter);
			//System.out.println(a);
			for(int i = 0; i < codes.length; i++) {
				char tc = (char)(codes[i] - shift);
				//System.out.print(tc);
			}
			//System.out.print("abc");
		}
	}

	private static int findMessage(int[] arr, int len, String let) {

	ArrayList<ArrayList<Integer>> list = new ArrayList<ArrayList<Integer>>();	
		int shifter = -1;
		String word = "";
		for(int i = 0; i < (arr.length - len); i++) {
			for(int a = i + 5; a < (arr.length - len); a++) {
				if(arr[i] == arr[a]) {
					//System.out.println("here");
					if(arr[i+1] == arr[a+1]) {
						if(arr[i+2] == arr[a+2]) {
							if(arr[i+3] == arr[a+3]) {
								if(arr[i+4] == arr[a+4]) {
									ArrayList<Integer> al = new ArrayList<Integer>();
									al.add(arr[i]);
									al.add(arr[i+1]);
									al.add(arr[i+2]);
									al.add(arr[i+3]);
									al.add(arr[i+4]);
									list.add(al);
									System.out.println("here");
									System.out.println(i);
									/*
									   char letc = let.charAt(0);
									   int tempNum = letc;
									int n = arr[i+4] - tempNum;
									//System.out.println("N; " + n);
									char f = ' ';	
									int fi = f;
									if(i == 0) {
										if(arr[a-1] != arr[a+4+1]) {
										word = "";
												}
										for(int t = a; t < a + 5; t++) {
											if(arr[a-1] == arr[t]) {
												word = "";
											}
											if(arr[a+4+1] == arr[t]) {
												word = "";
											}
										}	
									} else if((a + 5) == (arr.length - 1)) {
										if(arr[i-1] != arr[i+4+1]) {
											word = "";
											}
											for(int t = i; t < i + 5; t++) {
												if(arr[i-1] == arr[t]) {
													word = "";
												}
												if(arr[i+4+1] == arr[t]) {
													word = "";
												}

											}
									} else if(arr[i-1] != arr[i+4+1]) {
										word = "";
										for(int t = a; t < a + 5; t++) {
											if(arr[a-1] == arr[t]) {
												word = "";
											}
											if(arr[a+4+1] == arr[t]) {
												word = "";
											}
										}
									} else { 
										word = "";
										String aa = Integer.toString(arr[i]); 		
										word+=aa;
										word+=" ";
										String b = Integer.toString(arr[i+1]); 
										word+=b;
										word+=" ";
										String c = Integer.toString(arr[i+2]); 
										word+=c;
										word+=" ";
										String d = Integer.toString(arr[i+3]); 
										word+=d;
										word+=" ";
										String e = Integer.toString(arr[i+4]); 
										word+=e;
										word+=" ";
										//System.out.println(word);
										if((n + fi) == arr[i]) {
											word = "";
										} else if((n + fi)== arr[i+1]) {
											word = "";
										} else if((n + fi) == arr[i+2]) {
											word = "";
										} else if((n + fi) == arr[i+3]) {
											word = "";
										} else if((n + fi) == arr[i+4]) {
											word = "";
										} 
										if(word != "") {
											shifter = n;
											//System.out.println("**" + word + "**" + n + "**" );
											return shifter;
										} 
									}
							*/	}
							}
						}
					}
				}

			}
		}
		for(int i = 0; i < list.size(); i++) {
			ArrayList<Integer> temp = list.get(i);
			for(int a = 0; a < temp.size(); a++) {
				System.out.print(temp.get(a));
			}
				System.out.print('\n');
		}

		return shifter;
	}

	private static int[] formatInput(String s) {

		String line = s;
		String message = line.substring(8, line.length());
		//System.out.println(message);
		String[] codesA = message.split(" ");
		int[] codes = new int[codesA.length];
		for(int i = 0; i < codes.length; i++) {
			codes[i] = Integer.parseInt(codesA[i]);
			//System.out.println(codes[i]);
		}
		s = "abc";
		return codes;
	}
}

