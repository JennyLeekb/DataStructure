package com.lkb.linlist.test;

import com.lkb.linlist.bean.LinList;
import com.lkb.linlist.exception.GenaralException;

public class Test {
	
	public static void main(String[] args){
		try {
			LinList list = new LinList();
			for(int i = 0; i < 10; i++){
				list.listInsert(i, i+1);
			}
			System.out.println("list size is " + list.getSize());
			list.listPrint();
			
			list.listDelete(0);
			System.out.println("list size is " + list.getSize());
			
			list.listEdit(6, 7890);
			System.out.println("data in 6 is " + list.listGet(6));
			
			list.listPrint();

		} catch (GenaralException e) {
			// TODO: handle exception
			System.out.println(e.getMessage());
		}
	}

}
