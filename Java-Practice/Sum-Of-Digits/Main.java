import java.io.*;
import java.util.*;
import java.util.Scanner;
public class Main
{
	public static void main(String[] args) throws IOException
	{
		File file = new File(args[0]);
		Scanner inputScanner = new Scanner(file);
		BufferedReader buffer = new BufferedReader(new FileReader(file));
		String line;

		while(inputScanner.hasNextLine())
		{
			line = inputScanner.nextLine();
			line = line.trim();
			//Process line of input here
			int sum = 0;

			int x = Integer.parseInt(line);
			int t = x;
			while(t > 0){
				sum = sum +  (t % 10);
				t = t / 10;	
			}
			System.out.print(sum);
			if(inputScanner.hasNextLine())
			{
				System.out.print("\n");
			}
			
		}
	}
}