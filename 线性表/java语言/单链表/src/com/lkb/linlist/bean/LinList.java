package com.lkb.linlist.bean;

import com.lkb.linlist.exception.GenaralException;

public class LinList {
	
	private SLNode head; //ͷ���
	private int size; //��ǰ�洢���ݸ���
	
	/**
	 * ���캯��
	 */
	public LinList(){
		this.head = new SLNode();
		this.size = 0;
	}
	
	/**
	 * ���캯��
	 * @param list
	 */
	public LinList(LinList list){
		this.head = list.getHead();
		this.size = list.getSize();
	}
	
	/**
	 * ���������в�������
	 * @param i
	 * @param data
	 * @throws GenaralException 
	 */
	public void listInsert(int i,Object data) throws GenaralException{
		if(i < 0 || i > size){
			throw new GenaralException("����i����");
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
	 * ɾ��i�ϵ�Ԫ��
	 * @param i
	 * @return ����ɾ����Ԫ��
	 * @throws GenaralException 
	 */
	public Object listDelete(int i) throws GenaralException{
		Object result = null;
		
		if(i < 0 || i > size-1){
			throw new GenaralException("����i����");
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
	 * �޸ĵ������е�����
	 * @param i
	 * @param data
	 * @throws GenaralException 
	 */
	public void listEdit(int i, Object data) throws GenaralException{
		if(i < 0 || i > size-1){
			throw new GenaralException("����i����");
		}
		
		SLNode p = head;
		for(int j = 0; j < i; j++){
			p = p.getNext();
		}
		
		p.getNext().setData(data);		
	}
	
	/**
	 * ��ȡ��������iλ�õ�����
	 * @param i
	 * @return
	 * @throws GenaralException
	 */
	public Object listGet(int i) throws GenaralException{
		Object result = null;
		if(i < 0 || i > size-1){
			throw new GenaralException("����i����");
		}
		
		SLNode p = head;
		for(int j = 0; j < i; j++){
			p = p.getNext();
		}
		
		result = p.getNext().getData();
		
		return result;
	}
	
	/**
	 * ��ӡ������
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
