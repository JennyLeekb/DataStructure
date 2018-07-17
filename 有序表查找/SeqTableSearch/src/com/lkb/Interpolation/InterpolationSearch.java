package com.lkb.Interpolation;

/**
 * 插值查找
 * @author LKB
 *
 */
public class InterpolationSearch {
	
	public static void main(String[] args) {
		int[] src = {0,1,16,24,35,47,59,62,73,88,99};
		int key = 47;
		System.out.println(interpolationSearch(key, src));
	}
	
	/**
	 * 插值查找
	 * @param key
	 * @param src
	 * @return
	 */
	public static int interpolationSearch(int key, int[] src){
		int length = src.length;
		int low = 0; //low high 的初始值分别为数组索引 的最小、最大值
		int high = length -1;
		int middle = 0;
		
		while(low <= high){
			middle = low + (high - low)*(key - src[low])/(src[high] - src[low]);
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
