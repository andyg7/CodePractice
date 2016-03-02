import java.util.*;

public class Tree<T extends Comparable<T>>
{
	private Node<T> root;

	public Tree(T rootData)
	{
		root = new Node<T>(rootData);
	}

	public void insert(T data)
	{
		root.insert(data);
	}

	public Node<T> getRoot()
	{
		return root;
	}

	public void dfs(Node<T> curr, int i)
	{
		System.out.println(i + ": " + curr.getData());
		
		if (curr.hasLeftChild() == true) {
			this.dfs(curr.getLeftChild(), i + 1);
		}

		if (curr.hasRightChild() == true) {
			this.dfs(curr.getRightChild(), i + 1);
		}
	}

	public Node<T> addPath(Node<T> curr, T data, HashSet<T> hashSet)
	{
		T currData = curr.getData();

		hashSet.add(currData);

		if (currData.compareTo(data) == 0) {
			return curr;
		} else if (currData.compareTo(data) > 0) {
			if (curr.getLeftChild() != null) {
				return addPath(curr.getLeftChild(), data, hashSet);
			}
		} else {
			if (curr.getRightChild() != null) {
				return addPath(curr.getRightChild(), data, hashSet);
			}
		}
		return null;
	}

	public Node<T> searchPath(Node<T> curr, T data, HashSet<Integer> hashSet, Node<T> lowestNode)
	{
		System.out.println("Found: " + lowestNode.getData());
		T currData = curr.getData();

		if (hashSet.contains(currData)) {
			lowestNode.setData(currData);
		}

		if (currData.compareTo(data) == 0) {
			return lowestNode;
		} else if (currData.compareTo(data) > 0) {
			if (curr.getLeftChild() != null) {
				return searchPath(curr.getLeftChild(),
				data, hashSet, lowestNode);
			}
		} else {
			if (curr.getRightChild() != null) {
				return searchPath(curr.getRightChild(),
				data, hashSet, lowestNode);
			}
		}
		return lowestNode;
	}

	public static void main(String args[])
	{
		Tree<Integer> myTree = new Tree<Integer>(5);
		HashSet<Integer> hashSet = new HashSet<Integer>();
		myTree.insert(1);
		myTree.insert(9);
		myTree.insert(7);
		myTree.insert(6);
		myTree.insert(11);
		myTree.insert(8);
		myTree.insert(0);
		myTree.insert(10);

		myTree.dfs(myTree.getRoot(), 0);

		int numToFind = 7;
		int secondNum = 10;
		if (myTree.addPath(myTree.getRoot(), numToFind, hashSet) != null) {
		} else {
			System.out.println("did not find: " + numToFind) ;
		}

		Node<Integer> lowestNode = new Node<Integer>(-1);
		myTree.searchPath(myTree.getRoot(), secondNum, hashSet, lowestNode);

		if (lowestNode.getData() != -1) {
			System.out.println("Lowest common node: " + lowestNode.getData());
		} else {
			System.out.println(lowestNode.getData());
		}

		Node<Integer> n1 = new Node<Integer>(1);
		Node<Integer> n2 = new Node<Integer>(2);
		//test(n1, n2);
		System.out.println(n1.getData());

	}
}
