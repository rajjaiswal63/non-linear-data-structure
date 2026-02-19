#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int minProdictSubset(vector<int>& v) {
    int cz = 0, cn = 0, cp = 0;
    int minPositive = INT_MAX;
    int proNeg = 1;
    int proPos=1;
    int maxNeg=INT_MIN;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == 0) {
            cz++;
        }

        if (v[i] > 0) {
            cp++;
            minPositive = min(minPositive, v[i]);
            proPos*=v[i];
        }

        if (v[i] < 0) {
            cn++;
            proNeg *= v[i];
            maxNeg=max(maxNeg,v[i]);
        }
    }

    if (cn == 0) {
        if (cz > 0)
            return 0;
        else
            return minPositive;
    } else {
        if (cn % 2 != 0) {
            return proNeg*proPos;
        }
        else return (proNeg/maxNeg)*proPos;
    }

    return 0; // fallback to avoid undefined behavior
}

int main() {
    vector<int>v={0,1,2,3};
    cout<<minProdictSubset(v);
    return 0;
}
