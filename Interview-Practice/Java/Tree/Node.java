public class Node<T extends Comparable<T>>
{
	private T data;
	private Node<T> leftChild;
	private Node<T> rightChild;

	public Node(T in) 
	{
		this.data = in;	
	}

	public int insert(T in)
	{
		if (in.compareTo(data) > 0) {
			if (rightChild != null) {
				rightChild.insert(in);			
			} else {
				rightChild = new Node<T>(in);
			}
		} else if (in.compareTo(data) < 0) {
			if (leftChild != null) {
				leftChild.insert(in);			
			} else {
				leftChild = new Node<T>(in);
			}
		}
		return 0;
	}

	public boolean hasRightChild()
	{
		if (rightChild != null) {
			return true;
		}
		return false;
	}

	public boolean hasLeftChild()
	{
		if (leftChild != null) {
			return true;
		}
		return false;
	}

	public Node<T> getRightChild()
	{
		if (hasRightChild() == true) {
			return rightChild;
		} else {
			return null;
		}
	}

	public Node<T> getLeftChild()
	{
		if (hasLeftChild() == true) {
			return leftChild;
		} else {
			return null;
		}
	}

	public T getData() 
	{
		return data;
	}
}
