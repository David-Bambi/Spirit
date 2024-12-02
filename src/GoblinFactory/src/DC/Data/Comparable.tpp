#ifndef COMPARABLE_TPP
#define COMPARABLE_TPP

template <typename T>
bool Comparable<T>::operator<(const T& other) const
{
    return CompareTo(other) < 0;
}

template <typename T>
bool Comparable<T>::operator>(const T& other) const
{
    return CompareTo(other) > 0;
}

template <typename T>
bool Comparable<T>::operator==(const T& other) const
{
    return CompareTo(other) == 0;
}

template <typename T>
bool Comparable<T>::operator<=(const T& other) const
{
    return CompareTo(other) <= 0;
}

template <typename T>
bool Comparable<T>::operator>=(const T& other) const
{
    return CompareTo(other) >= 0;
}

template <typename T>
bool Comparable<T>::operator!=(const T& other) const
{
    return CompareTo(other) != 0;
}


#endif