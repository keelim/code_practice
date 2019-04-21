package practice_code;

import java.util.Objects;

public class ArrayList<E> {


    private static final int DEFAULT_CAPACITY = 100;
    private int _size;
    private int _capacity;
    private E[] _elements;

    public int get_size() {
        return _size;
    }

    public void set_size(int _size) {
        this._size = _size;
    }

    public int get_capacity() {
        return _capacity;
    }

    public void set_capacity(int _capacity) {
        this._capacity = _capacity;
    }

    public E[] get_elements() {
        return _elements;
    }

    public void set_elements(E[] _elements) {
        this._elements = _elements;
    }



    @SuppressWarnings("unchecked")
    public ArrayList() {
        _size = 0;
        _capacity = DEFAULT_CAPACITY;
        _elements = ((E[]) new Objects[this._capacity]);
    }

    @SuppressWarnings("uncheked")
    public ArrayList(int givenCapacity) {
        _size = 0;
        _capacity = givenCapacity;
        _elements = ((E[]) new Objects[this._capacity]);

    }

    public int frequencyOf(E anElement) {
        int frequencycount = 0;
        for (int i = 0; i < this.get_size(); i++) {
            if (this.get_elements()[i].equals(anElement)) {
                frequencycount++;
            }
        }
        return frequencycount;
    }

    public E any() {
        if (this.isEmpty()) {
            return null;
        } else {
            return this.get_elements()[0];
        }
    }

    public boolean isEmpty() {
        return (this.get_size() == 0);
    }


    public boolean isFull() {
        return (this.get_size() == this.get_capacity());
    }

    public boolean add(E anElement) {
        if (this.isFull()) {
            return false;
        } else {
            this.get_elements()[this.get_size()] = anElement;
            this.set_size(1 + this.get_size());
            return true;
        }
    }

    public E removeAny() {
        E remove = null;
        if (this.isEmpty()) {
            return remove;
        } else {
            remove = this.get_elements()[this.get_size() - 1];
            this.get_elements()[this.get_size() - 1] = null;
            this.set_size(this.get_size() - 1);
            return remove;
        }

    }

    public void clear() {
        for (int i = 0; i < this.get_size(); i++) {
            this.get_elements()[i] = null;
        }
        this.set_size(0);
    }

    public ListIterator iteartor() {
        return new ListIterator();
    }

    public class ListIterator implements iterator {
        private int _nextPosition;

        public ListIterator() {
            _nextPosition = 0;
        }

        @Override
        public boolean hasNext() {
            return (this._nextPosition <= ArrayList.this._size);
        }

        @Override
        public E next() {
            if (_nextPosition == ArrayList.this.get_size()) {
                return null;
            } else {
                E next = ArrayList.this.get_elements()[this._nextPosition];
                this._nextPosition++;
                return next;
            }

        }
    }

}





