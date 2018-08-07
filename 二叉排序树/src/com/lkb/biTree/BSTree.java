package com.lkb.biTree;


/**
 * ����һ�ö��������
 * �ص㣺���� < ����� < �Һ���
 * @author LKB
 *
 */
public class BSTree {
	
	private int data; //Ԫ��
	
	private BSTree left; //������
	
	private BSTree right;//������
	
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
	 * ����ֻ����һ�����Ķ��������
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
