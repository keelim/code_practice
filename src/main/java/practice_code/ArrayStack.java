package practice_code;

public class ArrayStack<E> {

    private static final int DEFAULT_CAPACITY = 0;
    private int _capacity;
    private int _top;
    private E[] _elements;

    @SuppressWarnings("unchecked")
    public ArrayStack() {
        this._elements = (E[]) new Object[ArrayStack.DEFAULT_CAPACITY];
        this._capacity = ArrayStack.DEFAULT_CAPACITY;
        this._top = -1;
    }

    @SuppressWarnings("unchecked")
    public ArrayStack(int givenCapapcity) {
        this._elements = (E[]) new Object[givenCapapcity];
        this._capacity = givenCapapcity;
        this._top = -1;
    }

    public int get_capacity() {
        return _capacity;
    }

    public void set_capacity(int _capacity) {
        this._capacity = _capacity;
    }

    public int get_top() {
        return _top;
    }

    public void set_top(int _top) {
        this._top = _top;
    }

    public E[] get_elements() {
        return _elements;
    }

    public void set_elements(E[] _elements) {
        this._elements = _elements;
    }

    public boolean isEmpty() {
        return (this._top < 0);
    }

    public boolean isFull() {
        return ((this._top + 1) == this._capacity);
    }

    public boolean push(E anElement, int anOrder) {
        if (this.isFull()) {
            return false;
        } else {
            this._top++;
            this._elements[this._top] = anElement;
            return true;
        }
    }

    public E peek(int anOrder) {
        E peek = null;
        if (!this.isEmpty()) {
            peek = this._elements[anOrder];
        }
        return peek;
    }

    public E pop() {
        E pop = null;
        if (!isEmpty()) {
            pop = this._elements[this._top];
            this._elements[this._top] = null;
            this._top--;
        }
        return pop;
    }

    public void clear() {
        while (this._top >= 0) {
            this._elements[this._top] = null;
            this._top--;
        }
    }

    @SuppressWarnings("unchecked")
    public void resize() {
        this._capacity *= 2;
        E[] oldElements = this._elements;
        this._elements = (E[]) new Object[this._capacity];

        for (int i = 0; i <= _top; i++) {
            this._elements[i] = oldElements[i];
            oldElements[i] = null;
        }

    }
}
