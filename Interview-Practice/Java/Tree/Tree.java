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

	public void dfs(Node<T> curr)
	{
		System.out.println(curr.getData());
		if (curr.hasLeftChild() == true) {
			this.dfs(curr.getLeftChild());
		}

		if (curr.hasRightChild() == true) {
			this.dfs(curr.getRightChild());
		}
	}


	public static void main(String args[])
	{
		Tree<Integer> myTree = new Tree<Integer>(10);
		myTree.insert(1);
		myTree.insert(9);
		myTree.insert(7);
		myTree.insert(6);
		myTree.insert(11);
		myTree.insert(8);
		myTree.insert(0);
		myTree.insert(6);

		myTree.dfs(myTree.getRoot());
	}
}
