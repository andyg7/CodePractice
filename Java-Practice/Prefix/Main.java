import java.io.*;
import java.util.*;
import java.lang.*;
public class Main {

	public static void main(String[] args) throws IOException {

		File file = new File(args[0]);
		BufferedReader buffer = new BufferedReader(new FileReader(file));

		String line;
		boolean firstRun = true;
		while((line = buffer.readLine()) != null) {
			if(firstRun == false) {
				System.out.print('\n');
			}
			firstRun = false;
			Stack<String> st = new Stack<String>();
			double answer = 0;
			int lineLength = line.length();
			ArrayList<String> inputList = new ArrayList<String>();
			for(int i = 0;i<lineLength;i++) {
				int endOfOperIndex = i + 1;
				while(endOfOperIndex < lineLength && line.charAt(endOfOperIndex) != ' ') {
					endOfOperIndex++;
				}
				String inputChar = line.substring(i,endOfOperIndex);
				inputList.add(inputChar);
				i = endOfOperIndex;

			}
			st.push("+");
			st.push("0");
			while(!(inputList.size() == 1 && (st.size()==0))) {
				if(inputList.size() == 1) {
					inputList.add(0,st.pop());
				}
				boolean at = isOperand(inputList.get(0));
				boolean bt = isOperand(inputList.get(1));
				if((at == true) && (bt == true)) {
					double a = Double.parseDouble(inputList.get(0));
					double b = Double.parseDouble(inputList.get(1));
					String op = st.pop();
					if(isOperand(op) == false) {
						answer = performCalc(a,b,op);
						//System.out.println("Answer: " + answer);
						String t = Double.toString(answer);
						inputList.remove(0);
						inputList.remove(0);
						inputList.add(0,t);
					} else {
						inputList.add(0,op);
}
				} else {
					st.push(inputList.remove(0));	
				}	
			}
			int tempAnswer = (int)answer;
			System.out.print(tempAnswer);
		}

	}

	public static double performCalc(double a, double b, String c) {
		double result = 0;
		switch(c) {
			case "+":
				result = a + b;
				break;
			case "*":

				result = a * b;
				break;
			case "/":
				result = a / b;
				break;
		}
		return result;
	}	

	public static boolean isOperand(String c) {
		boolean isOperand = true;
		switch(c) {
			case "+":
				isOperand = false;
				break;
			case "*":
				isOperand = false;
				break;
			case "/":
				isOperand = false;
				break;
		}

		return isOperand;
	}

} 
