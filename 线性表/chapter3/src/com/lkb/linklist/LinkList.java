package com.lkb.linklist;

public class LinkList {
	
	private Node head;
	private int size; //the size of the linklist
	private Node next;
	
	public LinkList() {
		// TODO Auto-generated constructor stub
		this.head = new Node(null,null);
		this.next = head;
		this.size = 0;
	}
	
	public void insertElement(Object data,int index){
		if(size == 0){
			Node newNode = new Node(null, data);
			head.next = newNode;
			next.next = newNode.next;
			return;
		}
		if(index < 0 || index > size){
			throw new ArrayIndexOutOfBoundsException("param index error");
		}
		
		
		
	}
	
	private class Node{
		public Node next;
		public Object data;
		private int index;
		
		public Node(Node next,Object data){
			this.next = next;
			this.data = data;
			this.index = 0;
		}
	}
}
