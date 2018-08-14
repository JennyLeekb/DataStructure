package com.lkb.seqlist.test;

import com.lkb.seqlist.bean.SeqList;
import com.lkb.seqlist.exception.GenaralException;

public class Test {

	public static void main(String[] args) {
		SeqList seqList = new SeqList();
		try{
			for(int i=0; i<10; i++){
				seqList.listInsert(seqList, i, i+1);
			}
			
			int size = seqList.getSize(seqList);
			System.out.println("list size is " + size);
			
			for(int i=0; i < size; i++){
				System.out.println(seqList.listGet(seqList, i));
			}
			
			seqList.listDelete(seqList, 8);
			size = seqList.getSize(seqList);
			System.out.println("list size is " + size);
			
			seqList.listEdit(seqList, 4, 1000);
			
			seqList.printList();
			
			
		}catch(GenaralException e){
			System.out.println(e.getMessage());
		}
		
	}
	
}
