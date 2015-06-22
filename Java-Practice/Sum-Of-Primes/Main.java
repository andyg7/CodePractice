public class Main
{
	public static void main(String[] agrs)
	{
		int numOfPrimes = 0;
		int sumOfPrimes = 0;
		int x = 1;
		while(numOfPrimes<1000)
		{
			if(isPrime(x) == true)
			{
				sumOfPrimes = sumOfPrimes + x;
				numOfPrimes++;
			}
			x++;
		}	
		System.out.println(sumOfPrimes);
	}
	
	public static boolean isPrime(int num)
	{
		if(num == 2 || num == 3)
		{
			return true;
		}
		if(num == 1)
		{
			return false;
		}
		if((num % 2) == 0)
		{
			return false;
		} 
		for(int i = 3 ; i < num ;i=i+2)
		{
			if((num % i) == 0)
			{
				return false;
			}
		}
		
		return true;
	}
	
}