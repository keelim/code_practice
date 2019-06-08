package L;


class MyCircularQueue {
    private Integer elements[];
    private int maxLength;
    private int frontPosition;
    private int rearPosition;

    /**
     * Initialize your data structure here. Set the size of the queue to be k.
     */
    public MyCircularQueue(int givenCapacity) {
        this.elements = new Integer[givenCapacity];
        this.maxLength = givenCapacity + 1;
        this.frontPosition = -1;
        this.rearPosition = -1;
    }

    /**
     * Insert an element into the circular queue. Return true if the operation is successful.
     */
    public boolean enQueue(int value) {
        if (this.isFull()) {
            return false;
        } else {
            this.frontPosition = (this.frontPosition + 1) % maxLength;
            this.elements[this.frontPosition] = value;
            return true;
        }
    }

    /**
     * Delete an element from the circular queue. Return true if the operation is successful.
     */
    public boolean deQueue() {
        if (!this.isEmpty()) {
            this.rearPosition = (this.rearPosition + 1) % maxLength;
            int element = this.elements[rearPosition];
            this.elements[this.rearPosition] = null;
            return true;
        }
        return false;
    }

    /**
     * Get the front item from the queue.
     */
    public int Front() {
        if (this.isEmpty()) {
            return -1;
        } else {
            return this.elements[frontPosition];
        }
    }

    /**
     * Get the last item from the queue.
     */
    public int Rear() {
        if (this.isEmpty()) {
            return -1;
        } else {
            return this.elements[this.rearPosition];
        }
    }

    /**
     * Checks whether the circular queue is empty or not.
     */
    public boolean isEmpty() {
        return this.frontPosition == this.rearPosition;
    }

    /**
     * Checks whether the circular queue is full or not.
     */
    public boolean isFull() {
        int nextRear = (this.rearPosition + 1) % maxLength;
        return (nextRear == this.frontPosition);
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */