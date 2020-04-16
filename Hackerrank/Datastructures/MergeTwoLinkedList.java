import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class SinglyLinkedListNode {
    int data;
   SinglyLinkedListNode next;
}

public class MergeTwoLinkedList {
	public static void main(String[] args){
		boolean local=false;
		Scanner sc=new Scanner(System.in);
		if(local) {
			sc.close();
			try {
				if(args.length<1) throw new IllegalArgumentException();
				sc=new Scanner(new File(args[0]));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			} catch (IllegalArgumentException e){
				sc=new Scanner(System.in);
			}
		}
		
		sc.close();
	}
    
	static SinglyLinkedListNode mergeLists(SinglyLinkedListNode a, SinglyLinkedListNode b) {
		SinglyLinkedListNode head, itr;
		head=itr=null;
		while(true) {
			// 1 4 5
			// -1 0 3
			if(a==null || b==null) {
				if(a==null)
					itr.next=b;
				else
					itr.next=a;
				break;
			}
			if(a.data<b.data) {
				if(head==null)
					itr=head=a;
				else {
					itr.next=a;
					itr=itr.next;
				}
				
				a=a.next;
			}else {
				if(head==null)
					itr=head=b;
				else {
					itr.next=b;
					itr=itr.next;
				}
				b=b.next;
			}
			
		}
		
		return head;
    }
	
}
