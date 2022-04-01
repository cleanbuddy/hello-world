//Given a vector, v, where each element of the vector is a (name, grade) pair, 
//sorts the vector by name and partitions the first half of the vector as pairs who 
//passed, and the second half of the vector as pairs who failed.

//A pair “passes” if the grade is greater than or equal to 600 points.

#include <iostream>
using std::cin; using std::cout; using std::endl; using std::pair;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
using std::copy_if;
#include <iterator>
using std::back_inserter;

bool Fail(pair<string, int> & v)
{
    if (v.second < 600)
    {
        cout << v.first << " fails! score: " << v.second << endl;
        return true;
    }
    return false;
}

bool Pass(pair<string, int> & v)
{
    if (v.second >= 600)
    {
        cout << v.first << " passes! score: " << v.second << endl;
        return true;
    }
    return false;
}

vector<pair<string, int>> PassFail(vector<pair<string, int>> & v)
{
    vector<pair<string, int>> passes;
    vector<pair<string, int>> fails;

    copy_if(v.begin(), v.end(), back_inserter(passes), Pass);
    copy_if(v.begin(), v.end(), back_inserter(fails), Fail);

    sort(passes.begin(), passes.end());
    sort(fails.begin(), fails.end());

    vector<pair<string, int>> final;
    copy(passes.begin(), passes.end(), back_inserter(final));
    copy(fails.begin(), fails.end(), back_inserter(final));

    return final;
}

int main()
{
    vector<pair<string, int>> input = {{"josh", 851}, {"mark", 600}, {"charles", 412}, {"sebnem", 1000}, {"abdol", 905}, {"imen", 300}};
    vector<pair<string, int>> final = PassFail(input);
    cout << "final: " << endl;
    for (auto e: final)
    {
        cout << e.first << ": " << e.second << endl;
    }
    return 0;
}