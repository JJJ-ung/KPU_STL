//-----------------------------------------------------------------------------
// String.h - STL 내부 동작을 관찰하기 위해 만든 자원을 확보하는 클래스
//
// STL의 표준 컨테이너처럼 동작하게 만들자. (STL의 작동원리파악)
//
// 2021. 3. 30                           Programmed by wulong
//-----------------------------------------------------------------------------
#pragma once

#include <iostream>
#include <random>
#include <iterator>

using std::cout;
using std::endl;

//#define 관찰         // 이 주석을 풀면 special member의 동작을 알 수 있다.

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
// 이터레이터의 특성을 상속받지 않고
// 직접 정의하여 C++17 이후에도 사용가능하도록 한다
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
#ifdef 관찰
        cout << "생성자(int) (this:" << this << ") - 갯수: "
            << num << ", 위치:" << (void*)p << endl;
#endif

        for (int i = 0; i < num; ++i)
            p[i] = uidAlpha(dre);
    }

    // 2021.04.20 생성자 추가   
    String(const char* s) : num{ strlen(s) }, p{ new char[num] }
    {
        memcpy(p, s, num);
#ifdef 관찰
        cout << "생성자(int) (this:" << this << ") - 갯수: "
            << num << ", 위치:" << (void*)p << endl;
#endif
    }

    ~String() {
#ifdef 관찰
        cout << "소멸자 (this:" << this << ") - 갯수: "
            << num << ", 위치:" << (void*)p << endl;
#endif
        delete[] p;
    }

    // 복사생성자
    String(const String& other) : num{ other.num }, p{ new char[num] } {
        memcpy(p, other.p, num);

#ifdef 관찰
        cout << "복사생성자 (this:" << this << ") - 갯수: "
            << num << ", 위치:" << (void*)p << endl;
#endif
    }

    // 복사할당연산자
    String& operator=(const String& other) {
        if (this != &other) {
            this->~String();
            num = other.num;
            p = new char[num];
            memcpy(p, other.p, num);
        }

#ifdef 관찰
        cout << "복사할당연산자 (this:" << this << ") - 갯수: "
            << num << ", 위치:" << (void*)p << endl;
#endif

        return *this;
    }

    // 이동생성자
    String(String&& other) noexcept : num{ other.num } {
        p = other.p;
        other.p = nullptr;
        other.num = 0;

#ifdef 관찰
        cout << "이동생성자 (this:" << this << ") - 갯수: "
            << num << ", 위치:" << (void*)p << endl;
#endif
    }

    // 이동할당연산자
    String& operator=(String&& other) noexcept {
        if (this != &other) {
            this->~String();
            num = other.num;
            p = other.p;

            other.num = 0;
            other.p = nullptr;
        }

#ifdef 관찰
        cout << "이동할당연산자 (this:" << this << ") - 갯수: "
            << num << ", 위치:" << (void*)p << endl;
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

    // 2021.04.20 추가
    iterator begin()
    {
        return iterator(p);
    }

    iterator end()
    {
        return iterator{ p + num };
    }

    // 2021.04.20 추가
    reverse_iterator rbegin()
    {
        return reverse_iterator{ p + num };
    }

    reverse_iterator rend()
    {
        return reverse_iterator{ p };
    }

    // 2021.05.06 추가
    void set(std::string s)
    {
        num = s.size();
        p = new char[num];
        memcpy(p, s.data(), num);
    }

    // 2021.05.13 추가
    bool operator<(const String& rhs) const
    {
        return num < rhs.num;
    }

private:
    size_t num;                         // 확보한 자원의 수
    char* p;                                // 확보한 자원의 위치

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

