package com.lkb.seqstack.test;

import com.lkb.seqstack.bean.SeqStack;
import com.lkb.seqstack.exception.GenaralException;

public class Test {
	
	public static void main(String[] args) throws GenaralException{
		try{
			SeqStack stack = new SeqStack();
			if(stack.stackIsNotEmpty()){
				System.out.println("stack not empty!");
			}else{
				System.out.println("stack is empty!");
			}
			
			
			for(int i=0;i<10;i++){
				stack.stackPush(i);
			}
			int size = stack.stackSize();
			System.out.println("stack size is "+size);
			stack.stackPrint();
			
			Object topEle = stack.stackTop();
			System.out.println("stack top data is " + topEle);
			
			stack.stackPop();
			size = stack.stackSize();
			System.out.println("stack size is "+size);
			stack.stackPrint();
			
			
		}catch(GenaralException e){
			System.out.println(e.getMessage());
		}
	}

}
