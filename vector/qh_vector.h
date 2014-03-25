#ifndef QIHOO_VECTOR_H_
#define QIHOO_VECTOR_H_

namespace qh
{
    template<class T>
    class vector {
    public:
        //ctor
        vector()
            : data_(NULL), size_(0)
        {
        }

        explicit vector( size_t n, const T& value = T())
        {
            data_ = new T[n];
            for (size_t i = 0; i < n; i++)
            {
                data_[0] = value;
            }
        }

        vector<T>& operator=(const vector<T>& rhs)
        {
            if (this == &rhs)
            {
                return *this;
            }
            data_ = rhs.data_;
            size_ = rhs.size_;
        }

        //dtor
        ~vector()
        {
            if (data_ != NULL)
            {
                delete data_;
            }
        }

        //get
        size_t size() const
        {
            return size_;
        }

        size_t capacity() const
        {
            return capacity_;
        }

        // set & get
        T& operator[](size_t index)
        {
            return data_[index];
        }

        // set
        void push_back(const T& element);
        void pop_back();
        void resize();
        void reserve(size_t n);

        void clear()
        {
            size_ = 0;
        }

        bool empty()
        {
            return size_ == 0;
        }

    private:
        T*      data_;
        size_t  size_;
        size_t  capacity_;
    };

    template<class T>
    void vector<T>::reserve(size_t n)
    {
        capacity_ = n;
        T* new_data = new T[capacity];
        for (size_t i = 0; i != size_; ++i)
        {
            new_data[i] = data_[i];
        }
        delete [] data_;
        data_ = new_data;
    }

     template<class T>
     void vector<T>::resize()
     {
        capacity<<1;
        reserve(capacity);        
     }

    template<class T>
    void vector<T>::push_back(const T& element)
    {
        if (size_ == 0 || size_ == capacity_)
        {
            resize();
        }

        data_[size_] = element;
        ++size_;
    }

    template<class T>
    void vector<T>::pop_back()
    {
        if (size_ != 0)
        {
            --size_;
        }
    }

   

    
}



#endif


