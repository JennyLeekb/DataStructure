package com.lkb.seqstack.bean;

import com.lkb.seqstack.exception.GenaralException;

public class SeqStack {
	
	private Object[] data;
	private int top; //栈顶指针，指向下一个入栈的元素位置
	private int MAX_SIZE = 10000;
	
	/**
	 * 构造函数
	 */
	public SeqStack(){
		this.data = new Object[MAX_SIZE];
		this.top = 0;
	}
	
	/**
	 * 构造函数
	 * @param maxSize
	 */
	public SeqStack(int maxSize){
		MAX_SIZE = maxSize;
		this.data = new Object[MAX_SIZE];
		this.top = 0;
	}
	
	/**
	 * 堆栈是否非空
	 * 非空返回true,空返回false;
	 * @return
	 */
	public boolean stackIsNotEmpty(){
		if(top == 0)
			return false;
		else
			return true;
	}
	
	/**
	 * 获取当前堆栈中的元素
	 * @return
	 */
	public int stackSize(){
		return top;
	}
	
	/**
	 * 入栈
	 * @param o
	 * @throws GenaralException 
	 */
	public void stackPush(Object o) throws GenaralException{
		if(top > MAX_SIZE){
			throw new GenaralException("堆栈已满，不可入栈！");
		}
		
		data[top] = o;
		top ++;
	}
	
	/**
	 * 出栈
	 * @return
	 * @throws GenaralException
	 */
	public Object stackPop() throws GenaralException{
		if(top <= 0){
			throw new GenaralException("堆栈为空，无法出栈！");
		}
		
		top --;
		return data[top];
	}
	
	/**
	 * 获取栈顶元素
	 * @return
	 * @throws GenaralException 
	 */
	public Object stackTop() throws GenaralException{
		if(top <= 0){
			throw new GenaralException("堆栈为空，无法获取栈顶元素！");
		}
		
		return data[top-1];
	}
	
	/**
	 * 打印堆栈
	 */
	public void stackPrint(){
		int p = top;
		while(p > 0){
			p --;
			System.out.print(data[p] + " -> ");
		}
		System.out.println();
	}
}
