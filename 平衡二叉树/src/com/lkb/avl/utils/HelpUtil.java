package com.lkb.avl.utils;

import com.lkb.avl.bean.BiTree;

public class HelpUtil {
	
	/**
	 * ÖÐÐò±éÀú¶þ²æÊ÷
	 */
	public static void inOrderTraverse(BiTree tree){
		if(tree == null || tree.getRoot() == null){
			return;
		}
		inOrderTraverse(tree.getRoot().getLeft());
		System.out.print(tree.getRoot().getData()+ " -> ");
		inOrderTraverse(tree.getRoot().getRight());
	}
}
