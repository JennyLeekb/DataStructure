package com.lkb.seqlist.bean;

import com.lkb.seqlist.exception.GenaralException;

public class SeqList{
	
	private int MAX_SIZE = 1000; //默认是1000
	private Object[] list;
	private int size;
	
	/**
	 * 构造函数
	 */
	public SeqList(){
		this.list = new Object[MAX_SIZE];
	}
	
	/**
	 * 构造函数
	 * @param maxSize
	 */
	public SeqList(int maxSize){
		this.MAX_SIZE = maxSize;
		this.list = new Object[MAX_SIZE];
	}
	
	/**
	 * 构造函数
	 * @param list
	 */
	public SeqList(Object[] seqList){
		this.list = seqList;
		this.size = seqList.length;
	}
	
	/**
	 * 获取顺序表大小
	 * @param list
	 * @return
	 */
	public int getSize(SeqList seqList){
		return seqList.size;
	}
	
	/**
	 * 插入元素
	 * @param list
	 * @param i
	 * @param x
	 */
	public void listInsert(SeqList seqList,int i, Object e) throws GenaralException{
		if(seqList.size >= MAX_SIZE){
			throw new GenaralException("顺序已满不能插入！");
		}
		
		if(i < 0 || i > seqList.size){
			throw new GenaralException("输入参数i错误！");
		}
		
		for(int j = seqList.size;j > i; j--){
			seqList.list[j] = seqList.list[j-1];
		}
		
		seqList.list[i] = e;
		seqList.size ++;
	}
	
	/**
	 * 删除元素
	 * @param seqList
	 * @param i
	 */
	public Object listDelete(SeqList seqList, int i) throws GenaralException{
		if(seqList.size == 0){
			throw new GenaralException("顺序表已空，无元素可删除！");
		}
		
		if(i < 0 || i>= seqList.size){
			throw new GenaralException("输入参数i错误");
		}
		
		Object e = seqList.list[i];
		
		for(int j = i; j < seqList.size; j++){ //前移数据
			seqList.list[j] = seqList.list[j+1];
		}
		
		seqList.size --;
		
		return e;
	}
	
	/**
	 * 修改数据
	 * @param seqList
	 * @param i
	 * @param e
	 */
	public void listEdit(SeqList seqList, int i, Object e) throws GenaralException{
		if(seqList.size == 0){
			throw new GenaralException("顺序表为空，无元素可修改！");
		}
		
		if(i < 0 || i >= seqList.size){
			throw new GenaralException("参数i错误！");
		}
		
		seqList.list[i] = e;
	}
	
	/**
	 * 获取元素
	 * @param seqList
	 * @param i
	 * @return
	 */
	public Object listGet(SeqList seqList, int i) throws GenaralException{
		if(seqList.size == 0){
			throw new GenaralException("顺序表为空，无元素可取！");
		}
		
		if(i < 0 || i >= seqList.size){
			throw new GenaralException("参数i错误！");
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

