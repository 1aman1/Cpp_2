#include <vector>
#include <iostream>
#include <algorithm>

/*
to get all the positions for an element wherever it is present in vector
uses: find neighbours of a node in an adjacency matrix
*/

void locate_all_matches_in_vector(const std::vector<int> &v)
{
    int pos_1 = 0;
    int match = 1;

    auto itr_for_1 = std::find(v.begin() + pos_1, v.end(), match);

    while (itr_for_1 != v.end())
    {
        std::cout << itr_for_1 - v.begin();

        pos_1 += itr_for_1 - v.begin() + 1;

        itr_for_1 = std::find(v.begin() + pos_1, v.end(), match);

        std::cout << "working\n";
    }
}

int main()
{
    std::vector<int> v{0, 1, 0, 1};

    locate_all_matches_in_vector(v);

    return 0;
}