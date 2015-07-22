import java.util.Scanner;

public class Main {

	public static void main(String args[]) {

		
		Scanner scan = new Scanner( System.in );        
		System.out.println("Heap Sort Test\n");
		int n, i;    
		/* Accept number of elements */
		System.out.println("Enter number of integer elements");
		n = scan.nextInt();    
		/* Make array of n elements */
		int arr[] = new int[ n ];
		/* Accept elements */
		System.out.println("\nEnter "+ n +" integer elements");
		for (i = 0; i < n; i++)
			arr[i] = scan.nextInt();
		/* Call method sort */
		MyHeapSort heap = new MyHeapSort(arr);
		/* Print sorted Array */
		System.out.println("\nElements after sorting ");        
		heap.printHeap();

		System.out.println(heap.getPrivateNum);
		heap.setPrivateNum(5);
		System.out.println(heap.getPrivateNum);

	}



}
