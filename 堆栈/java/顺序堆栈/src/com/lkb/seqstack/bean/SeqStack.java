package com.lkb.seqstack.bean;

import com.lkb.seqstack.exception.GenaralException;

public class SeqStack {
	
	private Object[] data;
	private int top; //ջ��ָ�룬ָ����һ����ջ��Ԫ��λ��
	private int MAX_SIZE = 10000;
	
	/**
	 * ���캯��
	 */
	public SeqStack(){
		this.data = new Object[MAX_SIZE];
		this.top = 0;
	}
	
	/**
	 * ���캯��
	 * @param maxSize
	 */
	public SeqStack(int maxSize){
		MAX_SIZE = maxSize;
		this.data = new Object[MAX_SIZE];
		this.top = 0;
	}
	
	/**
	 * ��ջ�Ƿ�ǿ�
	 * �ǿշ���true,�շ���false;
	 * @return
	 */
	public boolean stackIsNotEmpty(){
		if(top == 0)
			return false;
		else
			return true;
	}
	
	/**
	 * ��ȡ��ǰ��ջ�е�Ԫ��
	 * @return
	 */
	public int stackSize(){
		return top;
	}
	
	/**
	 * ��ջ
	 * @param o
	 * @throws GenaralException 
	 */
	public void stackPush(Object o) throws GenaralException{
		if(top > MAX_SIZE){
			throw new GenaralException("��ջ������������ջ��");
		}
		
		data[top] = o;
		top ++;
	}
	
	/**
	 * ��ջ
	 * @return
	 * @throws GenaralException
	 */
	public Object stackPop() throws GenaralException{
		if(top <= 0){
			throw new GenaralException("��ջΪ�գ��޷���ջ��");
		}
		
		top --;
		return data[top];
	}
	
	/**
	 * ��ȡջ��Ԫ��
	 * @return
	 * @throws GenaralException 
	 */
	public Object stackTop() throws GenaralException{
		if(top <= 0){
			throw new GenaralException("��ջΪ�գ��޷���ȡջ��Ԫ�أ�");
		}
		
		return data[top-1];
	}
	
	/**
	 * ��ӡ��ջ
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
