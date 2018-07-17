package com.lkb.Binary;

/**
 * 二分查找
 * @author LKB
 *
 */
public class BinarySearch {
	
	public static void main(String[] args) {
		int[] src = {0,1,16,24,35,47,59,62,73,88,99};
		int key = 47;
		System.out.println(binarySearch(key, src));
	}
	
	/**
	 * 二分查找
	 * @param key
	 * @param src
	 * @return
	 */
	public static int binarySearch(int key, int[] src) {
		int length = src.length;
		int low = 0; //low high 初始值分别是数组索引的最小、最大值
		int high = length -1;
		int middle = 0;
		
		while(low <= high){
			middle = (low + high) / 2 ;
			
			if(key < src[middle]){
				high = middle - 1;
			}
			else if(key > src[middle]){
				low = middle + 1;
			}
			else{
				return middle;
			}
		}
		
		return -1;
	}
	
	
}
