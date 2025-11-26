#ifndef SETTLMENT_H
#define SETTLMENT_H

#include <iostream>
#include <string>

using namespace std;

class Settlement {
private:
    string name = "";
    string county = "";
    int population = 0;

public:
    // Constructor
    Settlement(string name, string county, int pop)
        : name(name), county(county), population(pop) {}

    // Getters
    string getName() const { return name; }
    string getCounty() const { return county; }
    int getPopulation() const { return population; }

    // Setters
    void setName(const string& n) { name = n; }
    void setCounty(const string& c) { county = c; }
    void setPopulation(int p) { population = p; }

    // Inserter operator (for easy printing)
    friend ostream& operator<<(ostream& os, const Settlement& s) {
        os << "Settlement: " << s.name 
           << ", County: " << s.county 
           << ", Population: " << s.population;
        return os;
    }
};

#endif
