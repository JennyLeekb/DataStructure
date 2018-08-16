package com.lkb.linkstack.test;

import com.lkb.linkstack.bean.LinkStack;
import com.lkb.linkstack.exception.GenaralException;

public class Test {
	
	public static void main(String[] args){
		try{
			LinkStack stack = new LinkStack();
			stackNotEmpty(stack);
			
			for(int i=0;i<10;i++){
				stack.push(i);
			}
			stackNotEmpty(stack);
			stack.printStack();
			
			Object top = stack.pop();
			System.out.println("pop element: "+ top);
			int size = stack.getSize();
			System.out.println("stack size is " + size);
			
			top = stack.top();
			System.out.println("stack top element: " + top);
			
			stack.printStack();
			
		}catch(GenaralException e){
			System.out.println(e.getMessage());
		}
		
		
	}
	
	private static void stackNotEmpty(LinkStack stack){		
		if(stack.stackNotEmpty())
			System.out.println("stack not empty!");
		else
			System.out.println("stack is empty!");
	}
	

}
