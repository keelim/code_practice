package practice_code;

public class Arraylist<E> {
    private static final int DEFAULT_CAPACITY = 100;

    private int _capacity;
    private int _size;
    private E[] _elements;

    @SuppressWarnings("unchecked")
    public Arraylist(int givenCapacity) {
        this._elements = (E[]) new Object[givenCapacity];
        this._capacity = givenCapacity;
        this._size = 0;
    }

    public Arraylist() {
        this(Arraylist.DEFAULT_CAPACITY);
    }

    public int get_capacity() {
        return _capacity;
    }

    public void set_capacity(int _capacity) {
        this._capacity = _capacity;
    }

    public int get_size() {
        return _size;
    }

    public void set_size(int _size) {
        this._size = _size;
    }

    public E[] get_elements() {
        return _elements;
    }

    public void set_elements(E[] _elements) {
        this._elements = _elements;
    }

    public boolean isEmpty() {
        return (this._size == 0);
    }

    public boolean isFull() {
        return (this._size == this._capacity);
    }

    public E elementAt(int anOrder) {
        int position = anOrder;
        if (anOrder >= 0 && anOrder < this._size) {
            return this._elements[anOrder];
        } else {
            return null;
        }

    }

    public E last() {
        if (!isEmpty()) {
            return this._elements[this._size - 1];
        }
        return null;
    }

    public boolean addTo(E anElement, int anOrder) {
        if (this.isFull()) {
            return false;
        } else if (!((anOrder >= 0 && anOrder <= this._size))) {
            return false;
        } else {
            this.makeRoomAt(anOrder);
            this._elements[anOrder] = anElement;
            this._size++;
            return true;
        }
    }

    private void makeRoomAt(int aPosition) {
        for (int i = this._size; i > aPosition; i--) {
            this._elements[i] = this._elements[i - 1];
        }
    }


}
