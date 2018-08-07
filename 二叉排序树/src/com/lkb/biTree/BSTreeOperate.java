package com.lkb.biTree;

/**
 * �����������Ĳ��롢ɾ�������Ҳ���
 * �ص㣺���� < ����� < �Һ���
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
	 * �ڶ���������в�������
	 * ������ҵ����ݣ��򷵻�true��
	 * ���û�в��ҵ����ݣ��򷵻�false�����Ҹ����Ƿ����ı�־λ������������
	 * @param data
	 * @param tree
	 * @param flag true��ʾ��Ҫ��������
	 * @return
	 */
	public static boolean bstreeSearch(int data, BSTree tree, boolean flag){
		boolean result = false;
		if(tree.getRoot() == null){//��������Ϊ�գ���ʾΪһ�ÿ���
			if(flag){//��������
				BSTree newTree = new BSTree(data);
				tree.setRoot(newTree);
			}
			return false;
		}
		
		if(data == tree.getRoot().getData()){ //����ؼ��ֵ��ڸ�����ʾ�����ݣ�����true
			return true;
		}
		
		if(data < tree.getRoot().getData()){ //����ؼ��ֱȸ��ڵ�С�������������; ����ؼ��ֱȸ����󣬲���������			
			result = bstreeSearch(data, tree.getRoot().getLeft(), flag); 
		}
		else{
			result = bstreeSearch(data, tree.getRoot().getRight(), flag);
		}
		
		return result;
	}
	
	/**
	 * ���뵥������ 
	 * @param data
	 * @param tree
	 * @return
	 */
	public static void bstreeInsert(int data, BSTree tree){
		bstreeSearch(data,tree,true);
	}
	
	/**
	 * ����һ������
	 * @param data
	 * @param tree
	 */
	public static void bstreeInsert(int[] dataArr, BSTree tree){
		for(int i=0;i<dataArr.length;i++){
			bstreeInsert(dataArr[i], tree);
		}
	}
	
	
	/**
	 * ɾ������
	 * �ҵ���Ҫɾ���Ľ��p��ֱ��ǰ��������ֱ�Ӻ�̣����s���滻��p��Ȼ����ɾ�����p
	 * @param data
	 * @param tree
	 */
	public static void bstreeDelete(int data, BSTree tree){
		if(!bstreeSearch(data, tree, false)) //������Ҳ�����Ҫɾ���Ľ����ֱ�ӷ���
			return ;
		
		if(data == tree.getRoot().getData()){ //���ڸ�����ֵ
			delete(data,tree);
		}
		else if(data < tree.getRoot().getData()){ //С�ڸ�����ֵ
			bstreeDelete(data, tree.getRoot().getLeft());
		}
		else{//���ڸ�����ֵ
			bstreeDelete(data, tree.getRoot().getRight());
		}
		
	}
	
	/**
	 * �����ɾ������
	 */
	private static void delete(int data, BSTree tree){
		
		boolean rightIsNull = (tree.getRoot().getRight().getRoot() == null);
		boolean leftIsNull = (tree.getRoot().getLeft().getRoot() == null);
		
		if(rightIsNull && leftIsNull){ //Ҷ�ӽ��ֱ������
			destroyNode(tree);
			return;
		}
		
		if(rightIsNull){ //��Ҫɾ���Ľ���������Ϊ�գ�ֻ��Ҫ��������������
			tree.setRoot(tree.getRoot().getLeft().getRoot());
			return;
		}
		
		if(leftIsNull){ //��Ҫɾ���Ľ���������Ϊ�գ�ֻ��Ҫ��������������
			tree.setRoot(tree.getRoot().getRight().getRoot());	
			return;
		}
		
		//������������Ϊ�գ��ҵ�ǰ����㣬ʹ��ǰ������滻����Ҫɾ���Ľ��
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
		
		if(isLeafNode(before)){//�����Ҷ�ӽ��
			destroyNode(before);
			return;
		}else{ //����Ҷ�ӽ����ݲ��Ҷ��������ص㣬��ֻ��������
			left.getRoot().getRight().setRoot((before.getRoot().getLeft().getRoot()));
		}	
	}
	
	/**
	 * ����һ�����
	 * @param tree
	 */
	private static void destroyNode(BSTree tree){
		tree.setData(0);
		tree.setRoot(null); //��Ҷ�ӽ��ĸ��ڵ�����Ϊ��
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
	 * �����ӡ������
	 * @param tree
	 */
	public static void printTree(BSTree tree){
		inOrderTraverse(tree);
		System.out.println();
	}
	
	/**
	 * �������������
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
