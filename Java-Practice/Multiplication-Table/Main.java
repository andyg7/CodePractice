public class Main
{
	public static void main(String[] args)
	{
		for(int i = 1; i <=12; i++)
		{
			String nextLine = "";
			
			for(int a = 1;a<=12;a++)
			{
				int n = i * a;
				String s = String.valueOf(n);
				
				if(n <= 9)
				{
					nextLine +="   ";
				}
				if(n>9 && n<100)
				{
					nextLine += "  ";
				} 
				if(n>=100)
				{
					nextLine += " ";
				}
				nextLine += s;
			}
			System.out.print(nextLine);
			if(i < 12) {
				System.out.print("\n");
			}
		}
	}
}