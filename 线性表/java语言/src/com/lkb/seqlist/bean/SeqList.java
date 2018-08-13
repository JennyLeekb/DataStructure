package com.lkb.seqlist.bean;

import com.lkb.seqlist.exception.GenaralException;

public class SeqList{
	
	private int MAX_SIZE = 1000; //Ĭ����1000
	private Object[] list;
	private int size;
	
	/**
	 * ���캯��
	 */
	public SeqList(){
		this.list = new Object[MAX_SIZE];
	}
	
	/**
	 * ���캯��
	 * @param maxSize
	 */
	public SeqList(int maxSize){
		this.MAX_SIZE = maxSize;
		this.list = new Object[MAX_SIZE];
	}
	
	/**
	 * ���캯��
	 * @param list
	 */
	public SeqList(Object[] seqList){
		this.list = seqList;
		this.size = seqList.length;
	}
	
	/**
	 * ��ȡ˳����С
	 * @param list
	 * @return
	 */
	public int getSize(SeqList seqList){
		return seqList.size;
	}
	
	/**
	 * ����Ԫ��
	 * @param list
	 * @param i
	 * @param x
	 */
	public void listInsert(SeqList seqList,int i, Object e) throws GenaralException{
		if(seqList.size >= MAX_SIZE){
			throw new GenaralException("˳���������ܲ��룡");
		}
		
		if(i < 0 || i > seqList.size){
			throw new GenaralException("�������i����");
		}
		
		for(int j = seqList.size;j > i; j--){
			seqList.list[j] = seqList.list[j-1];
		}
		
		seqList.list[i] = e;
		seqList.size ++;
	}
	
	/**
	 * ɾ��Ԫ��
	 * @param seqList
	 * @param i
	 */
	public Object listDelete(SeqList seqList, int i) throws GenaralException{
		if(seqList.size == 0){
			throw new GenaralException("˳����ѿգ���Ԫ�ؿ�ɾ����");
		}
		
		if(i < 0 || i>= seqList.size){
			throw new GenaralException("�������i����");
		}
		
		Object e = seqList.list[i];
		
		for(int j = i; j < seqList.size; j++){ //ǰ������
			seqList.list[j] = seqList.list[j+1];
		}
		
		seqList.size --;
		
		return e;
	}
	
	/**
	 * �޸�����
	 * @param seqList
	 * @param i
	 * @param e
	 */
	public void listEdit(SeqList seqList, int i, Object e) throws GenaralException{
		if(seqList.size == 0){
			throw new GenaralException("˳���Ϊ�գ���Ԫ�ؿ��޸ģ�");
		}
		
		if(i < 0 || i >= seqList.size){
			throw new GenaralException("����i����");
		}
		
		seqList.list[i] = e;
	}
	
	/**
	 * ��ȡԪ��
	 * @param seqList
	 * @param i
	 * @return
	 */
	public Object listGet(SeqList seqList, int i) throws GenaralException{
		if(seqList.size == 0){
			throw new GenaralException("˳���Ϊ�գ���Ԫ�ؿ�ȡ��");
		}
		
		if(i < 0 || i >= seqList.size){
			throw new GenaralException("����i����");
		}
		
		return seqList.list[i];
	}
	
	public void printList(){
		for(int i=0; i< size; i++){
			System.out.print(list[i] + " -> ");
		}
		System.out.println();
	}
	
}

