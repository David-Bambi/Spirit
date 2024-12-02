#include <gtest/gtest.h>

#include <set>
#include <string>
#include <algorithm>

#include <../Data/DInt.hpp>
#include <../Manager/TxStrategy.hpp>
#include <../Manager/TxToTextFileStrategy.hpp>

TEST(TxToTextFileStrategy, SaveAndLoad) 
{
    std::set<DInt*> DIntDataSet;

    DIntDataSet.insert(new DInt(4));
    DIntDataSet.insert(new DInt(5));
    DIntDataSet.insert(new DInt(25));

    std::string Directory = "Test_TxStrat";
    std::string Filename = "TxToTextFile.txt";

    TxToTextFileStrategy<DInt> TxStrat = TxToTextFileStrategy<DInt>(Directory,
                                                                    Filename);
    TxStrat.Save(DIntDataSet); 

    std::set<DInt*> DIntDataSetLoaded;
    DIntDataSetLoaded = TxStrat.Load();

    std::vector<DInt*> DIntDataVec(DIntDataSet.begin(), DIntDataSet.end());
    std::vector<DInt*> DIntDataVecLoaded(DIntDataSetLoaded.begin(), DIntDataSetLoaded.end());

    auto SortLambda =  [] (const DInt* a, const DInt* b) 
    {
        return *a < *b;
    };

    auto CompareLambda =  [] (const DInt* a, const DInt* b) 
    {
        return *a == *b;
    };

    std::sort(DIntDataVec.begin(), DIntDataVec.end(), SortLambda);
    std::sort(DIntDataVecLoaded.begin(), DIntDataVecLoaded.end(), SortLambda);

    EXPECT_TRUE(std::equal(DIntDataVec.begin(), 
                           DIntDataVec.end(), 
                           DIntDataVecLoaded.begin(), 
                           CompareLambda)); 
}

TEST(TxToTextFileStrategy, AppendMode) 
{
    std::set<DInt*> DIntDataSet;
    DIntDataSet.insert(new DInt(4));

    std::string Directory = "Test_TxStrat";
    std::string Filename = "TxToTextFile.txt";

    TxToTextFileStrategy<DInt> TxStrat = TxToTextFileStrategy<DInt>(Directory,
                                                                    Filename);
    TxStrat.Save(DIntDataSet);

    std::set<DInt*> DIntDataSetLoaded;
    DIntDataSetLoaded = TxStrat.Load();

    EXPECT_EQ(DIntDataSetLoaded.size(), DIntDataSet.size());

    TxToTextFileStrategy<DInt> TxStratAppend = TxToTextFileStrategy<DInt>(Directory,
                                                                          Filename,
                                                                          ios_base::app);
    TxStratAppend.Save(DIntDataSet);
    std::set<DInt*> DIntDataSetLoadedAppend;
    DIntDataSetLoadedAppend = TxStratAppend.Load();

    EXPECT_NE(DIntDataSetLoadedAppend.size(), DIntDataSet.size());
    EXPECT_EQ(DIntDataSetLoadedAppend.size(), 2);
}
