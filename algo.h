

namespace algo {
    
    /**
    * Finds larger element from two.
    * T(n) = O(1).
    * S(n) = O(1).
    *
    * @tparam T must be totally ordered and it must have defined >,<,= operators.
    * @param a first element.
    * @param b second element.
    * @return larger element.
    */
    template <typename T>
    inline T Max(T a, T b) { return (a > b)? a: b; }    
   
    /**
    * Finds smaller element from two.
    * T(n) = O(1).
    * S(n) = O(1).
    *
    * @tparam T must be totally ordered and it must have defined >,<,= operators.
    * @param a first element.
    * @param b second element.
    * @return smaller element.
    */
    template <typename T>
    inline T Min(T a, T b) { return (a < b)? a: b; }
    
    /**
    * Return index of larger element from array.
    * T(n) = O(1).
    * S(n) = O(1).
    *
    * @tparam T must be totally ordered and it must have defined >,<,= operators.
    * @param arr Array of elements.
    * @param i index of first element.
    * @param j index of second element.
    * @return index of larger element.
    */
    template <typename T>
    inline int MaxIdx(T* arr, int i, int j) { return (arr[i] > arr[j])? i: j; }

    /**
    * Return index of smaller element from array.
    * T(n) = O(1).
    * S(n) = O(1).
    *
    * @tparam T must be totally ordered and it must have defined >,<,= operators.
    * @param arr Array of elements.
    * @param i index of first element.
    * @param j index of second element.
    * @return index of smaller element.
    */
    template <typename T>
    inline int MinIdx(T* arr, int i, int j) { return (arr[i] < arr[j])? i: j; }

    /**
    * Return the largest element from array.
    * T(n) = O(n).
    * S(n) = O(1).
    *
    * @tparam T must be totally ordered and it must have defined >,<,= operators.
    * @param arr array of elements.
    * @param len length of the first array.
    * @param min_idx optional, if set, index of the largest element will be assigned to it.
    * @return the largest element.
    */
    template <typename T>
    T ArrMax(T* arr, int len, int* max_idx = NULL) {
        T max = arr[0];
        if(max_idx) *max_idx = 0;
        for(int i=1; i<len; ++i) {
            if(arr[i]>max) {
                max = arr[i];
                if(max_idx) *max_idx = i;
            }
        }
        return max;
    }

    /**
    * Return the smallest element from array.
    * T(n) = O(n).
    * S(n) = O(1).
    *
    * @tparam T must be totally ordered and it must have defined >,<,= operators.
    * @param arr array of elements.
    * @param len length of the first array.
    * @param max_idx optional, if set, index of the smallest element will be assigned to it.
    * @return value of the smallest element.
    */
    template <typename T>
    T ArrMin(T* arr, int len, int* min_idx = NULL) {
        T min = arr[0];
        if(min_idx) *min_idx = 0;
        for(int i=1; i<len; ++i) {
            if(arr[i]<min) {
                min = arr[i];
                if(min_idx) *min_idx = i;
            }
        }
        return min;
    }
    
    /**
    * Swaps two elements in array.
    * T(n) = O(1).
    * S(n) = O(1).
    *
    * @tparam T must be totally ordered and it must have defined >,<,= operators.
    * @param arr array of elements.
    * @param i index of first element.
    * @param j index of second element.
    */
    template <typename T>
    void ArrSwap(T* arr, int i, int j) {
        T temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    // Operation on binary heap stored in array.
    namespace ArrHeap {
        
        /**
        * Adds one element to binary heap in array.
        * If the heap is on elements 0-n, it adds element with index n+1.
        * T(n) = O(log(n)).
        * S(n) = O(1).
        *
        * @tparam T must be totally ordered and it must have defined >,<,= operators.
        * @param arr array of elements.
        * @param heap_len length of the heap.
        * @param is_max Is the heap maximal?
        */
        template <typename T>
        void Insert(T* arr, int heap_len, bool is_max) {
            int last = heap_len;
	    int next = (last-1)/2;
	    while(is_max? (arr[next] < arr[last]): (arr[next] > arr[last])) {
		ArrSwap<T>(arr, next, last);
		last = next;
		next = (last-1)/2;
	    }
        }
        
        /**
        * Removes element from top of binary heap.
        * T(n) = O(log(n)).
        * S(n) = O(1).
        *
        * @tparam T must be totally ordered and it must have defined >,<,= operators.
        * @param arr array of elements.
        * @param heap_len length of the heap.
        * @param is_max Is the heap maximal?
        */
        template <typename T>
        void Remove(T* arr, int heap_len, bool is_max) {
            ArrSwap<T>(arr, 0, heap_len);
            int last = 0;
            int next = 2*last+1;
            if(next > heap_len-1) return; 
            if(is_max) next = MaxIdx<T>(arr, next, Min<int>(next+1, heap_len-1));
            else next = MinIdx<T>(arr, next, Min<int>(next+1, heap_len-1));

	    while(is_max ? (arr[next]>arr[last]) : (arr[next]<arr[last]) ) {
		ArrSwap<T>(arr, last, next);
		last = next;
                next = 2*next+1;
                if(next > heap_len-1) return; 
                if(is_max) next = MaxIdx<T>(arr, next, Min<int>(next+1, heap_len-1));
                else next = MinIdx<T>(arr, next, Min<int>(next+1, heap_len-1));
	    }
        }

    }
    
    /**
    * Sorts array using heap-sort algorithm.
    * T(n) = O(n log(n)), where n is arr size.
    * S(n) = O(1).
    *
    * @tparam T must be totally ordered and it must have defined >,<,= operators.
    * @param arr array of elements.
    * @param len length of the array.
    * @param rising Sort the array in rising order?.
    */
    template <typename T>
    void ArrHeapSort(T* arr, int len, bool rising = true) {
        for(int i=1; i<len; ++i) ArrHeap::Insert<T>(arr, i, rising);
        for(int i=len-1; i>0; --i) ArrHeap::Remove<T>(arr, i, rising);
    }

    
    /**
    * Sorts array using merge-sort algorithm.
    * T(n) = O(n log(n)).
    * S(n) = O(n log(n)), where n is arr size.
    *
    * @tparam T must be totally ordered and it must have defined >,<,= operators.
    * @param arr array of elements.
    * @param len length of the array.
    */
    template <typename T>
    void ArrMergeSort(T* arr, int len) {
        if(len > 1) {
            int half = len/2;
            T* a = new T[half];
            T* b = new T[len-half];
            for(int i=0; i<len; ++i) {
                if(i<half) a[i] = arr[i];
                else b[i-half] = arr[i];
            }
            ArrMergeSort<int>(a, half);
            ArrMergeSort<int>(b, len-half);
            int a_idx = 0;
            int b_idx = 0;
            for(int i=0; i<len; ++i) {
                if(a_idx == half) arr[i] = b[b_idx++];
                else if(b_idx == len-half) arr[i] = a[a_idx++];
                else {
                    if(a[a_idx] < b[b_idx]) arr[i] = a[a_idx++];
                    else arr[i] = b[b_idx++];
                }
            }
            delete[] a;
            delete[] b;
        }
    }
    
    
    /**
    * Sorts array using count-sort algorithm.
    * T(n) = O(n + m).
    * S(n) = O(m), where n is arr size and m = Max(arr) - Min(arr)
    *
    * @tparam T must be totally ordered and it must have defined >,<,= operators.
    * @param arr array of elements.
    * @param len length of the array.
    */
    void CountSort(int* arr, int len) {
        int min = ArrMin<int>(arr, len);
        int max = ArrMax<int>(arr, len);
        int t_len = max - min + 1;
        int* t_arr = new int[t_len];
        for(int i=0; i<t_len; ++i) t_arr[i] = 0;
        for(int i=0; i<len; ++i) ++t_arr[arr[i]-min];
        int idx = 0;
        for(int i=0; i<len; ++i) {
            while(t_arr[idx] == 0) ++idx;
            arr[i]=idx+min;
            --t_arr[idx];
        }
        delete[] t_arr;
    }

    /**
    * Find if element is in sorted array, between two indexes. 
    * T(n) = O(log(n)).
    * S(n) = O(1).
    *
    * @tparam T must be totally ordered and it must have defined >,<,= operators.
    * @param arr array of elements, must be sorted.
    * @param target element that is being searched for.
    * @param beg starting index.
    * @param beg ending index index.
    *
    * @return value returns True if target is in array, false otherwise 
    */
    template <typename T>
    bool BinarySearch(T* arr, T target, int beg, int end) {
        if(end < beg) return false;
        int half = (beg+end)/2;
        if(arr[half] == target) return true;
        else if(arr[half] > target) return BinarySearch(arr, target, beg, half-1);
        else return BinarySearch<T>(arr, target, half+1, end);
    };

    /**
    * Node for singly linked list
    * 
    * @param value Value stored in the node
    * @param next Pointer to next node
    */
    template <typename T>
    struct SinglyLLNode {
        T value;
        SinglyLLNode<T>* next;
        SinglyLLNode(T v, SinglyLLNode<T>* n) {
            value = v;
            next = n;
        }
    };
     
    /**
    * Singly linked list with O(1) Inset, Append and Remove First.
    * 
    * ...
    *
    * @tparam T the type of data stored in the list.
    */
    template <typename T>
    class SinglyLL {
        public:
            SinglyLL(): length(0), first(NULL) {}
            
            /**
            * Inserts new element at the end of the linked list.
            * T(n) = O(1).
            * S(n) = O(1).
            *
            * @param data element for insertion.
            */
            void Append(T data) {
                SinglyLLNode<T>* node = new SinglyLLNode<T>(data, NULL);
                if (length == 0) {
                    first = node;
                    last = node;
                }
                else {
                    last->next = node;
                    last = node;
                }
                ++length;
            }
            
            
            /**
            * Inserts new element at the beginning of the list.
            * T(n) = O(1).
            * S(n) = O(1).
            *
            * @param data element for insertion.
            */
            void Insert(T data) {
                if (length == 0) Append(data);
                else {
                    SinglyLLNode<T>* node = new SinglyLLNode<T>(data, first);
                    first = node; 
                    ++length;
                }
            }

            
            /**
            * Removes first element from the list.
            * T(n) = O(1).
            * S(n) = O(1).
            *
            * @return value data of removed element.
            */
            T RemoveFirst() {
                T returnValue = first->value;
                SinglyLLNode<T>* temp = first;
                first = first->next;
                delete(temp);
                --length;
                return returnValue;
            }

            /**
            * Removes all elements from list.
            * T(n) = O(n) where n is the number of stored elements.
            * S(n) = O(1).
            *
            * @param data element for insertion.
            */
            void Clear() {
                while(first != NULL) RemoveFirst();
            }
            
            /**
            * Returns true if the structure is empty.
            * T(n) = O(1).
            * S(n) = O(1).
            */
            bool IsEmpty() {
                if(length == 0) return true;
                else return false;
            }


            /**
            * Returns length of the list.
            * T(n) = O(1).
            * S(n) = O(1).
            */
            int Length() {
                return length;
            }

        protected:
            int length;
            SinglyLLNode<T>* first; 
            SinglyLLNode<T>* last; 

    };
    
    
    /**
    * Node for doubly linked list
    * 
    * @param value Value stored in the node
    * @param next Pointer to next node
    * @param prev Pointer to previous node
    */
    template <typename T>
    struct DoublyLLNode {
        T value;
        DoublyLLNode<T>* next;
        DoublyLLNode<T>* prev;
        DoublyLLNode(T v, DoublyLLNode<T>* n, DoublyLLNode<T>* p) {
            value = v;
            next = n;
            prev = p;
        }
    };
    
    
    /**
    * Doubly linked list with O(1) Inset, Append, Remove First and Remove Last.
    * 
    * ...
    *
    * @tparam T the type of data stored in the list.
    */
    template <typename T>
    class DoublyLL { 
        public:
            DoublyLLNode<T>* first;
            DoublyLLNode<T>* last;

            DoublyLL(): first(NULL), last(NULL), length(0) {};
            ~DoublyLL() { Clear(); }

            /**
            * Inserts new element at the end of the list.
            * T(n) = O(1).
            * S(n) = O(1).
            *
            * @param data element for insertion.
            */
            void Append(T data) {
                DoublyLLNode<T>* node = new DoublyLLNode<T>(data, NULL, NULL);
                if (length == 0) {
                    first = node;
                    last = node;
                }
                else {
                    node->prev = last;
                    last->next = node;
                    last = node;
                }
                ++length;
            }
            
            
            /**
            * Inserts new element at the beginning of the list.
            * T(n) = O(1).
            * S(n) = O(1).
            *
            * @param data element for insertion.
            */
            void Insert(T data) {
                if (length == 0) append(data);
                else {
                    DoublyLLNode<T>* node = new DoublyLLNode<T>(data, first, NULL);
                    first->prev = node;
                    first = node; 
                    ++length;
                }
            }
            
            
            /**
            * Removes last element from the list.
            * T(n) = O(1).
            * S(n) = O(1).
            *
            * @return value data of removed element.
            */
            T RemoveLast() {
                T returnValue = last->data;
                T* temp = last;
                last = last->prev;
                last->next = NULL;
                delete(temp);
                --length;
                return returnValue;
            }

            /**
            * Removes first element from the list.
            * T(n) = O(1).
            * S(n) = O(1).
            *
            * @return value data of removed element.
            */
            T RemoveFirst() {
                T returnValue = first->value;
                T* temp = first;
                first = first-> next;
                first->prev = NULL;
                delete(temp);
                --length;
                return returnValue;
            }
            
            /**
            * Removes all elements from list.
            * T(n) = O(n) where n is the number of stored elements.
            * S(n) = O(1).
            *
            * @param data element for insertion.
            */

            void Clear() {
                while(first != NULL) RemoveFirst();
            }
            /**
            * Returns true if the structure is empty.
            * T(n) = O(1).
            * S(n) = O(1).
            */
            bool IsEmpty() {
                if(length == 0) return true;
                else return false;
            }

            /**
            * Returns length of the list.
            * T(n) = O(1).
            * S(n) = O(1).
            */
            int Length() {
                return length;
            }

        private:
            int length;

    };

    /**
    * First in first out data structure with O(1) Delete and Insert.
    * 
    * ...
    *
    * @tparam T the type of data stored in the structure.
    */
    template <typename T>
    class FIFO: protected SinglyLL<T> {
        public: 
            FIFO() {};
            
            /**
            * Inserts new element into structure.
            * T(n) = O(1).
            * S(n) = O(1).
            *
            * @param data element for insertion.
            */
            void Insert(T data) { SinglyLL<T>::Insert(data); }
            
            /**
            * Removes the element, that has been in the structure for the longest time.
            * T(n) = O(1).
            * S(n) = O(1).
            *
            * @return value data of the removed element.
            */
            T Remove() { return SinglyLL<T>::RemoveFirst(); }
            
            /**
            * Returns true if the structure is empty.
            * T(n) = O(1).
            * S(n) = O(1).
            */
            bool IsEmpty() { SinglyLL<T>::IsEmpty(); }
    };
    
    
    /**
    * Last in first out storage for data with O(1) Delete and Insert.
    * 
    * ...
    *
    * @tparam T the type of data stored in the structure.
    */
    template <typename T>
    class LIFO: protected SinglyLL<T> {
        public: 
            LIFO() {};    
        
            /**
            * Inserts new element into structure.
            * T(n) = O(1).
            * S(n) = O(1).
            *
            * @param data element for insertion.
            */
            void Insert(T data) { SinglyLL<T>::Append(data); }

            /**
            * Removes the element, that has been in the structure for the shortest time.
            * T(n) = O(1).
            * S(n) = O(1).
            *
            * @return value data of the removed element.
            */
            T Remove() { return SinglyLL<T>::RemoveFirst(); }
     
            /**
            * Returns true if the structure is empty.
            * T(n) = O(1).
            * S(n) = O(1).
            */
            bool IsEmpty() { SinglyLL<T>::IsEmpty(); }
    };
    
    
    /**
    * Node for AVL trees
    * 
    * @param data data stored in node
    * @param balance height(left) - height(right)
    * @param height 0 for Node with no child, max(height(left), height(right)) + 1 otherwise
    * @left pointer to left child node
    * @right pointer to right child node
    */
    template <typename T>
    struct AVLTreeNode {
        T data;
        int balance;
        int height;
        AVLTreeNode<T>* left;
        AVLTreeNode<T>* right;
        AVLTreeNode(T d, int b, int h, AVLTreeNode<T>* l, AVLTreeNode<T>* r) {
            data = d;
            balance = b;
            height = h;
            left =l;
            right = r;
        }
        AVLTreeNode(int h) {
            height = h;
        }
    };
    
    
    /**
    * Data structure for comparable data with log(N) Insert, Delete and Find.
    * 
    * ...
    *
    * @tparam T the type of data stored in the tree. T must be totally ordered and it must have defined >,<,= operators.
    */
    template <typename T>
    class AVLTree {
        public:
            AVLTree(): size(0) {
                    end = new AVLTreeNode<T>(-1);
                    root = end;
                }

            ~AVLTree() {
                Clear();
                delete end;
            }


            /**
            * Inserts new element into AVL tree.
            * T(n) = O(log(n)), where n is the number of elements in tree.
            * S(n) = O(1).
            *
            * @param data element for insertion.
            */
            void Insert(T data) {
                if(size == 0) root = new AVLTreeNode<T>(data, 0, 0, end, end);
                else Insert(data, root, &root);
                ++size;
            }

            /**
            * Removes element from AVL tree.
            * T(n) = O(log(n)), where n is the number of elements in tree.
            * S(n) = O(1).
            *
            * @param data element which will be removed.
            // TODO 
            */
            void Remove(T data) {
               Remove(data, root, &root);
               --size;
            }

            /**
            * Find if element is in the tree.
            * T(n) = O(log(n)).
            * S(n) = O(1).
            *
            * @param data element being search.
            * @return value Is the element in the AVL tree?
            */
            bool Find(T data) {
                return Find(data, root);
            }

            /**
            * Removes all elements from the tree.
            * T(n) = O(n), where n is the number of elements in tree.
            * S(n) = O(1).
            */
            void Clear() {
                Clear(root);
            }

        protected:
            AVLTreeNode<T>* root;
            AVLTreeNode<T>* end;
            int size;
            
            
            bool Find(T data, AVLTreeNode<T>* node) {
                if (node == end) return false;
                else if (node->data == data) return true;
                else if (node->data > data) return Find(data, node->left);
                else return Find(data, node->right);
            }

            int Insert(T data, AVLTreeNode<T>* node, AVLTreeNode<T>** parent_pointer) {
                if(node->data > data) {
                    if(node->left == end) {
                        node->left = new AVLTreeNode<T>(data, 0, 0, end, end);
                        --node->balance;
                        node->height = 1;
                        return 1;
                    }
                    else {
                        int temp = Insert(data, node->left, &(node->left));
                        if(temp == 0) return 0;
                        switch(node->balance) {
                            case -1:
                                if (node->left->balance == -1) {
                                    *parent_pointer = RotateRight(node);
                                    return 0;
                                }
                                else {
                                    *parent_pointer = DoubleRotateLeft(node); 
                                    return 0;
                                }
                                break;
                            case 0:
                                node->balance = -1;
                                ++(node->height);
                                return 1;
                            case 1:
                                node->balance = 0;
                                return 0;
                        }
                    }
                }
                else {
                    if(node->right == end) {
                        node->right = new AVLTreeNode<T>(data, 0, 0, end, end); 
                        ++node->balance;
                        node->height = 1;
                        return 1;
                    }
                    else {
                        int temp = Insert(data, node->right, &(node->right));
                        if(temp == 0) return 0;
                        switch(node->balance) {
                            case 1:
                                if (node->right->balance == 1) {
                                    *parent_pointer = RotateLeft(node);
                                    return 0;
                                }
                                else {
                                    *parent_pointer = DoubleRotateLeft(node); 
                                    return 0;
                                }
                            case 0:
                                node->balance = 1;
                                ++(node->height);
                                return 1;
                            case -1:
                                node->balance = 0;
                                return 0;
                        }
                    }
                }
                return 0;
            }


            int Remove(T data, AVLTreeNode<T>* node, AVLTreeNode<T>** parent_pointer) {
                // if this node is supposed to be removed, remove the node
                if(node->data == data) {
                    if(node->left == end) {
                        if(node->right == end) {
                            *parent_pointer = end;
                            delete node;
                            return -1;
                        }
                        else {
                            *parent_pointer = node->right;
                            delete node;
                            return -1;
                        }
                    }
                    else {
                        if(node->right == end) {
                            *parent_pointer = node->left;
                            delete node;
                            return -1;
                        }
                        // is the node has both child, we need to find replacement first
                        else {
                            AVLTreeNode<T>* temp = node->right;
                            while(temp->left != end) temp = temp->left;
                            node->data = temp->data;
                            data = temp->data;
                        }
                    }
                }
                // if data is in any child we call remove on child and then handle rebalancing
                else if (node->data > data) {
                    int temp = Remove(data, node->left, &(node->left));
                    if(temp == 0) return 0;
                    switch(node->balance) {
                        case -1:
                            node->balance = 0;
                            --node->height;
                            return -1;
                        case 0:
                            node->balance = 1;
                            return 0;
                        case 1:
                            switch (node->right->balance) {
                                case -1:
                                    *parent_pointer = DoubleRotateLeft(node);
                                    return -1;
                                case 0:
                                    *parent_pointer = RotateLeft(node);
                                    return 0;
                                case 1:
                                    *parent_pointer = RotateLeft(node);
                                    return -1;
                            }
                    }
                }
                else {
                    int temp = Remove(data, node->right, &(node->right));
                    if(temp == 0) return 0;
                    switch(node->balance) {
                        case 1:
                            node->balance = 0;
                            --node->height;
                            return -1;
                        case 0:
                            node->balance = 1;
                            return 0;
                        case -1:
                            switch (node->left->balance) {
                                case 1:
                                    *parent_pointer = DoubleRotateRight(node);
                                    return -1;
                                case 0:
                                    *parent_pointer = RotateRight(node);
                                    return 0;
                                case -1:
                                    *parent_pointer = RotateRight(node);
                                    return -1;
                            }
                    }
                }
                return 0;
            }
            
            void Clear(AVLTreeNode<T>* node) {
                if(node != end) {
                    Clear(node->left);
                    Clear(node->right);
                    delete node;
                }
            }

            AVLTreeNode<T>* RotateLeft(AVLTreeNode<T>* x) {
                AVLTreeNode<T>* y = x->right;
                AVLTreeNode<T>* t = y->left;
                y->left = x;
                x->right = t;
                x->height = Max<int>(x->left->height, x->right->height) + 1;
                x->balance = x->right->height - x->left->height;
                y->height = Max<int>(y->left->height, y->right->height) + 1;
                y->balance = y->right->height - y->left->height;
                return y;
            }

            AVLTreeNode<T>* RotateRight(AVLTreeNode<T>* y) {
                AVLTreeNode<T>* x = y->left;
                AVLTreeNode<T>* t = x->right;
                x->right = y;
                y->left = t;
                y->height = Max<int>(y->left->height, y->right->height) + 1;
                y->balance = y->right->height - y->left->height;
                x->height = Max<int>(x->left->height, x->right->height) + 1;
                x->balance = x->right->height - x->left->height;
                return x;
            }

            
            AVLTreeNode<T>* DoubleRotateRight(AVLTreeNode<T>* x) {
                x->left = RotateLeft(x->left);
                return RotateRight(x);
            }

            AVLTreeNode<T>* DoubleRotateLeft(AVLTreeNode<T>* x) {
                x->left = RotateLeft(x->left);
                return RotateRight(x);
            } 
    };
   



    template <typename T>
    class ABTreeNode;
    
    
    /**
    * Knot for AB trees
    * 
    * @param key Key stored in the node
    * @param next Pointer to next knot)
    * @param child Pointer to child node, all keys stored there are smaller than key
    */
    template<typename T>
    struct ABTreeKnot{
        T key;
        ABTreeKnot<T>* next;
        ABTreeNode<T>* child;
        ABTreeKnot(T k, ABTreeKnot<T>* n, ABTreeNode<T>* c) {
            key = k;
            next = n;
            child = c;
        }
        ABTreeKnot(ABTreeNode<T>* c) {
            next = NULL;
            child = c;
        }
    };
    
    /**
    * Node for AB trees
    */
    template <typename T>
    class ABTreeNode {
        public:
            // constructor for creating root node;
            ABTreeNode(): key_count(0), last_layer(false), parent_node(NULL) {
                list = new ABTreeKnot<T>(NULL);
            }
            
            // constructor for creating first no-root node
            ABTreeNode(bool l):  key_count(0), last_layer(l) {
                list = new ABTreeKnot<T>(NULL);
            }
            
            // constructor for 
            ABTreeNode(ABTreeNode<T>* n, ABTreeKnot<T>* k): key_count(0), last_layer(true), parent_node(n), parent_knot(k) {
                list = new ABTreeKnot<T>(NULL);
            }
            
            // constructor for crating node with data, used when splitting/merging
            ABTreeNode(int k, bool l, ABTreeNode<T>* p, ABTreeKnot<T>* li):
                key_count(k), last_layer(l), parent_node(p), list(li), parent_knot(NULL) {}
           
            
            /**
            * Tries to insert data into node.
            * At success returns NULL
            * If it fails return pointer to child that leads the right way
            */
            ABTreeNode<T>* Insert(T data) {
                // inserting into empty tree
                if(list->next == NULL) {
                    list = new ABTreeKnot<T>(data, list, NULL);
                    ++key_count;
                    return NULL;
                }
                    
                // if this is the lowest level, we will be inserting here
                if(last_layer) {
                    ++key_count;
                    if(data < list->key) list = new ABTreeKnot<T>(data, list, NULL); 
                    else {
                        ABTreeKnot<T>* pt = list;
                        while(pt->next->next != NULL) {
                            if(data < pt->next->key) { 
                                pt->next = new ABTreeKnot<T>(data, pt->next, NULL);
                                return NULL;
                            }
                            pt = pt->next;
                        }
                        pt->next = new ABTreeKnot<T>(data, pt->next, NULL);
                    }
                    return NULL;
                }
                
                // if its not the lowest level, find the right child
                else {
                    ABTreeKnot<T>* pt = list;
                    while(pt->next != NULL) {
                        if(data < pt->key) return pt->child;
                        pt = pt->next;
                    }
                    return pt->child; 
                }
            }

            
            /**
            * Splits the node into 2 halves.
            * Used to handle overflow.
            */
            void Split() {
                // make new node with second half of knots
                ABTreeKnot<T>* pt = list;
                for(int i=0; i<key_count/2; ++i) pt = pt->next;
                ABTreeNode<T>* new_node = new ABTreeNode<T>(((key_count-1)/2), last_layer, parent_node, pt->next);
                
                // set this new node as parent for her child
                if(!last_layer) {
                    ABTreeKnot<T>* pt2 = pt->next;
                    while(pt2 != NULL) {
                        pt2->child->SetParentNode(new_node);
                        pt2 = pt2->next;
                    }
                }
             
                // removing end pointer of first half
                T new_key = pt->key;
                pt->next = NULL;

                // join split nodes into corresponding knots
                parent_node->SplitChild(parent_knot, new_node, new_key);

                // updating key_count
                key_count = key_count/2; 
            }
            
            
             
            /**
            * Used to handle underflow
            * Tries to steal knot from brother node, if it fails, it merges this node with brother node.
            */
            void Join(int a) {
                // if the root is empty, delete it
                if(parent_knot == NULL){
                    if(key_count == 0) {
                        if(last_layer) return;
                        parent_node->GetList()->child = list->child;
                        list->child->SetParentNode(parent_node);
                        list->child->SetParentKnot(NULL);
                        delete list;
                        delete this;
                    }
                    else return;
                }

                else {
                    // Try using left brother
                    if(parent_knot->next != NULL) {
                        // find last knot
                        ABTreeKnot<T>* end = list;
                        while(end->next != NULL) end = end->next;

                        //find brother
                        ABTreeNode<T>* brother = parent_knot->next->child;

                        // if brother has >a knots, just steal one
                        if(brother->GetKeyCount() > a) {
                            
                            // move keys
                            end->key = parent_knot->key;
                            parent_knot->key = brother->GetList()->key;
                            
                            // steal knot from brother
                            end->next = brother->GetList();
                            brother->SetList(brother->GetList()->next);
                            end->next->next = NULL;
                            
                            // if not on last layer, update parent info in new knot
                            if(!last_layer) {
                                end->next->child->SetParentNode(parent_node);
                                end->next->child->SetParentKnot(parent_knot);
                            }
                            
                            //update key counts
                            brother->SetKeyCount(brother->GetKeyCount() - 1);
                            ++key_count;
                        }

                        // if brother has exactly a knots, merge him into this node
                        else {
                            // connect brothers knots
                            end->key = parent_knot->key;
                            end->next = brother->GetList();

                            // if not on last layer set new parent knot and node to moved knots
                            if(!last_layer) {
                                ABTreeKnot<T>* pt  = brother->GetList();
                                while(pt != NULL){
                                    pt->child->SetParentKnot(parent_knot);
                                    pt->child->SetParentNode(parent_node);
                                    pt = pt->next;
                                }
                            }
                            
                            // update key counts in current node
                            key_count += brother->GetKeyCount() + 1;
                            parent_node->SetKeyCount(parent_node->GetKeyCount() - 1);
                            
                            // delete brother
                            brother->SetList(NULL);
                            delete brother;
                            
                            // remove brothers knot in parent node
                            parent_knot->key = parent_knot->next->key;
                            ABTreeKnot<T>* del = parent_knot->next;
                            parent_knot->next = parent_knot->next->next;
                            delete del;
                        }
                    }

                    // Use left brother
                    else {
                        // find brother
                        ABTreeKnot<T>* prev = parent_node->FindPrev(parent_knot);
                        ABTreeNode<T>* brother = prev->child;
                        
                        
                        // if brother has >a knots, just steal one
                        if(brother->GetKeyCount() > a) {
                            // find brothers last knot
                            ABTreeKnot<T>* pt = brother->GetList();
                            while(pt->next->next != NULL) pt = pt->next;
                            ABTreeKnot<T>* brother_end = pt->next;

                            // steal knot
                            pt->next = NULL;
                            brother_end->next = list;
                            list = brother_end;
                            
                            //move keys
                            brother_end->key = prev->key;
                            prev->key = pt->key;

                            
                            // if not on last layer, update parent info in new knot
                            if(!last_layer) {
                                list->child->SetParentKnot(parent_knot);
                                list->child->SetParentNode(parent_node);
                            }

                            // update key count
                            brother->SetKeyCount(brother->GetKeyCount() - 1);
                            ++key_count;
                        }
                        // merge this node into brother
                        else {
                            // find last knot of brother 
                            ABTreeKnot<T>* brother_end = brother->GetList();
                            while(brother_end->next != NULL) brother_end = brother_end->next;
                            
                            // join nodes 
                            brother_end->key = prev->key;
                            brother_end->next = list;
                            prev->key = parent_knot->key;
                            prev->next = parent_knot->next;
                             
                            // if not on last layer set new parent knot and node to moved knots
                            if(!last_layer) {
                                ABTreeKnot<T>* pt  = list;
                                while(pt != NULL){
                                    pt->child->SetParentNode(brother);
                                    pt = pt->next;
                                }
                            }

                            //update key counts
                            brother->SetKeyCount(brother->GetKeyCount() + key_count + 1);
                            parent_node->SetKeyCount(parent_node->GetKeyCount() - 1);
                            
                            delete parent_knot;
                            list = NULL;
                            delete this;
                        }
                    }
                }
            }

            
            /** 
            * Returns true if data is stored in sub tree with root in this node
            */
            bool Find(T target) {
                ABTreeNode<T>* next_node = NULL;
                if(SearchList(target, &next_node) != NULL) return true;
                else if(next_node == NULL) return false;
                else return next_node->Find(target);
            }
            
            /*
            * Removes targeted node from sub tree with root in this node
            */
            ABTreeNode<T>* Remove(T* target) {
                // find way towards target
                ABTreeNode<T>* next_node = NULL;
                ABTreeKnot<T>* knot = SearchList(*target, &next_node);

                if(knot != NULL) {
                    // if this is the last layer, just delete right knot
                    if(last_layer) {
                        ABTreeKnot<T>* del;
                        // if its the first knot, just delete it
                        if(knot == list) {
                            del = list;
                            list = list->next;
                        }
                        // if its not, we first need to find previous knot to reconnect pointers
                        else {
                            ABTreeKnot<T>* prev = FindPrev(knot);
                            del = prev->next;
                            prev->next = knot->next;
                        }
                        --key_count; 
                        delete del;
                        return NULL; 
                    }
                    // else find knot in last layer to swap places with
                    else {
                        ABTreeNode<T>* pt = knot->next->child;
                        while(!pt->IsLastLayer()) pt = pt->GetList()->child;
                        *target = pt->GetList()->key;
                        knot->key = *target;
                        return knot->next->child;
                    }
                }
                return next_node; 
            }
            
    

            // Setters and getters for some protected variables
            void SetParentKnot(ABTreeKnot<T>* knot) { parent_knot = knot; }

            void SetParentNode(ABTreeNode<T>* node) { parent_node = node; }

            ABTreeKnot<T>* GetParentKnot() { return parent_knot; }

            ABTreeNode<T>* GetParentNode() { return parent_node; }
            
            void SetList(ABTreeKnot<T>* new_list) { list = new_list; }

            ABTreeKnot<T>* GetList() { return list; }

            void SetKeyCount(int new_key_count) { key_count = new_key_count; }

            int GetKeyCount() { return key_count; }

            bool IsLastLayer() { return last_layer; }

        protected:
            int key_count;
            bool last_layer;
            ABTreeKnot<T>* parent_knot;
            ABTreeNode<T>* parent_node;
            ABTreeKnot<T>* list;
                
            
            /*
            * Handles changes in this node when some of child nodes splits
            */
            void SplitChild(ABTreeKnot<T>* knot, ABTreeNode<T>* new_node, T new_key) {
                // if this is the root node
                if(parent_node == NULL) {
                    // making new root node
                    ABTreeKnot<T>* second_knot = new ABTreeKnot<T>(new_node); 
                    ABTreeKnot<T>* first_knot = new ABTreeKnot<T>(new_key, second_knot, list->child);
                    list->child = new ABTreeNode<T>(1, false, this, first_knot);    

                    // setting right parent knots and nodes
                    new_node->SetParentNode(list->child);
                    new_node->SetParentKnot(second_knot);
                    first_knot->child->SetParentNode(list->child);
                    first_knot->child->SetParentKnot(first_knot);
                }
                // if its not
                else {
                    knot->next = new ABTreeKnot<T>(knot->key, knot->next, new_node);
                    knot->key = new_key;
                    new_node->SetParentKnot(knot->next);
                    ++key_count;
                }
            }
            
            
            /*
            * Searches through knot list for target.
            * On success returns pointer to right knot
            * Of fail returns NULL and stores pointer to right child in next_node
            */
            ABTreeKnot<T>* SearchList(T target, ABTreeNode<T>** next_node) {
                ABTreeKnot<T>* pt = list;
                while(pt->next != NULL) {
                    if(pt->key == target) return pt;
                    else if(pt->key > target) {
                        *next_node = pt->child;
                        return NULL;
                    }
                    pt = pt->next;
                }
                *next_node = pt->child;
                return NULL;
            }
            
            /*
            * Returns pointer to node previous to knot in args.
            */ 
            ABTreeKnot<T>* FindPrev(ABTreeKnot<T>* knot) {
                ABTreeKnot<T>* pt = list;
                while(pt->next != knot) {
                        pt = pt->next;
                }
                return pt;
            }
    };


    /*
    * AB Tree
    * 
    * @tparam T must be totally ordered and it must have defined >,<,= operators.
    */
    template <typename T>
    class ABTree {
        public:
            /* 
            * a must be >=2 and b>=2*a-1
            */
            ABTree(int _a, int _b): a(_a), b(_b), size(0) {
                root = new ABTreeNode<T>();
                root->GetList()->child = new ABTreeNode<T>(true);
                root->GetList()->child->SetParentNode(root);
                root->GetList()->child->SetParentKnot(NULL);
             }
            
            
            /**
            * Inserts new item into structure.
            * T(n) = O(log(n)), where n is number of items stored in structure.
            *
            * @param data Item that will be inserted.
            */
            void Insert(T data) { 
                Insert(data, root->GetList()->child); 
                ++size;
            }
            
            /**
            * Removes item into structure.
            * T(n) = O(log(n)), where n is number of items stored in structure.
            *
            * @param data Item that will be removed.
            */
            void Remove(T data) { 
                Remove(data, root->GetList()->child); 
                --size;
            }
            
            /**
            * Returns true if data is in the structure, false otherwise.
            * T(n) = O(log(n)), where n is number of items stored in structure.
            *
            * @param data Item that will be searched for.
            */
            bool Find(T data) { return root->GetList()->child->Find(data); }

        protected:
            int a;
            int b;
            int size;
            ABTreeNode<T>* root;

            void Insert(T data, ABTreeNode<T>* node) {
                ABTreeNode<T>* next_node = node->Insert(data);
                if(next_node != NULL) Insert(data, next_node);
                if(node->GetKeyCount() > b) node->Split();
            }

            void Remove(T data, ABTreeNode<T>* node) {
                ABTreeNode<T>* next_node = node->Remove(&data);
                if(next_node != NULL) Remove(data, next_node);
                if(node->GetKeyCount() < a) node->Join(a);
            }
            
    };
}


