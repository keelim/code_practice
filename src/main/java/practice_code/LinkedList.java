package practice_code;

public class LinkedList<E> {
    private int _size;
    private Node<E> _head;

    public int size() {
        return _size;
    }

    public void setSize(int _size) {
        this._size = _size;
    }

    public Node<E> head() {
        return _head;
    }

    public void setHead(Node<E> _head) {
        this._head = _head;
    }

    public boolean isEmpty() {
        return (this.head() == null);
    }

    public boolean isFull() {
        return false;
    }

    public E elementAt(int anOrder) {
        if (anOrder < 0 || anOrder >= this._size) {
            return null;
        } else {
            Node<E> curr = this.head();
            int nodeCount = 0;
            while (nodeCount < anOrder) {
                curr = curr.next();
                nodeCount++;
            }
            return curr.element();
        }
    }

    public E first() {
        if (isEmpty()) {
            return null;
        } else {
            return this.head().element();
        }

    }

    public E last() {
        if (isEmpty()) {
            return null;
        } else {
            return this.elementAt(size() - 1);
        }
    }

    public boolean doesContain(E anElement) {
        Node<E> current = this.head();

        while (current != null && !current.element().equals(anElement)) {
            current = current.next();
        }
        return (current != null);
    }

    public boolean addTo(E anElement, int anOrder) {
        if (anOrder < 0 || anOrder > this._size) {
            return false;
        } else {
            Node<E> nodeForAdd = new Node<>();
            nodeForAdd.setElement(anElement);

            if (anOrder == 0) {
                nodeForAdd.setNext(this.head());
                this.setHead(nodeForAdd);
            } else {
                Node<E> prev = this.head();
                for (int i = 1; i < anOrder; i++) {
                    prev = prev.next();
                }
                nodeForAdd.setNext(prev.next());
                prev.setNext(nodeForAdd);

            }

        }
        this._size++;
        return true;
    }

    public E removeFrom(int anOrder) {
        if (anOrder < 0 || anOrder >= this._size) {
            return null;
        } else {
            Node<E> remove = null;
            if (anOrder == 0) {
                remove = this._head;
                this.setHead(this._head.next());
            } else {
                Node<E> prev = this.head();

                for (int i = 0; i < anOrder; i++) {
                    prev = prev.next();
                }
                remove = prev.next();
                prev.setNext(remove.next());

            }
            this._size--;
            return remove.element();
        }


    }

    public ListIterator iterator() {
        return new ListIterator();
    }

    public class ListIterator implements iterator<E> {
        private Node<E> _nextnode;

        private ListIterator() {
            _nextnode = LinkedList.this.head();
        }

        @Override
        public boolean hasNext() {
            return this._nextnode != null;
        }

        @Override
        public E next() {
            if (this._nextnode == null) {
                return null;
            } else {
                E next = _nextnode.element();
                _nextnode = _nextnode.next();
                return next;
            }
        }
    }


}
