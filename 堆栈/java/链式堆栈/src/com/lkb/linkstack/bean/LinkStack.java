package com.lkb.linkstack.bean;

import com.lkb.linkstack.exception.GenaralException;

public class LinkStack {
	
	private LSNode head; //头结点
	private int size ; //堆栈中存储元素的个数
	
	/**
	 * 构造函数
	 */
	public LinkStack(){
		this.head = new LSNode();
		this.size = 0;
	}
	
	/**
	 * 构造函数
	 * @param stack
	 */
	public LinkStack(LinkStack stack){
		this.head = stack.getHead();
		size = stack.getSize();
	}
	
	
	/**
	 * 获取堆栈中存储的元素个数
	 * @return
	 */
	public int getSize(){
		return size;
	}
	
	/**
	 * 判断堆栈是否为空
	 * @return
	 */
	public boolean stackNotEmpty(){
		if(size == 0)
			return false;
		else
			return true;
	}
	
	/**
	 * 获取头结点
	 * @return
	 */
	public LSNode getHead(){
		return head;
	}
	
	/**
	 * 入栈
	 * @param o
	 */
	public void push(Object o){
		LSNode newNode = new LSNode(o);
		newNode.next = head.next;
		head.next = newNode;
		size ++;
	}
	
	/**
	 * 出栈
	 * @return
	 * @throws GenaralException 
	 */
	public Object pop() throws GenaralException{
		Object o = null;
		if(size == 0){
			throw new GenaralException("堆栈为空，无元素可出！");
		}
		
		LSNode p = head.next;
		o = p.data;
		head.next = p.next;
		
		p = null;
		size --;
		
		return o;
	}
	
	/**
	 * 获取栈顶元素
	 * @return
	 * @throws GenaralException 
	 */
	public Object top() throws GenaralException{
		Object o = null;
		if(size == 0){
			throw new GenaralException("堆栈为空，无元素可出！");
		}
		
		o = head.next.data;
		
		return o;
	}
	
	/**
	 * 打印堆栈中的元素
	 */
	public void printStack(){
		LSNode p = head;
		while(p.next != null){	
			p = p.next;
			System.out.print(p.data + " -> ");
		}
		System.out.println();
	}
	
	/**
	 * 定义结点
	 * @author LKB
	 *
	 */
	class LSNode {
		private Object data; //存储数据
		private LSNode next; //next指针
		
		public LSNode(){
		}
		
		public LSNode(Object data){
			this.data = data;
			this.next = null;
		}
	}

}
