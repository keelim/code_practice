package practice_code;

public class ArrayStack<E> extends ArrayList {
    private static final int DEFAULT_CAPACITY = 100;
    private int top;
    private int capacity;
    private E[] _elements;

    public ArrayStack(int capacity) {
        this._elements = (E[]) new Object[capacity];
        this.capacity = capacity;
        this.top = 0;
    }

    public ArrayStack() {
        this._elements = (E[]) new Object[ArrayStack.DEFAULT_CAPACITY];
        this.capacity = ArrayStack.DEFAULT_CAPACITY;
        this.top = 0;
    }

    public boolean push(E anElement) {
        if (isFull()) {
            return false;
        } else {
            top++;
            this._elements[top] = anElement;
            return true;
        }
    }

    public E peek() {
        E peek = null;
        if (!isEmpty()) {
            peek = this.get_elements()[top];
        }
        return peek;
    }

    public E pop() {
        E pop = null;
        if (!isEmpty()) {
            pop = this.get_elements()[top];
            this.get_elements()[top] = null;
            this.top--;
        }

        return pop;
    }

    @Override
    public void clear() {
        int i = 0;
        while (this.top >= 0) {
            this.get_elements()[top] = null;
            top--;
        }
    }

    private void resize() {
        E[] oldElements = this.get_elements();
        this.capacity *= 2;
        this._elements = (E[]) new Object[this.capacity];

        for (int i = 0; i <= this.top; i++) {
            this._elements[i] = oldElements[i];
            oldElements[i] = null;
        }
    }

    @Override
    public E[] get_elements() {
        return _elements;
    }
}
