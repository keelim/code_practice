//ArrayStack
public boolean push(Element anElement){
    if(this.isFull()){//가득 차 있는지를 확인
        return false;
    } else{
        this._top++; //top을 증가 시킨다. 
        this._elements[top] = anElement;
        return true;
    }
}

public Element pop(){
    Element pop = null;

    if(!this.isEmpty()){
         pop = this._elements[top]; //top 에 있는 것을 꺼낸다.
        this._elements[top] = null; //top을 null 로 만든다. 
        this._top--; //top의 크기를 줄인다. 
    }
    return pop;
}

public Element peek(){
    Element peek = null; //리턴할 엘리먼트 생성
    if(!isEmpty()){
        peek = this._elements[top]; //top에 있는 것을 참조한다. 
    }
    return peek;
}

private void resize(){
    this._capacity*=2;
    Element[] oldElements = this._elements; //old 가 배열을 가진다. 
    this._elements = new Element[this._capacity]; //새로운 배열 할당

    for (int i = 0; i < this._top; i++) { //반복을 통하여 값을 할당을 하고
        this._elements[i] = oldElements[i];
        oldElements[i] = null; //오래된 것은 버린다. 
    }
}

ArrayList _size, _capacity, _elements

public boolean addTo(Element anElement, int anOrder){
    if(isFull()){
        return false;
    } else{
        this.makeRoomAt(anOrder);
        this._elements[anOrder] = anElement;
        this._size++;

        return true;
    }
}

private void  makeRoomAt(int aPosition){     
    for(int i = this.size();i>aPosition ;i--){ //줄여나가면서 채운다. 
        this._elements[i] = this._elements[i-1];
    }

}

public Element removeFrom(int anOrder){
    Element removed = null;
    if(!isEmpty()){
        removed = this._elements[anOrder];
        this.removeGapAt(anOrder);
        this._size--;
    }
    return removed;
}

private void removeGapAt(int aPosition){ //todo
    for(int i = aPosition +1; i<this.size(); i++)   {
        this._elements[i-1] = this._elements[i];
    }
}

//LinkedList
Node _element, next
LinekdList size, head
public boolean addTo(Element anElement, int anOrder){
    if(anOrder < 0 || (anOrder > this.size())){
        return false;
    } else if(isFull()){
        return false;
    } else {
        Node<E> nodeForAdd = newNode<>(Element, null);
        if(anOrder == 0){
            nodeForAdd.setNext() = this.head();
            this.setHead(nodeForAdd);
        } else {
            Node<E> prev = this.head();
            for(int i=1; i<anOrder; i++){
                prev = prev.next();
            }
            nodeForAdd.setNext(prev.next());
        }
        prev.setNext(nodeForAdd);this._size++;
            return true;
    }
}

public Element removedFrom(int anOrder){
    if(anOrder <0 || anOrder>this.size()){
     return null;
    } else if(isEmpty()){
        return null;
    } else{
        Node temp = null;
        if(anOrder == 0){
            temp = this.head();
            this.setHead(temp.next());
        } else {
            Node prev = this.head();
            for (int i = 1; i < anOrder; i++) {
                prev = prev.next();
            }
            temp = prev.next();
            prev.setNext(temp.next());
        }
        this.setSize(this.size()-1);
        return temp;
    }
}

//ArrayIterator
public ListIterator iterator(){
    return new ListIterator();
}

private ListIterator<E> implements iterator{
    private Node<E> nextNode;

    public ListIterator() {
        nextNode = LinkedList.head();
    }

    public boolean hasNext(){
        return (this._nextNode != null);
    }

    public Element next(){ //수정 필요
        if(this._nextNode == null){
            return null;
        } else {
            E temp = this._nextNode._element;
            this.nextNode = this.nextNode.next();
            return temp;
        }

    }
}

public ListIterator iterator(){
    return new ListIterator();
}

private class ListIterator<E> implements iterator{
    private _nextPosition;

    private ListIterator(){
        _nextPosition = 0;
    }

    public boolean hasNext(){
        return (this._element[_nextPosition] < ArrayList.size()); //내부 클래스 접근이기 떄문ㅔ
    }

    public E next(){
        if(this._nextPosition == ArrayList.size()){
            return null;
        } else{
            T nextElement = ArrayList._element[_nextPosition];
            this _nextPosition++;
            
            return nextElement;
        }
    }
}