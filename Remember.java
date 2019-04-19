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
        this.makeRoomAt(anOrder);//공간을 만든다.
        this._elements[anOrder] = anElement;
        this._size++;
        return true;
    }
}

private void makeRoomAt(int aPosition){     
    for(int i = this.size();i>aPosition ;i--){   //줄여나가면서 채운다. 
        this._elements[i] = this._elements[i-1];//원소들을 뒤로 넘어갔다.
    }
}

public E removeFrom(int anOrder){
    E removed = null; //임시 엘리먼트
    if(!isEmpty()){  //비어있는지 확인
        removed = this._elements[anOrder]; //일단 참조
        this.removeGapAt(anOrder); //뒤에있는 것을 땡겨 온다.
        this._size--;
    }
    return removed;
}

private void removeGapAt(int aPosition){ 
    for(int i = aPosition +1; i<this.size(); i++)   {
        this._elements[i-1] = this._elements[i];
    }
}

//LinkedList
Node _element, next
LinekdList size, head

public boolean addTo(Element anElement, int anOrder){
    if(anOrder < 0 || (anOrder > this.size())){//차수 확인
        return false;
    } else if(isFull()){ //꽉차 있는지 확인
        return false;
    } else {
        Node<E> nodeForAdd = newNode<>(anElement, null);
        if(anOrder == 0){ //LinkedList 는 0이 Boundary condition
            nodeForAdd.setNext() = this.head();
            this.setHead(nodeForAdd);
        } else {
            Node<E> prev = this.head();
            for(int i=1; i<anOrder; i++){
                prev = prev.next();
            }
            nodeForAdd.setNext(prev.next());
        }
        prev.setNext(nodeForAdd);
        this.setSize(this.size()+1);

        return true;
    }
}

public E removedFrom(int anOrder){
    if(anOrder <0 || anOrder>this.size()){ //차수 확인
     return null;
    } else if(isEmpty()){ //비어 있는지 확인
        return null;
    } else{
        Node temp = null;
        if(anOrder == 0){ //Boundary Condition
            temp = this.head();
            this.setHead(temp.next());
        } else {
            Node prev = this.head();

            for (int i = 1; i < anOrder; i++) { //이전까지 전부 접근
                prev = prev.next();
            }
            temp = prev.next();
            prev.setNext(temp.next());
        }
        this.setSize(this.size()-1);
        return temp;
    }
}

//LinkedList Iterator
public ListIterator iterator(){ 
    return new ListIterator();
}

private ListIterator<E> implements iterator{ //iterator를 implements 를 한다. 
    private Node<E> nextNode;

    public ListIterator() {
        nextNode = LinkedList.head();
    }

    public boolean hasNext(){
        return (this._nextNode != null);
    }

    public E next(){ 
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
        return (this._element[_nextPosition] < ArrayList.size()); //내부 클래스 접근이기 떄문
    }

    public E next(){
        if(this._nextPosition == ArrayList.size()){
            return null;
        } else{
            E nextElement = ArrayList._element[_nextPosition];
            this _nextPosition++;
            return nextElement;
        }
    }
}

//max //factorial //recursive max()

void quickSort(int[] a, int left, int right){
    if(left <right){
        int mid = partition(a, left, right);
        quickSort(a, left, mid-1);
        quickSort(a, mid+1, right);
    }
}

int partion(int[] a, int right, int left){
    int pivot = a[left] //아무거나 생성
    int toRight = left;
    int toLeft = right+1; //--를 바로 진행하기 때문에
    do {
        do{toRight++} while(a[toRight]<pivot);
        do{toLeft--} while(a[toLeft]>pivot);
        if(toRight<toLeft){
            swap(int, a[toRight], a[toLeft]);
        }
    } while (toRight<toLeft);// 서로 교차하면
    swap(int, a[left], pivot)
    return toLeft;
}

public int fact(int n){ //초항을 만드는 것이 중요하다. 
    if(n==1){
        return 1;
    } else {
        return n*fact(n-1);
    }
}

public int findMax(int[] a, int left, int right){
    int maxOfPart;
    if(left == right){ //초항
        return a[left];
    } else {
        maxOfPart = findMax(a, left+1, right);
        if(a[left] > = maxOfPart){
            return a[left];
        } else {
            return maxOfPart;
        }
    } 
}

public int findMax(int[] a, int left, int right){ //재귀적이지 않는 최대값찾기
    int culLoc, max;
    max = a[left];
    curLoc = left+1;
    while(culLoc<=right){
        if(max<A[curLoc]){
            max = A[curLoc];
        }
        curLoc++;
    }
    return max;
}

public int findmax2(int[] A, int left, int right){
    int maxOfleft;
    int maxOfright;
    if(left == right){ //초항을 만든 것이 중요
        return a[left];
    } else{
        int mid = (right+left)/2;
        maxOfleft = findmax2(A, left, mid);
        maxOfright = findmax2(A, mid+1, right);
        if(maxOfleft >maxOfright){
            return maxOfleft;
        } else {
            return maxOfright;
        }
    }

public void printlnReverse(char[] s, int from){ //문자열 역순 인쇄
    if(from <s.length){
        printlnRevere(s, from+1);
        System.out.println(s[from]);
    }
}