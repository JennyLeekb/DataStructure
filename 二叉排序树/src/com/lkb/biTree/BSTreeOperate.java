package com.lkb.biTree;

/**
 * 二叉排序树的插入、删除、查找操作
 * 特点：左孩子 < 根结点 < 右孩子
 * @author LKB
 *
 */
public class BSTreeOperate {

	public static void main(String[] args) {
		BSTree tree = new BSTree();		
		int[] data = {62,58,47,35,29,36,37,48,49,50,51,56,73,88,93,99};
		bstreeInsert(data, tree);
		printTree(tree);
		bstreeDelete(58, tree);
		printTree(tree);
	}
	
	
	/**
	 * 在二叉查找树中查找数据
	 * 如果查找到数据，则返回true，
	 * 如果没有查找到数据，则返回false，并且根据是否插入的标志位，进入插入操作
	 * @param data
	 * @param tree
	 * @param flag true表示需要插入数据
	 * @return
	 */
	public static boolean bstreeSearch(int data, BSTree tree, boolean flag){
		boolean result = false;
		if(tree.getRoot() == null){//如果根结点为空，表示为一棵空树
			if(flag){//插入数据
				BSTree newTree = new BSTree(data);
				tree.setRoot(newTree);
			}
			return false;
		}
		
		if(data == tree.getRoot().getData()){ //如果关键字等于根结点表示的数据，返回true
			return true;
		}
		
		if(data < tree.getRoot().getData()){ //如果关键字比根节点小，则查找左子树; 如果关键字比根结点大，查找右子树			
			result = bstreeSearch(data, tree.getRoot().getLeft(), flag); 
		}
		else{
			result = bstreeSearch(data, tree.getRoot().getRight(), flag);
		}
		
		return result;
	}
	
	/**
	 * 插入单个数据 
	 * @param data
	 * @param tree
	 * @return
	 */
	public static void bstreeInsert(int data, BSTree tree){
		bstreeSearch(data,tree,true);
	}
	
	/**
	 * 插入一组数据
	 * @param data
	 * @param tree
	 */
	public static void bstreeInsert(int[] dataArr, BSTree tree){
		for(int i=0;i<dataArr.length;i++){
			bstreeInsert(dataArr[i], tree);
		}
	}
	
	
	/**
	 * 删除操作
	 * 找到需要删除的结点p的直接前驱（或者直接后继）结点s来替换掉p，然后再删除结点p
	 * @param data
	 * @param tree
	 */
	public static void bstreeDelete(int data, BSTree tree){
		if(!bstreeSearch(data, tree, false)) //如果查找不到需要删除的结点则直接返回
			return ;
		
		if(data == tree.getRoot().getData()){ //等于根结点的值
			delete(data,tree);
		}
		else if(data < tree.getRoot().getData()){ //小于根结点的值
			bstreeDelete(data, tree.getRoot().getLeft());
		}
		else{//大于根结点的值
			bstreeDelete(data, tree.getRoot().getRight());
		}
		
	}
	
	/**
	 * 具体的删除操作
	 */
	private static void delete(int data, BSTree tree){
		
		boolean rightIsNull = (tree.getRoot().getRight().getRoot() == null);
		boolean leftIsNull = (tree.getRoot().getLeft().getRoot() == null);
		
		if(rightIsNull && leftIsNull){ //叶子结点直接销毁
			destroyNode(tree);
			return;
		}
		
		if(rightIsNull){ //需要删除的结点的右子树为空，只需要重新连接左子树
			tree.setRoot(tree.getRoot().getLeft().getRoot());
			return;
		}
		
		if(leftIsNull){ //需要删除的结点的左子树为空，只需要重新连接左子树
			tree.setRoot(tree.getRoot().getRight().getRoot());	
			return;
		}
		
		//左右子树都不为空，找到前驱结点，使用前驱结点替换掉需要删除的结点
		BSTree left = tree.getRoot().getLeft();
		BSTree before = left;
		while(true){
			if(before.getRoot() != null && before.getRoot().getRight().getRoot() != null){
				left = before;
				before = before.getRoot().getRight() ;
			}
			else{
				break;
			}
		}	
		
		tree.getRoot().setData(before.getRoot().getData());
		
		if(isLeafNode(before)){//如果是叶子结点
			destroyNode(before);
			return;
		}else{ //不是叶子结点根据查找二叉树的特点，则只有左子树
			left.getRoot().getRight().setRoot((before.getRoot().getLeft().getRoot()));
		}	
	}
	
	/**
	 * 销毁一个结点
	 * @param tree
	 */
	private static void destroyNode(BSTree tree){
		tree.setData(0);
		tree.setRoot(null); //将叶子结点的根节点设置为空
		tree.setLeft(null);
		tree.setRight(null);
		tree = null;
	}
	
	private static boolean isLeafNode(BSTree tree){	
		boolean rightIsNull = (tree.getRoot().getRight().getRoot() == null);
		boolean leftIsNull = (tree.getRoot().getLeft().getRoot() == null);
		
		if(rightIsNull && leftIsNull)
			return true;
		else
			return false;
	}
	
	/**
	 * 中序打印二叉树
	 * @param tree
	 */
	public static void printTree(BSTree tree){
		inOrderTraverse(tree);
		System.out.println();
	}
	
	/**
	 * 中序遍历二叉树
	 */
	private static void inOrderTraverse(BSTree tree){
		if(tree.getRoot() == null){
			return;
		}
		inOrderTraverse(tree.getRoot().getLeft());
		System.out.print(tree.getRoot().getData()+ " -> ");
		inOrderTraverse(tree.getRoot().getRight());
	}
	
	
}
