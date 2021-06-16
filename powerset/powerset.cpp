
#include <iostream>
#include <vector>

static std::vector<int> vec;
int count = 1;
constexpr int upToWhat = 3;

void powerSet(int i, bool consider) {
    if (consider && i != 0) vec.push_back(i);
    if (i == upToWhat) {
        for (int j = 0; j < vec.size(); j++) {                  //this does the executions that you would draw out in a power set flow chart, thus
            if (j == vec.size() - 1) {                          //thus making recursion the right tool for the job.
                std::cout << vec[j] << "\t\t" << count++;
            }
            else {
                std::cout << vec[j] << ", ";
            }
        }
        std::cout << '\n';
        return;
    }
    powerSet(i + 1, true);
    vec.pop_back();
    powerSet(i + 1, false);
}

int main()
{
    std::cout << "\t\t" << count++ << '\n';
    powerSet(0, true);
}
