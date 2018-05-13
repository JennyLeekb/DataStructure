package com.lkb.seqlist.test;

import com.lkb.seqlist.SeqList;

public class Test {

	public static void main(String[] args) {
		SeqList seqList = new SeqList();
		for(int i = 0 ; i < 20 ; i++){
			seqList.insertElement(i+1, i);
		}
		
		System.out.println("size is :" + seqList.getSize());
		seqList.printSeqList();
		
		System.out.println(seqList.getElement(11));
		
		System.out.println(seqList.delete(13));
		
		System.out.println("size is :" + seqList.getSize());
		seqList.printSeqList();
		
	}
}
