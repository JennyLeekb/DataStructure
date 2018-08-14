package com.lkb.avl.bean;

import com.lkb.avl.exception.GenaralException;

public class HBTree extends BiTree{
	
	
	/**
	 * 空构造函数
	 */
	public HBTree(){
		
	}
	
	/**
	 * 传入数组构造一棵新的二叉平衡树
	 * @param data
	 */
	public HBTree(int[] data){
		HBTree tree = new HBTree();
		for(int x : data){
			insert(x,tree); //插入数据
		}
	}
	
	
	/**
	 * 往平衡二叉树中插入数据
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
	 * 检查平衡因子，并调整二叉树，使它符合平衡二叉树的定义
	 * 平衡因子只能是 -1 0 1
	 * @param tree
	 * @throws GenaralException 
	 */
	private void checkBF(BiTree tree) throws GenaralException{
		if(tree == null || tree.getRoot() == null)
			throw new GenaralException("<<tree is empty.>>");
		
	}
	
	/**
	 * 获取左子树的层数
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
	 * 获取右子树的层数
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
	 * 获取平衡因子
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
