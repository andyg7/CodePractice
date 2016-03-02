import java.util.*;

public class Main
{
	public static void main(String args[])
	{
		int[] arr = {1,2,3,4,239,2,9,9,9};
		int[] arr2 = {10,9,2398,28,2,2,9,1,9,4};

		HashMap<Integer, Integer> hashMap = new HashMap<Integer, Integer>();
		HashMap<Integer, Integer> hashMap2 = new HashMap<Integer, Integer>();

		for (int i = 0; i < arr.length; i++) {
			if (hashMap.containsKey(arr[i])) {
				int temp = hashMap.get(arr[i]);
				temp++;
				hashMap.remove(arr[i]);
				hashMap.put(arr[i], temp);
			} else {
				hashMap.put(arr[i], 1);
			}
		}

		for (int i = 0; i < arr2.length; i++) {
			if (hashMap2.containsKey(arr2[i])) {
				int temp = hashMap2.get(arr2[i]);
				temp++;
				hashMap2.remove(arr2[i]);
				hashMap2.put(arr2[i], temp);
			} else {
				hashMap2.put(arr2[i], 1);
			}
		}

		for (int i = 0; i < arr.length; i++) {
			if (hashMap2.containsKey(arr[i])) {
				if (hashMap.get(arr[i]) == hashMap2.get(arr[i])) {
					System.out.println("Found dup with same cardinality" + arr[i]);	
				}
			}
		}

		Friend sam = new Friend("sam");
		sam.setName("jon");
		System.out.println("His name is: " + sam.getName());
	}
}
