package com.lkb.biTree;


/**
 * 定义一棵二叉查找树
 * 特点：左孩子 < 根结点 < 右孩子
 * @author LKB
 *
 */
public class BSTree {
	
	private int data; //元素
	
	private BSTree left; //左子树
	
	private BSTree right;//右子树
	
	private BSTree root;

	public BSTree getRoot() {
		return root;
	}

	public void setRoot(BSTree root) {
		this.root = root;
	}

	public BSTree(){
		
	}
	
	/**
	 * 构建只含有一个结点的二叉查找树
	 * @param data
	 */
	public BSTree(int data){
		this.data = data;
		this.left = new BSTree();
		this.right = new BSTree();
	}
	
	public int getData() {
		return data;
	}

	public void setData(int data) {
		this.data = data;
	}

	public BSTree getLeft() {
		return left;
	}

	public void setLeft(BSTree left) {
		this.left = left;
	}

	public BSTree getRight() {
		return right;
	}

	public void setRight(BSTree right) {
		this.right = right;
	}

}
