import java.io.*;
import java.util.*;

public class Main {
	public static void main (String[] args) throws IOException {
		File file = new File(args[0]);
		BufferedReader buffer = new BufferedReader(new
				FileReader(file));
		String line;
		boolean firstRun = true;
		while ((line = buffer.readLine()) != null) {
			line = line.trim();
			// Process line of input Here
			if(firstRun == true) {
				firstRun = false;
			} else {
				System.out.print('\n');
			}
			int[][] arr = new int[5][6];
			int numOfJobs = getNumOfJobs(line);
			int matrixLen = (numOfJobs * 2) + 2;
			int[][] graph = new int[matrixLen][matrixLen];
			int[][] resGraph = new int[matrixLen][matrixLen];
			String nodeInfo = line.substring(3, line.length());
			processInput(nodeInfo, graph, numOfJobs, matrixLen);
			createResGraph(graph, resGraph, matrixLen);
			int[] path = new int[matrixLen];
			int maxFlow = fordfulk(resGraph,numOfJobs, matrixLen);
			if(maxFlow == numOfJobs) {
				System.out.print("Yes");
			} else {
				System.out.print("No");
			}
		}
	}

	private static void createResGraph(int[][] ar, int[][] r, int l) {
		for(int i = 0; i < l; i++) {
			for(int k = 0; k < l; k++) {
				r[i][k] = ar[i][k]; 
			}
		}
	}

	private static void processInput(String s, int[][] ar, int jobs, int matrixLen) {

		int source = 0;
		int sink = matrixLen - 1;
		int startingMemIndex = 1;
		int startingJobIndex = startingMemIndex + jobs;

		initializeArray(ar, matrixLen);
		ar[0][0] = 0;
		for(int i = 1; i < startingJobIndex; i++) {
			ar[0][i] = 1;
		}
		for(int i = startingJobIndex; i < sink; i++) {
			ar[i][sink] = 1;
		}
		int jobsCounter = 0;
		int counter = 0;
		while(jobsCounter < jobs) {
			if(s.substring(counter, counter + 1).equals("[")) {
				counter++;
				jobsCounter++;
				int num = 0;
				String number = "";
				while(!s.substring(counter, counter + 1).equals("]")) {
					if(s.substring(counter, counter + 1).equals(",")) {
						int tempNum = Integer.parseInt(number);
						int tempOffice = tempNum + jobs;
						ar[jobsCounter][tempOffice] = 1;
						number = "";
						counter++;
					} else {
						number+=s.substring(counter, counter + 1);
					}
					counter++;
				}
				if(!number.equals("")) {
					int tempNum = Integer.parseInt(number);
					int tempOffice = tempNum + jobs;
					ar[jobsCounter][tempOffice] = 1;
				}
			}
			counter++;
		}
	}

	private static void print2DArray(int ar[][], int l) {
		System.out.println("Printing Array: ");
		for(int i = 0; i < l; i++) {
			for(int k = 0; k < l; k++) {
				System.out.print(ar[i][k]);
			}
			System.out.print('\n');
		}
	}

	private static void initializeArray(int[][] ar, int l) {
		for(int i = 0; i < l; i++) {
			for(int k = 0; k < l; k++) {
				ar[i][k] = 0;
			}
		}
	}

	private static boolean bfs(int[][] ar, int[] path, int jobs, int l){

		Queue<Integer> queue = new LinkedList<Integer>();
		boolean[] visited = new boolean[l];
		int source = 0;
		int sink = l - 1;
		visited[source] = true;
		path[source] = -1;

		queue.add(0);

		while(!queue.isEmpty()) {
			int top = queue.remove();
			for(int i = 0; i < l; i++) {
				if(ar[top][i] > 0 && visited[i] == false) {
					visited[i] = true;
					path[i] = top; 
					queue.add(i);
				}
			}
		}
		if(visited[sink] == true){
			return true;	
		} else {
			return false;
		}
	}

	private static int fordfulk(int[][] res,int jobs, int l) {

		int source = 0;
		int sink = l - 1;
		int[] path = new int[l];
		int maxFlow = 0;
		while(bfs(res, path, jobs, l) == true) {
			int currentNode = sink;
			while(currentNode != source) {
				int parent = path[currentNode];
				res[parent][currentNode] = 0;
				res[currentNode][parent] = 1;
				currentNode = parent;
			}
			maxFlow++;
		}
		return maxFlow;
	}

	private static int getNumOfJobs(String input) {
		int counter = 0;
		String numString = "";
		while(!input.substring(counter, counter + 1).equals(";")) {
			numString+= input.substring(counter, counter + 1);
			counter++;
		}

		int result = Integer.parseInt(numString);

		return result;
	}
}
