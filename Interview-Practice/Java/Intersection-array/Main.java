import java.util.*;

public class Main
{

	public static void main(String args[]) {

		int[] array_1 = {10, 2, 1, 99, 4, 7, 38, 280, 2, 849, 578};
		int[] array_2 = {99, 3, 8, 4, 7, 0, 578};

		HashMap<Integer, Integer> hash_map = new HashMap<Integer, Integer>();

		for (int i = 0; i < array_1.length; i++) {
			int temp = array_1[i];

			if (hash_map.containsKey(temp) == true) {
				int value = hash_map.get(temp);
				value++;
				hash_map.remove(temp);
				hash_map.put(temp, value);
			} else {
				hash_map.put(temp, 1);
			}		
		}

		for (int i = 0; i < array_2.length; i++) {
			int temp = array_2[i];

			if (hash_map.containsKey(temp) == true) {
				System.out.println("Dup: " + temp); 
			} 			
		}		
	}


}
