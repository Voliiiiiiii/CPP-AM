#ifndef SETTLMENTSTATISTICSIMPL_H
#define SETTLMENTSTATISTICSIMPL_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Settlment.h"
#include "SettlmentStatistics.h"

using namespace std;




class SettelmentStatisticsImpl:public SettlementStatistics{
    multimap<string, Settlement>settelments;
    void readFromFile(string filename);
public:
    SettelmentStatisticsImpl(){
        readFromFile("telepulesek.csv");
    }
    int numSettlements() const override{ return settelments.size();}
    int numCounties() const override;
    int numSettlementsByCounty(const string& county) const override;
    vector<Settlement> findSettlementsByCounty(const string& county) const override;
    Settlement findSettlementsByNameAndCounty(const string& name, const string& county) const override;
    Settlement maxPopulationBySettlement() const override;
    Settlement minPopulationBySettlement() const override;
    vector<Settlement> findSettlementsByName(const string& name) override;
};

#endif