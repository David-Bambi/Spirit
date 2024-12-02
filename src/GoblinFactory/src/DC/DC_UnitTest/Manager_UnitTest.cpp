#include <gtest/gtest.h>

#include <../Data/DInt.hpp>
#include <../Manager/Manager.hpp>
#include <../Manager/TxStrategy.hpp>
#include <../Manager/TxToTextFileStrategy.hpp>

TEST(ManagerTest, GetDataSet) 
{
    std::string Filename = "ManagerTest.txt";
    std::string Directory = "Test_Manager";

    TxStrategy<DInt>* TxStrat = new TxToTextFileStrategy<DInt>(Directory,
                                                               Filename);

    Manager<DInt>* MgrSave = new Manager<DInt>();
    MgrSave->SetTxStrategy(*TxStrat);

    MgrSave->DataSet().insert(new DInt(4));
    MgrSave->Save();

    Manager<DInt>* MgrLoad = new Manager<DInt>();
    MgrLoad->SetTxStrategy(*TxStrat);
    MgrLoad->Load();

    EXPECT_EQ(MgrLoad->DataSet().size(), 1);
}

TEST(ManagerTest, GetDataSetWithoutStrategy) 
{
    Manager<DInt>* MgrSave = new Manager<DInt>();

    MgrSave->DataSet().insert(new DInt(4));
    MgrSave->Save();

    EXPECT_EQ(MgrSave->DataSet().size(), 1);
}
