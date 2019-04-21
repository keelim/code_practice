package practice_code;

public class LinkedBag<E> {
    private int _size;
    private Node<E> head;

    public int get_size() {
        return _size;
    }

    public void set_size(int _size) {
        this._size = _size;
    }

    public Node<E> getHead() {
        return head;
    }

    public void setHead(Node<E> head) {
        this.head = head;
    }

    public LinkedBag() {
        this._size = 0;
        this.head = null;
    }

    public boolean isEmpty() {
        return (this._size == 0);
    }

    public boolean isFull() {
        return false;
    }

    public boolean doesContain(E anElement) {
        Node<E> current = this.getHead();

        while (current != null) {
            if (current.getAnElement().equals(anElement)) {
                return true;
            }
            current = current.get_next();
        }
        return false;
    }

    public int frequencyOf(E anElement) {
        int frequency = 0;
        Node<E> current = this.getHead();
        while (current != null) {
            if (current.getAnElement().equals(anElement)) {
                frequency++;
            }
            current = current.get_next();
        }

        return frequency;

    }

    public E elementAt(int anOrder) {

        if (anOrder < 0 || anOrder > this.get_size()) {
            return null;
        } else {
            Node<E> current = this.getHead();
            for (int i = 0; i < anOrder; i++) {
                current = current.get_next();
            }

            return current.getAnElement();

        }
    }

    public boolean add(E anElement) {
        if (this.isFull()) {
            return false;
        } else {
            Node<E> nodeForAdd = new Node<>();
            nodeForAdd.setAnElement(anElement);
            nodeForAdd.set_next(this.getHead());
            this.setHead(nodeForAdd);
            this.set_size(this.get_size() + 1);
            return false;
        }
    }

    public E removeAny() {
        if (this.isEmpty()) {
            return null;
        } else {
            Node<E> remove = this.getHead();
            this.setHead(remove.get_next());
            this.set_size(this.get_size() - 1);
            return remove.getAnElement();

        }
    }

    public boolean remove(E anElement) {
        if (this.isEmpty()) {
            return false;
        } else {
            Node<E> prev = null;
            Node<E> current = this.getHead();
            boolean found = false;

            if (!found && current != null) {
                if (current.getAnElement().equals(anElement)) {
                    found = true;
                }

                prev = current;
                current = current.get_next();
            }

            if (!found) {
                return false;
            } else {
                if (current == this.getHead()) {
                    this.setHead(this.getHead().get_next());
                } else {
                    prev.set_next(current.get_next());

                }
                this.set_size(this.get_size() - 1);
                return true;
            }

        }

    }

    public ListIterator iterator() {
        return new ListIterator();
    }

    public class ListIterator implements iterator {
        Node<E> _nextPosition = null;

        private ListIterator() {
            this._nextPosition = head;
        }

        @Override
        public boolean hasNext() {
            return (this._nextPosition == null);
        }

        @Override
        public E next() {
            if (this._nextPosition == null) {
                return null;
            } else {
                E temp = _nextPosition.getAnElement();
                _nextPosition = _nextPosition.get_next();
                return temp;
            }

        }
    }
}
