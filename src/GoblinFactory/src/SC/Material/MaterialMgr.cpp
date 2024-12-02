
#include <deque>

#include <Material/MaterialMgr.hpp>
#include <Manager/TxToTextFileStrategy.hpp>
#include <Material/Material.hpp>
#include <Data/Serializable.hpp>

MaterialMgr* MaterialMgr::_instance = nullptr;

MaterialMgr::MaterialMgr()
{}

MaterialMgr* MaterialMgr::GetInstance()
{
    if (_instance == nullptr)
    {
        _instance = new MaterialMgr();

        std::string Directory = "SC";
        std::string Filename = "Materials.txt";

        TxToTextFileStrategy<Material> TxStrat = TxToTextFileStrategy<Material>(Directory,
                                                                                Filename);
        _instance->SetTxStrategy(TxStrat);

    }

    return _instance;
}


