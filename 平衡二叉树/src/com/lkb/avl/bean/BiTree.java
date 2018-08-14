package com.lkb.avl.bean;

public class BiTree {
	
	private int data;
	
	private BiTree left; //左孩子
	
	private BiTree right; //右孩子
	
	private BiTree root; //根结点

	public int getData() {
		return data;
	}

	public void setData(int data) {
		this.data = data;
	}

	public BiTree getLeft() {
		return left;
	}

	public BiTree getRoot() {
		return root;
	}

	public void setRoot(BiTree root) {
		this.root = root;
	}

	public void setLeft(BiTree left) {
		this.left = left;
	}

	public BiTree getRight() {
		return right;
	}

	public void setRight(BiTree right) {
		this.right = right;
	}	
	
	
}
