package com.lkb.avl.bean;

import com.lkb.avl.exception.GenaralException;

public class HBTree extends BiTree{
	
	
	/**
	 * �չ��캯��
	 */
	public HBTree(){
		
	}
	
	/**
	 * �������鹹��һ���µĶ���ƽ����
	 * @param data
	 */
	public HBTree(int[] data){
		HBTree tree = new HBTree();
		for(int x : data){
			insert(x,tree); //��������
		}
	}
	
	
	/**
	 * ��ƽ��������в�������
	 * @param data
	 * @param tree
	 */
	public void insert(int data,BiTree tree){
		if(tree == null)
			tree = new HBTree();
		if(tree.getRoot() == null){
			HBTree root = new HBTree();
			root.setData(data);
			tree.setRoot(root);
			try {
				checkBF(tree);
			} catch (GenaralException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			return;
		}
		
		if(data < tree.getRoot().getData()){
			insert(data,tree.getRoot().getLeft());
		}
		else{
			insert(data,tree.getRoot().getRight());
		}		
	}
	
	/**
	 * ���ƽ�����ӣ���������������ʹ������ƽ��������Ķ���
	 * ƽ������ֻ���� -1 0 1
	 * @param tree
	 * @throws GenaralException 
	 */
	private void checkBF(BiTree tree) throws GenaralException{
		if(tree == null || tree.getRoot() == null)
			throw new GenaralException("<<tree is empty.>>");
		
	}
	
	/**
	 * ��ȡ�������Ĳ���
	 * @param tree
	 * @return
	 */
	private int getLeftLevel(BiTree tree){
		int count = -1;
		while(tree != null && tree.getRoot() != null){
			count ++;
			tree = tree.getRoot().getLeft();
		}		
		return count;
	}
	
	/**
	 * ��ȡ�������Ĳ���
	 * @param tree
	 * @return
	 */
	private int getRightLevel(BiTree tree){
		int count = -1;
		while(tree != null && tree.getRoot() != null){
			count ++;
			tree = tree.getRoot().getRight();
		}		
		return count;
	}
	
	/**
	 * ��ȡƽ������
	 * @param tree
	 * @return
	 * @throws GenaralException
	 */
	private int getBF(BiTree tree) throws GenaralException{
		int leftLevel = getLeftLevel(tree);
		if(leftLevel == -1)
			throw new GenaralException("<<tree is empty.>>");
		
		int rightLevel = getRightLevel(tree);
		if(rightLevel == -1)
			throw new GenaralException("<<tree is empty.>>");
		
		return (leftLevel - rightLevel);
	}
	
	
	
}
