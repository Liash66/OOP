#include <iostream>

double f(double x)
{
    return x * x;
}

class dif
{
protected:
    double m_dx;

public:
    dif(const double& dx) : m_dx(dx)
    {}

    virtual ~dif()
    {}

    virtual double calcDif(double (*f)(double), double x) = 0;
};

class left_dif : public dif
{
public:
    left_dif(const double& dx) : dif(dx)
    {}

    double calcDif(double (*f)(double), double x) override
    {
        if (m_dx > 0)
            return (f(x) - f(x - m_dx)) / m_dx;
        else if (m_dx < 0)
        {
            std::cout << "Шаг не может быть отрицательным" << std::endl;
            return 0;
        }
        else if (m_dx != 0)
        {
            std::cout << "Деление на ноль" << std::endl;
            return 0;
        }
    }
};

class right_dif : public dif
{
public:
    right_dif(const double& dx) : dif(dx)
    {}

    double calcDif(double (*f)(double), double x) override
    {
        if (m_dx >= 0)
            return (f(x + m_dx) - f(x)) / m_dx;
        else if (m_dx < 0)
        {
            std::cout << "Шаг не может быть отрицательным" << std::endl;
            return 0;
        }
        else if (m_dx != 0)
        {
            std::cout << "Деление на ноль" << std::endl;
            return 0;
        }
    }
};

class mid_dif : public dif
{
public:
    mid_dif(const double& dx) : dif(dx)
    {}

    double calcDif(double (*f)(double), double x) override
    {
        if (m_dx != 0)
            return (f(x + m_dx) - f(x - m_dx)) / (2 * m_dx);
        else if (m_dx < 0)
        {
            std::cout << "Шаг не может быть отрицательным" << std::endl;
            return 0;
        }
        else if (m_dx != 0)
        {
            std::cout << "Деление на ноль" << std::endl;
            return 0;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "rus");

    double dx = 0.1;
    double x = 1;

    left_dif* l_dif = new left_dif(dx);
    right_dif* r_dif = new right_dif(dx);
    mid_dif* m_dif = new mid_dif(dx);

    std::cout << "Левая производная: " << l_dif->calcDif(f, x) << std::endl;
    std::cout << "Правая производная: " << r_dif->calcDif(f, x) << std::endl;
    std::cout << "Средняя производная: " << m_dif->calcDif(f, x) << std::endl;

    return 0;
}