package com.lkb.seqlist;

import java.util.Arrays;


public class SeqList {

	private Object[] array;  //an array to hold the datas of SeqList
	private int size; //the number of datas in the SeqList
	private int capacity = 10; //the capacity of the array,init capacity is 10
	
	/**
	 * init the SeqList
	 * @param size
	 */
	public SeqList(){
		this.array = new Object[capacity];
		this.size = 0;
	}
	
	/**
	 * get the SeqList's size
	 * @return
	 */
	public int getSize(){
		return this.size;
	}
	
	/**
	 * insert data obj into SeqList at the place index
	 * @param obj
	 * @param index
	 */
	public synchronized void insertElement(Object obj, int index){
		if(size >= Integer.MAX_VALUE){
			throw new ArrayIndexOutOfBoundsException("seqlist size error. size : " + size);
		}
		
		
		if(index < 0 || index > size){
			throw new ArrayIndexOutOfBoundsException("param index error. index : " + index);
		}
		
		size ++;
		checkGrow();
		
		
		for(int i = size; i > index; i--){ //move the data behind the index
			array[i] = array[i-1];
		}
		array[index] = obj;  //set the data
		
	}
	
	/**
	 * delete the data in the index
	 * @param index
	 * @return
	 */
	public synchronized Object delete(int index){
		if(index < 0 || index > size){
			throw new ArrayIndexOutOfBoundsException("param index error.");
		}

		Object temp = array[index];
		
		size --;
		checkReduce();
		
		for(int i = index; i < size; i++){
			array[i] = array[i+1];
		}
		
		return temp;
	}
	
	/**
	 * get data in index
	 * @param index
	 * @return
	 */
	public Object getElement(int index){
		if(index < 0 || index > size){
			throw new ArrayIndexOutOfBoundsException("param index error.");
		}
		
		return array[index];
	}
	
	/**
	 * print the list
	 */
	public void printSeqList(){
		for(int i = 0; i < size; i++){
			System.out.print(array[i] + " ->");
		}
		System.out.println();
	}
	
	/**
	 * check whether the capacity need to grow 
	 */
	private void checkGrow(){
		if(capacity >= Integer.MAX_VALUE){ //capacity is max, cannot grow
			return;
		}
		
		if(size >= capacity/2){
			capacity += capacity/2 ;
			array = Arrays.copyOf(array, capacity);
		}
	}
	
	/**
	 * check whether the array need to reduce
	 */
	private void checkReduce(){
		if(size < capacity/4){
			capacity = capacity/2;
			array = Arrays.copyOf(array, capacity);
		}
	}
	
}
