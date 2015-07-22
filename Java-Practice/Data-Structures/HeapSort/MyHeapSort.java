import java.util.*;

public class MyHeapSort {

	private int highestIndex;
	int[] heap;
	private int privNum = 10;

	/*
		Constructor takes an array of ints to sort and automatically
		calls sort method
	*/

	public void setPrivateNum(int i) {
		privNum = i;
	}

	public int getPrivateNum(int i) {
		return privateNum;
	}

	public MyHeapSort(int[] arr) {
		heap = arr;
		highestIndex = heap.length - 1;
		int heapSize = heap.length;
		sort(arr);
	}
	/*
		Sort method first turns unordered list into a heap. 
		Then we go through and pop the first element from root(which is
		the largest) and reorder the heap after each pop.
	*/
	public void sort(int[] a) {
		heapify(a, a.length);
		int counter = highestIndex;
		for(int i = counter; i > 0 ; i--) {
			swap(a, 0, i);
			highestIndex--;	 
			maxHeap(a, 0); 
		}

	}

	/*

		Turns an unordered array of ints into a heap.
		@s size of array

	*/

	private void heapify(int[] a, int s) {
		
		int heapSize = s;
		int counter = (highestIndex - 1) / 2;
		for(int i = counter; i >= 0 ; i--) {
			maxHeap(a, i); 
			//System.out.println("jj" + i);
		}

	}

	/*
		Converts array into heap from a given node and below
	*/
	
	private void maxHeap(int[] a, int index) {

		int parent = index;
		int leftChild = (parent * 2) + 1;
		int rightChild = (parent * 2) + 2;
		//System.out.println("prt" + parent);
		//System.out.println("lc" + leftChild + "rc" + rightChild);

		int hIndex = index;

		if((leftChild <= highestIndex) && (a[index] < a[leftChild])) {
			hIndex = leftChild;	
		}

		if((rightChild <= highestIndex) && (a[hIndex] < a[rightChild])) {
			hIndex = rightChild;
		}

		if(hIndex != index) {
			//System.out.println("swapping: " + a[hIndex]);
			//System.out.println("with " + a[index]);
			swap(a, index, hIndex);
			maxHeap(a, hIndex);
		}

	}

	private void swap(int[] a, int index1, int index2) {
		int tempNum = a[index1];
		a[index1] = a[index2];
		a[index2] = tempNum;
	}


	public void printHeap() {
		for(int i = 0; i < heap.length; i++) {
			 System.out.print(heap[i] + " ");
		}
		System.out.print('\n');
	}

}

