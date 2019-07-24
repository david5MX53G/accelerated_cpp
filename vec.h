//
// Created by branch on 7/19/19.
//

#ifndef ACCELERATED_CPP_VEC_H
#define ACCELERATED_CPP_VEC_H

#include <cstddef>
#include <memory>

template <class T> class Vec {
public:
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef size_t size_type;
    typedef T value_type;
    typedef T& reference;
    typedef const T& const_reference;

    Vec() { create(); }
    explicit Vec(size_type n, const T& t = T()) { create(n, t); }
    Vec(const Vec& v) { create(v.begin(), v.end()); }

    // returns a reference to a copy of the original arg
    Vec& operator=(const Vec& rhs) {
        if (&rhs != this) {
            uncreate();
            create(rhs.begin(), rhs.end());
        }
        return *this;
    };

    ~Vec() { uncreate(); }

    T& operator[](size_type i) { return data[i]; }
    const T& operator[](size_type i) const { return data[i]; }

    void push_back(const T& t) {
        if (avail == limit)
            grow();
        unchecked_append(t);
    }

    size_type size() const { return avail - data; }

    iterator begin() { return data; }
    const_iterator begin() const { return data; }

    iterator end() { return avail; }
    const_iterator end() const { return avail; }

private:
    iterator data; // first element of Vec
    iterator avail; // one past last element of Vec
    iterator limit; // one past allocated memory of Vec

    std::allocator<T> alloc; // object to handle memory allocation

    // allocate and init underlying array
    void create() {
        data = avail = limit = 0;
    }

    void create(size_type n, const T& val) {
        data = alloc.allocate(n);
        limit = avail = data + n;
        std::uninitialized_fill(data, limit, val);
    }

    void create(const_iterator i, const_iterator j) {
        data = alloc.allocate(j - i);
        limit = avail = std::uninitialized_copy(i, j, data);
    }
    // destroy elements and free memory
    void uncreate() {
        if (data) {
            iterator it = avail;

            while (it != data)
                alloc.destroy(--it);

            alloc.deallocate(data, limit - data);
        }
        data = limit = avail = 0;
    };

    // support funcs for push_back
    void grow() {
        // allocate 2x space needed
        size_type new_size = max(2 * (limit - data), ptrdiff_t(1));

        // copy existing elements to new space
        iterator new_data = alloc.allocate(new_size);
        iterator new_avail = uninitialized_copy(data, avail, new_data);

        // return old space
        uncreate();

        // reset pointers to new space
        data = new_data;
        avail = new_avail;
        limit = data + new_size;
    }

    void unchecked_append(const T& val) {
        alloc.construct(avail++, val);
    }
};
#endif //ACCELERATED_CPP_VEC_H
