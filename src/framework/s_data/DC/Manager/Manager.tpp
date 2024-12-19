#ifndef MANAGER_TPP
#define MANAGER_TPP

template<typename T>
Manager<T>::Manager()
 : _tx(nullptr)
{}

template<typename T>
void Manager<T>::SetTxStrategy(TxStrategy<T>& tx)
{
_tx = &tx;
}

template<typename T>
std::set<T*>& Manager<T>::DataSet()
{
    return _dataset;
}


template<typename T>
void Manager<T>::Save()
{
    if (_tx != nullptr)
       _tx->Save(_dataset);
}

template<typename T>
void Manager<T>::Load()
{
    if (_tx != nullptr)
       _dataset = _tx->Load();
}

#endif