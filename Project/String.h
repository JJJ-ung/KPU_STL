//-----------------------------------------------------------------------------
// String.h - STL ���� ������ �����ϱ� ���� ���� �ڿ��� Ȯ���ϴ� Ŭ����
//
// STL�� ǥ�� �����̳�ó�� �����ϰ� ������. (STL�� �۵������ľ�)
//
// 2021. 3. 30                           Programmed by wulong
//-----------------------------------------------------------------------------
#pragma once

#include <iostream>
#include <random>
#include <iterator>

using std::cout;
using std::endl;

//#define ����         // �� �ּ��� Ǯ�� special member�� ������ �� �� �ִ�.

//#define __cpp_lib_concepts

std::default_random_engine dre;
std::uniform_int_distribution<> uidAlpha{ 'a', 'z' };
class String_iterator
{
	char* p{ nullptr };

public:
	using iterator_concept = std::contiguous_iterator_tag;

public:
    String_iterator(char* p) : p{ p } {}

    bool operator== (const String_iterator& rhs) const
    {
        return p == rhs.p;
    }

    bool operator!= (const String_iterator& rhs) const
    {
        return p != rhs.p;
    }

    String_iterator& operator++()
    {
        ++p;
        return *this;
    }

    String_iterator& operator--()
    {
        --p;
        return *this;
    }

    char& operator* ()
    {
        return *p;
    }

    char& operator* () const
    {
        return *p;
    }

    // 2021.04.29 
    int operator-(const String_iterator& rhs) const
    {
        return int(p - rhs.p);
    }
    String_iterator operator-(const int value) const
    {
        return String_iterator(p - value);
    }

    String_iterator operator+(const int value) const
    {
        return String_iterator(p + value);
    }
    bool operator<(const String_iterator& rhs) const
    {
        return p < rhs.p;
    }
};


// 2021.05.06
// ���ͷ������� Ư���� ��ӹ��� �ʰ�
// ���� �����Ͽ� C++17 ���Ŀ��� ��밡���ϵ��� �Ѵ�
template<>
struct std::iterator_traits<String_iterator>
{
    using iterator_concept = std::contiguous_iterator_tag;
    using iterator_category = std::random_access_iterator_tag;
    using value_type = char;
    using pointer = char*;
    using reference = char&;
    using difference_type = std::ptrdiff_t;
};


class String_reverse_iterator
{
    char* p{ nullptr };

public:
    String_reverse_iterator(char* p) : p{ p } {}

    bool operator!= (const String_reverse_iterator& rhs) const
    {
        return p != rhs.p;
    }

    String_reverse_iterator& operator++()
    {
        --p;
        return *this;
    }

    char operator* ()
    {
        return *(p - 1);
    }
};

class String {
    using iterator = String_iterator;
    using reverse_iterator = String_reverse_iterator;

public:
    String(size_t n) : num{ n }, p{ new char[num] } {
#ifdef ����
        cout << "������(int) (this:" << this << ") - ����: "
            << num << ", ��ġ:" << (void*)p << endl;
#endif

        for (int i = 0; i < num; ++i)
            p[i] = uidAlpha(dre);
    }

    // 2021.04.20 ������ �߰�   
    String(const char* s) : num{ strlen(s) }, p{ new char[num] }
    {
        memcpy(p, s, num);
#ifdef ����
        cout << "������(int) (this:" << this << ") - ����: "
            << num << ", ��ġ:" << (void*)p << endl;
#endif
    }

    ~String() {
#ifdef ����
        cout << "�Ҹ��� (this:" << this << ") - ����: "
            << num << ", ��ġ:" << (void*)p << endl;
#endif
        delete[] p;
    }

    // ���������
    String(const String& other) : num{ other.num }, p{ new char[num] } {
        memcpy(p, other.p, num);

#ifdef ����
        cout << "��������� (this:" << this << ") - ����: "
            << num << ", ��ġ:" << (void*)p << endl;
#endif
    }

    // �����Ҵ翬����
    String& operator=(const String& other) {
        if (this != &other) {
            this->~String();
            num = other.num;
            p = new char[num];
            memcpy(p, other.p, num);
        }

#ifdef ����
        cout << "�����Ҵ翬���� (this:" << this << ") - ����: "
            << num << ", ��ġ:" << (void*)p << endl;
#endif

        return *this;
    }

    // �̵�������
    String(String&& other) noexcept : num{ other.num } {
        p = other.p;
        other.p = nullptr;
        other.num = 0;

#ifdef ����
        cout << "�̵������� (this:" << this << ") - ����: "
            << num << ", ��ġ:" << (void*)p << endl;
#endif
    }

    // �̵��Ҵ翬����
    String& operator=(String&& other) noexcept {
        if (this != &other) {
            this->~String();
            num = other.num;
            p = other.p;

            other.num = 0;
            other.p = nullptr;
        }

#ifdef ����
        cout << "�̵��Ҵ翬���� (this:" << this << ") - ����: "
            << num << ", ��ġ:" << (void*)p << endl;
#endif

        return *this;
    }

    bool operator==(const String& rhs) const
    {
        if (num != rhs.num)
            return false;
        for (int i = 0; i < num; ++i)
            if (p[i] != rhs.p[i])
                return false;

        return true;
    }

    size_t size() const {
        return num;
    }

    // 2021.04.20 �߰�
    iterator begin()
    {
        return iterator(p);
    }

    iterator end()
    {
        return iterator{ p + num };
    }

    // 2021.04.20 �߰�
    reverse_iterator rbegin()
    {
        return reverse_iterator{ p + num };
    }

    reverse_iterator rend()
    {
        return reverse_iterator{ p };
    }

    // 2021.05.06 �߰�
    void set(std::string s)
    {
        num = s.size();
        p = new char[num];
        memcpy(p, s.data(), num);
    }

    // 2021.05.13 �߰�
    bool operator<(const String& rhs) const
    {
        return num < rhs.num;
    }

private:
    size_t num;                         // Ȯ���� �ڿ��� ��
    char* p;                                // Ȯ���� �ڿ��� ��ġ

    friend std::ostream& operator<<(std::ostream&, const String&);
    friend std::istream& operator>>(std::istream&, String&);
};

std::ostream& operator<<(std::ostream& os, const String& s)
{
    for (int i = 0; i < s.num; ++i)
        os << s.p[i];
    return os;
}

inline std::istream& operator>>(std::istream& is, String& s)
{
    std::string str;
    is >> str;
    s.set(str);

    return is;
}

