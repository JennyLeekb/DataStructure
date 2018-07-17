package com.lkb.Fibonacci;

import java.util.Arrays;

import com.lkb.util.HelpUtils;

/**
 * 斐波那契查找
 * @author LKB
 *
 */
public class FibonacciSearch {

	
	public static void main(String[] args) {
		
		int[] src = {0,1,16,24,35,47,59,62,73,88,99};
		int key = 47;
		System.out.println(fobSearch(key, src));
		
	}
	
	/**
	 * 根据下标索引获取斐波那契数列中的元素
	 * 斐波那契数列 F {0,1,1,2,3,5,8,13,21,...}
	 * @param index 需要查找的元素下标
	 * @return
	 */
	public static int getFobonacci(int index){
		int[] fob = {0,1};	//斐波那契数列数组
		int oldCapacity = 2; //数组容量
		
		if(index==0){ //
			return fob[0]; 
		}
		if(index==1){
			return fob[1];
		}
		
		int i = 1; 
		while(i < index){
			i ++;
			
			if(i>oldCapacity-1){//检查数组容量
				int newCapacity = oldCapacity + oldCapacity/2;
				fob = Arrays.copyOf(fob, newCapacity); //增加数组容量
				oldCapacity = newCapacity;
			}
			
			fob[i] = fob[i-1]+fob[i-2]; 
		}		
		return fob[i];		
	}
	
	/**
	 * 从有序表中查找数据
	 * @param key 需要查找的数据
	 * @param src 有序表
	 * @return
	 */
	public static int fobSearch(int key,int[] src){
		int length = src.length;
		int low = 0; //low high 的初始值分别等于有序表索引的最小值和最大值
		int high = length-1; 		
		int fobInex = 0; // 我们后面需要用到的  斐波那契数组中的索引值
		int middle = 0 ; //二分法的分隔值
		
		//使用斐波那契查找的要求 就是有序表的元素个数必须是斐波那契数组元素的值
		while(length > getFobonacci(fobInex)){ 
			fobInex ++;
		}
		
		//如果有序表的元素个数不等于斐波那契数组元素的值，则需要在后面补全
		int newCapacity = getFobonacci(fobInex);//新数组的大小
		if(length < newCapacity){
			src = Arrays.copyOf(src, newCapacity);
			for(int i=length;i<newCapacity;i++){//将后续的数值补全
				src[i] = src[i-1];
			}
		}
		
		HelpUtils.printIntArray(src);//打印一下补全的数组
		
		while(low <= high){
			middle = low + getFobonacci(fobInex-1)-1;
			if (key < src[middle]) { //如果当前查找记录小于当前分隔记录
				high = middle - 1;
				fobInex = fobInex - 1;
			}
			else if (key > src[middle]) {
				low = middle + 1;
				fobInex = fobInex - 2;
			}
			else{
				if (middle < length) {
					return middle; 
				}
				else{
					return -1;
				}
			}			
		}

		return -1;
	}

}
