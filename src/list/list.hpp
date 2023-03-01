#pragma once

#include <cstddef>

#include "../iterator/sequentual/iterator.hpp"
#include "../iterator/sequentual/const_iterator.hpp"

template <typename T>
class List
{
    public:
        // Ctors
        List();

        explicit List(size_t count);

        List(const List<T> &);

        List(List<T> &&) noexcept;

        // Destructor
        virtual ~List()
        {
            // TODO: remove
            std::cout << "~List()" << std::endl;
            //
            try
            {
                ::operator delete(m_arr);
            }
            catch (const std::exception& e)
            {
                std::cerr << "ERR: " << e.what() << std::endl;
            }
        }

        // Methods
        void insert(size_t pos, const T&); // TODO: сменить тип pos на iterator

        void emplace(size_t pos, const T&); // TODO: сменить тип pos на iterator

        void push_back(const T &);

        void push_back(const T &&);

        template<class... Args>
        void emplace_back(Args&&...);

        void erase(size_t pos); // TODO: сменить тип pos на iterator
    //        void erase(range); // TODO: версия для рейнджа
        void resize(size_t count);

        size_t size() { return m_size; }

        size_t cap() { return m_cap; }

        // Iterator
        Iterator<T> begin();

        Iterator<T> end();

        ConstIterator<T> cbegin();

        ConstIterator<T> cend();

        // Operators
        List<T>& operator=(const List<T>&);

        List<T>& operator=(List<T>&&) noexcept;

        T& operator[](size_t index);

        const T& operator[](size_t index) const;

protected:
        size_t m_size;
        size_t m_cap;
        T* m_arr;

        const static size_t m_default_cap = 4;


        struct GrowthCoefficients
        {
            constexpr static float tiny = 2;
            constexpr static float small = 1.8;
            constexpr static float medium = 1.6;
            constexpr static float large = 1.5;
        };

        struct LimitValues
        {
            constexpr static unsigned short tiny = 64;
            constexpr static unsigned short small = 512;
            constexpr static unsigned short medium = 2048;
            constexpr static unsigned short large = 4096;
        };

        void copy(const List<T>&);
        void move(List<T>&& other);
        size_t calc_capacity();
};

#include "list_ctors.ipp"
#include "list_operators.ipp"
#include "list_private_methods.ipp"
#include "list_methods.ipp"
#include "list_iterator.ipp"
