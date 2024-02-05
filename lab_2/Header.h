#pragma once
#include <vector>
#include <stdexcept>

namespace mt
{
    template<typename T>
    class Array3d
    {
    private:
        int m_h, m_w, m_d;
        std::vector<T> m_arr;

    public:
        Array3d(int h, int w, int d) : m_h(h), m_w(w), m_d(d)
        {
            m_arr.resize(m_h * m_w * m_d);
        }

        void setValue(T temp, int i, int j, int k)
        {
            if (i >= m_h || j >= m_w || k >= m_d || i < 0 || j < 0 || k < 0)
                throw std::out_of_range("Выход за пределы массива");
            else
                m_arr[(m_arr.size() / m_h) * i + (m_arr.size() / (m_h * m_w)) * j + k] = temp;
        }

        T getValue(int i, int j, int k) const
        {
            if (i >= m_h || j >= m_w || k >= m_d || i < 0 || j < 0 || k < 0)
                throw std::out_of_range("Выход за пределы массива");
            else
                return m_arr[(m_arr.size() / m_h) * i + (m_arr.size() / (m_h * m_w)) * j + k];
        }

        void print() {
            for (int i = 0; i < m_h; i++) {
                for (int j = 0; j < m_w; j++) {
                    for (int k = 0; k < m_d; k++) {
                        std::cout << getValue(i, j, k) << " ";
                    }
                    std::cout << std::endl;
                }
                std::cout << std::endl;
            }
        }

        std::vector<T> fill(T value)
        {
            std::vector<T> filledList(m_arr.size(), value);
            return filledList;
        }

        std::vector<T> getValues0(int i)
        {
            std::vector<T> values;
            for (int j = 0; j < m_w; j++)
            {
                for (int k = 0; k < m_d; k++)
                {
                    values.push_back(getValue(i, j, k));
                }
            }
            return values;
        }

        void setValues0(int i, T value)
        {
            for (int j = 0; j < m_w; j++)
            {
                for (int k = 0; k < m_d; k++)
                {
                    setValue(value, i, j, k);
                }
            }
        }

        std::vector<T> getValues1(int i)
        {
            std::vector<T> values;
            for (int j = 0; j < m_h; j++)
            {
                for (int k = 0; k < m_d; k++)
                {
                    values.push_back(getValue(j, i, k));
                }
            }
            return values;
        }

        void setValues1(int i, T value)
        {
            for (int j = 0; j < m_h; j++)
            {
                for (int k = 0; k < m_d; k++)
                {
                    setValue(value, j, i, k);
                }
            }
        }

        std::vector<T> getValues2(int i)
        {
            std::vector<T> values;
            for (int j = 0; j < m_h; j++)
            {
                for (int k = 0; k < m_w; k++)
                {
                    values.push_back(getValue(j, k, i));
                }
            }
            return values;
        }

        void setValues2(int i, T value)
        {
            for (int j = 0; j < m_h; j++)
            {
                for (int k = 0; k < m_w; k++)
                {
                    setValue(value, j, k, i);
                }
            }
        }

        std::vector<T> getValues01(int i, int j)
        {
            std::vector<T> values;
            for (size_t k = 0; k < m_d; k++)
            {
                values.push_back(getValue(i, j, k));
            }

            return values;
        }

        void setValues01(int i, int j, T value)
        {
            for (size_t k = 0; k < m_d; k++)
            {
                setValue(value, i, j, k);
            }
        }

        std::vector<T> getValues02(int i, int j)
        {
            std::vector<T> values;
            for (size_t k = 0; k < m_w; k++)
            {
                values.push_back(getValue(i, k, j));
            }

            return values;
        }

        void setValues02(int i, int j, T value)
        {
            for (size_t k = 0; k < m_w; k++)
            {
                setValue(value, i, k, j);
            }
        }

        std::vector<T> getValues12(int i, int j)
        {
            std::vector<T> values;
            for (size_t k = 0; k < m_h; k++)
            {
                values.push_back(getValue(k, i, j));
            }

            return values;
        }

        void setValues12(int i, int j, T value)
        {
            for (size_t k = 0; k < m_h; k++)
            {
                setValue(value, k, i, j);
            }
        }

        static Array3d<T> CreateFill(int h, int w, int d)
        {
            int count = 0;
            Array3d<T> arr(h, w, d);
            for (int i = 0; i < h; i++)
            {
                for (int j = 0; j < w; j++)
                {
                    for (int k = 0; k < d; k++)
                    {
                        arr.setValue(count, i, j, k);
                        count++;
                    }
                }
            }

            return arr;
        }
    };
}