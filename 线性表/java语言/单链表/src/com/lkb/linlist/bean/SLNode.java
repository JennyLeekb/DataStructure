package com.lkb.linlist.bean;

public class SLNode {
	
	private Object data; //������
	private SLNode next; //nextָ����
	
	/**
	 * ���캯��
	 */
	public SLNode(){
		
	}
	
	/**
	 * ���캯��
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
