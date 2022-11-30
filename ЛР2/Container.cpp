#pragma once

template <typename T> class Container {
public:

    Container() {
        length = 0;
        allocated = 1;
        data = new T[allocated];
    };
    Container(int leng) :
        length{ leng }
    {
        if (length > 0)
        {
            data = new T[leng];
            allocated = data;
        }
    }

    T& operator[](int index)
    {
        return data[index];
    }

    T* begin() {
        return data;
    }

    T* end() {
        return data + length;
    }


    int getLength() const { return length; }

    void reserve() {
        if (allocated > length)
            return;
        T* newArr = new T[2 * allocated];
        for (size_t i = 0; i < length; i++)
        {
            newArr[i] = data[i];
        }
        delete[] data;
        data = newArr;
        allocated *= 2;
    }

    void pushBack(const T& value) {
        reserve();
        data[length] = value;
        length++;
    }

    void pushStart(const T& value) {
        reserve();
        T* newArr = new T[allocated];
        for (size_t i = 0; i < length; i++)
        {
            newArr[i + 1] = data[i];
        }
        newArr[0] = value;
        delete[] data;
        data = newArr;
        length++;
    }

    void clear()
    {
        delete[] data;
        data = nullptr;
        length = 0;
    }

    void erase(T* index) {
        size_t n = index - begin();
        for (size_t i = n; i < length; i++)
        {
            data[i] = data[i + 1];
        }
        length--;
    }

private:
    int length, allocated;
    T* data;
};