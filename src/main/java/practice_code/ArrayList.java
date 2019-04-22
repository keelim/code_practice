package practice_code;

public class ArrayList<E> {
    private static final int DEFAULT_CAPACITY = 100;
    E[] _elements;
    int capacity;
    int size;

    public ArrayList() {
        this(ArrayList.DEFAULT_CAPACITY);
    }

    @SuppressWarnings("unchecked")
    public ArrayList(int givenCapacity) {
        this.capacity = givenCapacity;
        this._elements = (E[]) new Object[givenCapacity];
        this.size = 0;
    }

    public boolean isEmpty() {
        return (this.size == 0);
    }

    public boolean isFull() {
        return (this.size == this.capacity);
    }

    public E[] elements() {
        return _elements;
    }

    public void setElements(E[] _elements) {
        this._elements = _elements;
    }

    public int getCapacity() {
        return capacity;
    }

    public void setCapacity(int capacity) {
        this.capacity = capacity;
    }

    public int size() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    private boolean anElementDoesExistAt(int anOrder) {
        return ((anOrder >= 0) && (anOrder < this.size));
    }

    public E elementAt(int anOrder) {
        int position = anOrder;
        if (this.anElementDoesExistAt(anOrder)) {
            return this._elements[position];
        } else {
            return null;
        }
    }

    public E last() {
        if (this.isEmpty()) {
            return null;
        } else {
            return this._elements[this.size - 1];
        }
    }

    public int orderOf(E anElement) {
        for (int order = 0; order < this.size; order++) {
            if (this._elements[order].equals(anElement)) {
                return order;
            }
        }
        return -1;
    }

    public boolean doesContain(E anElement) {
        for (int order = 0; order < this.size; order++) {
            if (this.elements()[order].equals(anElement)) {
                return true;
            }
        }
        return false;
    }

    public boolean addTo(E anElement, int anOrder) {
        if (this.isFull()) {
            return false;
        } else {
            if (anOrder >= 0 && anOrder <= this.size) {
                this.makeRoomAt(anOrder);
                this.elements()[anOrder] = anElement;
                this.size++;
                return true;
            } else {
                return false;
            }
        }
    }

    private void makeRoomAt(int aPosition) {
        for (int i = this.size; i > aPosition; i--) {
            this.elements()[i] = this.elements()[i - 1];

        }
    }

    public E removeFrom(int anOrder) {
        E remove = null;
        if (this.anElementDoesExistAt(anOrder)) {
            remove = this.elementAt(anOrder);
            this.removeGapAt(anOrder);
            this.size--;
        }
        return remove;

    }

    private void removeGapAt(int aPosition) {
        for (int i = aPosition + 1; i < this.size; i++) {
            this.elements()[i] = this.elements()[i - 1];
        }
        this.elements()[this.size - 1] = null;

    }

    public ListIterator iterator() {
        return new ListIterator();
    }

    public class ListIterator implements iterator<E> {
        private int _nexPosition;

        private ListIterator() {
            _nexPosition = 0;
        }


        @Override
        public boolean hasNext() {
            return _nexPosition < ArrayList.this.size;
        }

        @Override
        public E next() {
            if (_nexPosition == ArrayList.this.size) {
                return null;
            } else {
                E next = ArrayList.this.elements()[this._nexPosition];
                this._nexPosition++;
                return next;
            }
        }
    }


}
