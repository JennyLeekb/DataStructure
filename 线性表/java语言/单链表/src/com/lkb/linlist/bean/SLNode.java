package com.lkb.linlist.bean;

public class SLNode {
	
	private Object data; //数据域
	private SLNode next; //next指针域
	
	/**
	 * 构造函数
	 */
	public SLNode(){
		
	}
	
	/**
	 * 构造函数
	 * @param data
	 */
	public SLNode(Object data){
		this.data = data;
	}

	public Object getData() {
		return data;
	}

	public void setData(Object data) {
		this.data = data;
	}

	public SLNode getNext() {
		return next;
	}

	public void setNext(SLNode next) {
		this.next = next;
	}
}
