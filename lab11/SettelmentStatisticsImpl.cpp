#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <set>
#include "Settlment.h"
#include "SettlmentStatisticsImpl.h"


void SettelmentStatisticsImpl::readFromFile(string filename){
    ifstream f(filename);
    if(!f){
        cout<<"HIBA A BEMENETBEN"<<endl;
        return;
    }
    
    string line;
    getline(f,line);
    while (getline(f,line)){
        //cout<<line<<endl;
        stringstream item(line);
        string name, county, populationstr;
        getline(item,name,',');
        getline(item,county,',');
        getline(item,populationstr);

        stringstream conv(populationstr);
        int population;
        conv>>population;
        this->settelments.insert({county, Settlement(name, county, population)});
    }
    
}

int SettelmentStatisticsImpl::numCounties() const{
    set<string> counties;
    for(auto it=settelments.begin(); it!=settelments.end(); it++){
        counties.insert(it->first);
    }
    return counties.size();
}       

int SettelmentStatisticsImpl::numSettlementsByCounty(const string& county) const {
    auto range = settelments.equal_range(county);
    int count=0;

    for(auto it = range.first; it!=range.second; it++){
        count++;
    }
    return count;
}

vector<Settlement> SettelmentStatisticsImpl::findSettlementsByCounty(const string& county) const{
    auto range = settelments.equal_range(county);
    vector<Settlement> to_rtrn;

    for(auto it = range.first; it!=range.second; it++){
       to_rtrn.push_back(it->second);
    }

    return to_rtrn;
}

Settlement SettelmentStatisticsImpl::findSettlementsByNameAndCounty(const string& name, const string& county) const{
   auto range = settelments.equal_range(county);

    for (auto it = range.first; it != range.second; ++it) {
        if (it->second.getName() == name) {
            return it->second;
        }
    }
    return Settlement("", "", 0);
}


Settlement SettelmentStatisticsImpl::maxPopulationBySettlement() const{
    Settlement maxSettle("", "", 0);
    for(auto it=settelments.begin(); it!=settelments.end(); it++){
        if(it->second.getPopulation()>maxSettle.getPopulation()){
            maxSettle=it->second;
        }
    }
    return maxSettle;
}

Settlement SettelmentStatisticsImpl::minPopulationBySettlement() const{
    Settlement minSettle("", "", 0);
    for(auto it=settelments.begin(); it!=settelments.end(); it++){
        if(it->second.getPopulation()<maxSettle.getPopulation()){
            maxSettle=it->second;
        }
    }
    return minSettle;
}

vector<Settlement> SettelmentStatisticsImpl::findSettlementsByName(const string& name){
      vector<Settlement> result;

    // végigmegyünk az összes településen a multimap-ben
    for (const auto& pair : settelments) {
        if (pair.second.getName() == name) {
            result.push_back(pair.second);
        }
    }

    return result;vector<Settlement> result;

    for (const auto& pair : settelments) {
        if (pair.second.getName() == name) {
            result.push_back(pair.second);
        }
    }

    return result;
}