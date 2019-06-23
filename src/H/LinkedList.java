package H;

public class LinkedList {




    static SinglyLinkedListNode reverse(SinglyLinkedListNode head) {
        SinglyLinkedListNode node = new SinglyLinkedListNode();
        if(head != null){
            reverse(head.next);

        }

    }
}

