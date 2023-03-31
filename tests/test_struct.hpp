struct A
{
    A() = default;

    A(int a_, int b_) : a(a_), b(b_) {}

    int a;
    double b;

    A(const A& other)
    {
        a = other.a;
        b = other.b;
    }

    A(A&& other) noexcept
    {
        a = other.a;
        b = other.b;

        other.a = 0;
        other.b = 0;
    }

    ~A()
    {
        a = 0;
        b = 0;
    }

    A& operator=(const A& other)
    {
        if (*this != other)
        {
            a = other.a;
            b = other.b;
        }

        return *this;
    }

    A& operator=(A&& other) noexcept
    {
        if (*this != other)
        {
            a = other.a;
            b = other.b;

            other.a = 0;
            other.b = 0;
        }

        return *this;
    }

    bool operator==(const A& other) const
    {
        return a == other.a && b == other.b;
    }

    bool operator!=(const A& other) const
    {
        return a != other.a || b != other.b;
    }
};