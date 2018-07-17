package com.lkb.util;

public class HelpUtils {

	/**
	 * 打印数组
	 * @param array
	 */
	public static void printIntArray(int[] array){
		for(int i=0; i < array.length; i++){
			System.out.print(array[i] + " -> ");
		}
		System.out.println();
	}
	
}
