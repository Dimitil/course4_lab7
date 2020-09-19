#pragma once
template <typename T>
void Swap(T& a, T& b)
{
	if (&a == &b) return;
	T tmp(std::move(a));
	a = std::move(b);
	b = std::move(tmp);
}

template <typename T, const size_t capacity>
class MyStack {

	T m_pData[capacity];
	size_t m_size = 0;

public:

	void push(const T& t)
	{
		if (m_size == capacity)
		{
			throw std::exception();
		}

		m_pData[m_size] = T(t);
		++m_size;
	}

	T pop()
	{
		if (m_size == 0)
		{
			throw std::exception();
		}
		--m_size;

		return m_pData[m_size];
	}

	T& operator[](unsigned int q)
	{
		if ((q >= m_size) || (q < 0))
		{
			throw std::exception();
		}
		return m_pData[q];
	}

	const T& operator[](unsigned int q) const
	{
		return m_pData[q];
	}
};