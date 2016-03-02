public class MyMerge
{

	int[] array;
	int[] tempArray;

	public MyMerge(int[] arr) {
		int len = arr.length;
		array = new int[len];
		tempArray = new int[len];
		for (int i = 0; i < arr.length; i++) {
			array[i] = arr[i];
		}
	}


	public int[] sort()
	{
		int len = array.length;
		doSort(0, len - 1);

		for (int i = 0; i < array.length; i++) {
			System.out.println(array[i]);
		}
		return array;
	}

	public void doSort(int low, int high)
	{
		if (low < high) {
			int mid = low + (high - low) / 2;

			doSort(low, mid);

			doSort(mid + 1, high);

			merge(low, mid, high);
		}
	}

	private void merge(int low, int mid, int high)
	{
		for(int i = low; i <= high; i++) {
			tempArray[i] = array[i];
		}

		int i = low;
		int j = mid + 1;
		int counter = low;

		while (i <= mid && j <= high) {
			if (tempArray[i] < tempArray[j]) {
				array[counter] = tempArray[i];
				i++;
			} else {
				array[counter] = tempArray[j];
				j++;
			}
			counter++;
		}
		while (i <= mid) {
			array[counter] = tempArray[i];
			counter++;
			i++;
		}
	}

	public static void main(String args[])
	{
		int[] ar = {1,100,928,6,2,47,92,0,10,77};
		MyMerge list = new MyMerge(ar);
		ar = list.sort();
	}

}
