/**
    ���������
    ��������
*/

public static TreeNode createBinaryTree(LinkedList<Integer>inputList)
{
    TreeNode node = null;
    if(inputList == null || inputList.isEmpty()){
        return null;
    }
    Integer data = inputList.removeFirst();
    if(data!=null)
    {
        node = new TreeNode(data);
        node.leftChild = createBinaryTree(inputList);
        node.rightChild = createBinaryTree(inputList);
    }
    return node;
}

/**ǰ�к�������� �ݹ�ʵ��*/

public static void preOrderTraveral(TreeNode node)
{
    if(node == null)
    {
        return;
    }
    System.out.println(node.data);
    preOrderTraveral(ode.leftChild);
    preOrderTraveral()
}
