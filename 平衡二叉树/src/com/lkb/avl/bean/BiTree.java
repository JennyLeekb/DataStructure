package com.lkb.avl.bean;

public class BiTree {
	
	private int data;
	
	private BiTree left; //����
	
	private BiTree right; //�Һ���
	
	private BiTree root; //�����

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
