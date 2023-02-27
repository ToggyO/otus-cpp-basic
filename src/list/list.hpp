#pragma once

#include <cstddef>

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

        // TODO: тест
        T* get_arr() const
        {
            return m_arr;
        }

        // Operators
        List<T>& operator=(const List<T>&);

        List<T>& operator=(const List<T>&&);

        T& operator[](size_t index);

        const T& operator[](size_t index) const;

    protected:
        size_t m_size;
        size_t m_cap;
        T *m_arr;
        int id;

        const static size_t m_default_cap = 4;
        constexpr static float m_coefficients[3] = {1.5, 1.6, 2};

//        enum class Coefficients
//        {
//            Double = 2,
//            OnePointEight = 1.8,
//            OnePointSix = 1.6,
//            OnePointFive = 1.5,
//            OnePointFour = 1.4,
//        };
//
//        enum class LimitValues
//        {
//            Small = 64,
//            Medium = 512,
//            Large = 2048,
//            Huge = 4096,
//        };

        void copy(const List<T>&);
        void move(List<T>&& other);
        void grow(); // TODO
};

#include "list_ctors.ipp"
#include "list_operators.ipp"
#include "list_private_methods.ipp"
#include "list_methods.ipp"