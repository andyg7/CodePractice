public class Main
{
	public static void main(String args[]) 
	{
		String input = args[0];
		boolean is_palindrome = true;
		int front_pt = 0;
		int back_pt = input.length() - 1;

		while (front_pt < back_pt) {
			if (input.charAt(front_pt) != input.charAt(back_pt)) {
				is_palindrome = false;
				break; 
			}
			front_pt++;
			back_pt--;
		}

		if (is_palindrome == true) {
			System.out.println("Is palindrome");
		} else {
			System.out.println("Is not palindrome");
		}
	}


}
