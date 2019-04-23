package practice_code;

public class Set<E> {
    int _size = 0;
    E[] _elements;

    public boolean doesContain(E anElement) {
        boolean found = false;
        int i;
        for (i = 0; i < this._size && !found; i++) {
            if (this._elements[i].equals(anElement)) {
                found = true;
            }
        }
        return found;

    }
}
