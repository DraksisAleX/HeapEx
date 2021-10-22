
template <class T>
class BinaryHeap : public PriorityQueue<T>{

    T** queue;
    int heapsize;

    public:

    virtual double compare(T* a, T*b) = 0;
    virtual void printKey(int i) const = 0;

    T** getPriorityQueue() const {return queue;}

    int size() const {return heapsize;}

    BinaryHeap(int size)
    {
        queue = new T * [size + 1];
        heapsize = 0;
        queueLength = size + 1; 
    }

    BinaryHeap(T** V, int size)
    {
        queue = V;
        queueLength = size;
        heapsize = size - 1;
    }

    int left(int i) return i << 1;

    int right(int i) return i << 1 | 1;

    int parent(int i) return i >> 1;

    void swap(int i, int j)
    {
        T* tmp = queue[i];
        queue[i] = queue[j];
        queue[j] = tmp;
    }

    void heapify(int index)
    {
        int i = index;    
        while (i <= heapsize/2)
        {
            int tmp = i;
            int l = left(i);
            int r = right(i);
            if (l <= heapsize && compare(queue[tmp], queue[l]) < 0) tmp = l;
            if (r <= heapsize && compare(queue[tmp], queue[r]) < 0) tmp = r;
            if (tmp == i) return;
            swap(i, tmp);
            i = tmp;
        }
    }

    void print() const
    {
        for(int i = 1; i <= this->size(); i++) printKey(i);
        cout << endl;
    }

    void buildHeap()
    {
        for(int i = heapsize/2; i > 0; i--) heapify(i);
    }

    T* extract()
    {
        if(heapsize == NULL) return NULL;
        swap(1,heapsize);
        heapsize--;
        heapify(1);
        return queue[heapsize + 1];
    }

    void modify(int i, T k)
    {
        if(i > heapsize || i < 1 || compare(queue[i], &k) >= 0) return;
        delete queue[i];
        queue[i] = new T(k);
        while (i > 1 && compare(queue[i],queue[parent(i)]) > 0)
        {
            swap(i, parent(i));
            i = parent(i);
        }
    }

    BinaryHeap<T> enqueue(T x)
    {
        if(heapsize == queueLength-1) return this;
        heapsize++;
        queue[heapsize] = new T(x);
        int i = heapsize;
        while (i > 1 && compare(queue[i],queue[parent(i)]) > 0)
        {
            swap(i, parent(i));
            i = parent(i);
        }
    }

}