package com.lkb.linlist.bean;

import com.lkb.linlist.exception.GenaralException;

public class LinList {
	
	private SLNode head; //头结点
	private int size; //当前存储数据个数
	
	/**
	 * 构造函数
	 */
	public LinList(){
		this.head = new SLNode();
		this.size = 0;
	}
	
	/**
	 * 构造函数
	 * @param list
	 */
	public LinList(LinList list){
		this.head = list.getHead();
		this.size = list.getSize();
	}
	
	/**
	 * 往单链表中插入数据
	 * @param i
	 * @param data
	 * @throws GenaralException 
	 */
	public void listInsert(int i,Object data) throws GenaralException{
		if(i < 0 || i > size){
			throw new GenaralException("参数i错误");
		}
		
		SLNode p = head;
		for(int j = 0; j < i; j++){
			p = p.getNext();
		}
		
		SLNode q = new SLNode(data);
		q.setNext(p.getNext());
		p.setNext(q);
		
		size++;
	}
	
	/**
	 * 删除i上的元素
	 * @param i
	 * @return 返回删除的元素
	 * @throws GenaralException 
	 */
	public Object listDelete(int i) throws GenaralException{
		Object result = null;
		
		if(i < 0 || i > size-1){
			throw new GenaralException("参数i错误");
		}
		
		SLNode p = head;
		for(int j = 0; j < i; j++){
			p = p.getNext();
		}
		
		SLNode q = p.getNext();
		p.setNext(q.getNext());
		
		result = q.getData();
		q = null;
		size --;
		return result;
	}
	
	/**
	 * 修改单链表中的数据
	 * @param i
	 * @param data
	 * @throws GenaralException 
	 */
	public void listEdit(int i, Object data) throws GenaralException{
		if(i < 0 || i > size-1){
			throw new GenaralException("参数i错误");
		}
		
		SLNode p = head;
		for(int j = 0; j < i; j++){
			p = p.getNext();
		}
		
		p.getNext().setData(data);		
	}
	
	/**
	 * 获取单链表中i位置的数据
	 * @param i
	 * @return
	 * @throws GenaralException
	 */
	public Object listGet(int i) throws GenaralException{
		Object result = null;
		if(i < 0 || i > size-1){
			throw new GenaralException("参数i错误");
		}
		
		SLNode p = head;
		for(int j = 0; j < i; j++){
			p = p.getNext();
		}
		
		result = p.getNext().getData();
		
		return result;
	}
	
	/**
	 * 打印单链表
	 */
	public void listPrint(){
		SLNode p = head;
		for(int i = 0; i < size; i++){
			p = p.getNext(); 
			System.out.print(p.getData() + " -> ");
		}
		System.out.println();
	}

	public SLNode getHead() {
		return head;
	}

	public void setHead(SLNode head) {
		this.head = head;
	}

	public int getSize() {
		return size;
	}

	public void setSize(int size) {
		this.size = size;
	}
		
}
