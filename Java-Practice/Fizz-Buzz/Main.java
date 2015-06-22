import java.io.*;
public class Main
{
	public static void main(String[] args) throws IOException
	{	
		File file = new File(args[0]);
		BufferedReader buffer = new BufferedReader(new FileReader(file));
		String line;
		int numberOfLines= 0;
		while(((line = buffer.readLine()) != null)){
			numberOfLines++;
		}
		buffer = new BufferedReader(new FileReader(file));
		int linesLeft = numberOfLines;
		while (((line = buffer.readLine()) != null)) {
			line = line.trim();
			// Process line of input Here
			String[] arr = line.split(" ");
			int firstDivider;
			int secondDivider;
			int firstAndSecondDivider;
			int sizeOfN;
			try {
				firstDivider = Integer.parseInt(arr[0]);
				secondDivider = Integer.parseInt(arr[1]);
				firstAndSecondDivider = firstDivider * secondDivider;
				sizeOfN = Integer.parseInt(arr[2]);
			} catch(NumberFormatException e){
				sizeOfN = 0;	
				firstDivider = 0;
				secondDivider = 0;
				firstAndSecondDivider = 0;
			}
			String answer = "";
			for(int i = 1; i <= sizeOfN;i++){
				if(i%firstAndSecondDivider==0){ 
					//	System.out.println("BF");
					answer += "FB ";
				} else if(i%firstDivider == 0) {
					//	System.out.println("B");
					answer += "F ";
				}	else if(i%secondDivider== 0){
					//	System.out.println("F");
					answer += "B ";
				} else {
					//	System.out.println(i);
					String tmp = String.valueOf(i);
					answer += tmp;
					answer += " ";
				}
			}
			answer = answer.trim();
			System.out.print(answer);	
			if(linesLeft > 1){
				System.out.print("\n");	
			}
			linesLeft = linesLeft - 1;
		}
	}
}