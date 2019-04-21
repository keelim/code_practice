package practice_code;

public class Node<E> {
    private E anElement;
    private Node _next;

    public E getAnElement() {
        return anElement;
    }

    public void setAnElement(E anElement) {
        this.anElement = anElement;
    }

    public Node get_next() {
        return _next;
    }

    public void set_next(Node _next) {
        this._next = _next;
    }
}
