package practice_code;

public class Node<E> {
    private E _element;
    private Node<E> _next;

    public E element() {
        return _element;
    }

    public void setElement(E _element) {
        this._element = _element;
    }

    public Node<E> next() {
        return _next;
    }

    public void setNext(Node<E> _next) {
        this._next = _next;
    }

}
