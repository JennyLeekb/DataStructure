package com.lkb.linkstack.bean;

import com.lkb.linkstack.exception.GenaralException;

public class LinkStack {
	
	private LSNode head; //ͷ���
	private int size ; //��ջ�д洢Ԫ�صĸ���
	
	/**
	 * ���캯��
	 */
	public LinkStack(){
		this.head = new LSNode();
		this.size = 0;
	}
	
	/**
	 * ���캯��
	 * @param stack
	 */
	public LinkStack(LinkStack stack){
		this.head = stack.getHead();
		size = stack.getSize();
	}
	
	
	/**
	 * ��ȡ��ջ�д洢��Ԫ�ظ���
	 * @return
	 */
	public int getSize(){
		return size;
	}
	
	/**
	 * �ж϶�ջ�Ƿ�Ϊ��
	 * @return
	 */
	public boolean stackNotEmpty(){
		if(size == 0)
			return false;
		else
			return true;
	}
	
	/**
	 * ��ȡͷ���
	 * @return
	 */
	public LSNode getHead(){
		return head;
	}
	
	/**
	 * ��ջ
	 * @param o
	 */
	public void push(Object o){
		LSNode newNode = new LSNode(o);
		newNode.next = head.next;
		head.next = newNode;
		size ++;
	}
	
	/**
	 * ��ջ
	 * @return
	 * @throws GenaralException 
	 */
	public Object pop() throws GenaralException{
		Object o = null;
		if(size == 0){
			throw new GenaralException("��ջΪ�գ���Ԫ�ؿɳ���");
		}
		
		LSNode p = head.next;
		o = p.data;
		head.next = p.next;
		
		p = null;
		size --;
		
		return o;
	}
	
	/**
	 * ��ȡջ��Ԫ��
	 * @return
	 * @throws GenaralException 
	 */
	public Object top() throws GenaralException{
		Object o = null;
		if(size == 0){
			throw new GenaralException("��ջΪ�գ���Ԫ�ؿɳ���");
		}
		
		o = head.next.data;
		
		return o;
	}
	
	/**
	 * ��ӡ��ջ�е�Ԫ��
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
	 * ������
	 * @author LKB
	 *
	 */
	class LSNode {
		private Object data; //�洢����
		private LSNode next; //nextָ��
		
		public LSNode(){
		}
		
		public LSNode(Object data){
			this.data = data;
			this.next = null;
		}
	}

}
