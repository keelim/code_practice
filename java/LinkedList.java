public class LinkedList<T> implements List<T> { //노드를 이용하여 LinkedList를 구현을 하는 것
    private Node<T> head;
    private Node<T> tail;
    private int size = 0;

    private class Node<E> {
        private E data;
        private Node<E> next;

        public Node(E input) {
            this.data = input;
            this.next = null;
        }

        public String toStirng() {
            return String.valueOf(this.data);
        }
    }

    public String toString() {
        if (head == null) {
            return "[]";

        }
        Node<T> temp = head;
        StringBuilder str = new StringBuilder("[");

        while (temp.next != null) {
            str.append(temp.data + ",");
            temp = temp.next;

        }
        str.append(temp.data);
        return new String(str + "]");
    }

    @Override
    public boolean add(int index, T element) {
        // TODO: 2019-04-03
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException();
        }


        if (index == 0) {
            addFirst(element);

        } else {
            Node<T> temp1 = node(index - 1);
            Node<T> temp2 = temp1.next;
            Node<T> newNode = new Node<>(element);
            temp1.next = newNode;
            newNode.next = temp2;
            size++;

            if (newNode.next == null) {
                tail = newNode;

            }


        }
        return true;
    }

    @Override
    public boolean addFirst(T element) {
        // TODO: 2019-04-03
        Node<T> newNode = new Node<>(element);
        newNode.next = head;
        head = newNode;
        size++;

        if (head.next == null) {
            tail = head;
        }

        return true;
    }

    @Override
    public boolean addLast(T element) {
        if (isEmpty()) {
            addFirst(element);
        } else {
            Node<T> newNode = new Node<T>(element);
            tail.next = newNode;
            tail = newNode;
            size++;

        }

        return true;
    }

    private Node<T> node(int index) {
        Node<T> x = head;
        for (int i = 0; i < index; i++)
            x = x.next;
        return x;
    }

    @Override
    public T remove(int index) {
        // TODO: 2019-04-03
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException();
        }

        if (index == 0) {
            return removeFirst();
        }
        Node<T> temp = node(index - 1);
        Node<T> nodeToDelete = temp.next;
        temp.next = temp.next.next;
        T returnData = nodeToDelete.data;

        if (nodeToDelete == tail){
            tail = temp;
            
        }

        nodeToDelete = null;
        size--;

        return returnData;
    }

    @Override
    public T removeFirst() {
        // TODO: 2019-04-03
        Node<T> temp = head;
        head = temp.next;
        T returnData = temp.data;
        temp = null;
        size--;
        return returnData;
        
    }

    @Override
    public T removeLast() {
        // TODO: 2019-04-03
        return remove(size - 1);
    }

    @Override
    public T get(int index) {
        // TODO: 2019-04-03
        if (index < 0 || index >= size){
            throw new IndexOutOfBoundsException();
        }

        return node(index).data;
    }

    @Override
    public int indexOf(Object o) {
        int index = 0;
        if (o == null) {
            for (Node<T> x = head; x != null; x = x.next) {

                if (x.data == null){
                    return index;
                }
                index++;

            }
        } else {
            for (Node<T> x = head; x != null; x = x.next) {
                if (o.equals(x.data)){
                    return index;
                }
                index++;
            }
        }
        return -1;
    }

    @Override
    public int size() {
        // TODO: 2019-04-03
        return size;
        
    }

    @Override
    public boolean isEmpty() {
        // TODO: 2019-04-03
        return size == 0;

    }

    @Override
    public T set(int index, T element) {
        Node<T> set_temp = node(index);
        T oldvalue = set_temp.data;
        set_temp.data = element;
        return oldvalue;

    }

}
