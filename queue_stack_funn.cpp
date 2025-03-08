#include <iostream>
#include <vector>

using namespace std;
class CountStudentsThatdontGetTheSandwichTheyWant {
    public:
        int countStudents(vector<int>& students, vector<int>& sandwiches) {
            int going_to_start_count = 0;
            while (!students.empty() || !sandwiches.empty()){
                if (students[0] == sandwiches[0]){
                    sandwiches.erase(sandwiches.begin());
                    students.erase(students.begin());
                    // because student count has reduced we should 
                    // start counting again
                    going_to_start_count=0;
                }else{
                    int temp = students[0];
                    students.erase(students.begin());
                    students.push_back(temp);
                    going_to_start_count++;
                }
                // >= because going_to_start_count is indexed from 0 
                // last valid index is size() - 1
                if (going_to_start_count >= students.size()){
                    break;
                }
            }
            return students.size();
        }
};

int main(void) {
    CountStudentsThatdontGetTheSandwichTheyWant counter;

    vector<int> students1 = {1, 1, 0, 0};
    vector<int> sandwiches1 = {0, 1, 0, 1};
    cout << "Test 1: " << counter.countStudents(students1, sandwiches1) << " (Expected: 0)" << endl;

    vector<int> students2 = {0, 0, 1, 1};
    vector<int> sandwiches2 = {0, 1, 0, 1};
    cout << "Test 2: " << counter.countStudents(students2, sandwiches2) << " (Expected: 0)" << endl;

    vector<int> students3 = {1, 1, 1, 1};
    vector<int> sandwiches3 = {0, 0, 0, 0};
    cout << "Test 3: " << counter.countStudents(students3, sandwiches3) << " (Expected: 4)" << endl;

    vector<int> students4 = {0};
    vector<int> sandwiches4 = {1};
    cout << "Test 4: " << counter.countStudents(students4, sandwiches4) << " (Expected: 1)" << endl;

    vector<int> students5 = {};
    vector<int> sandwiches5 = {0, 1};
    cout << "Test 5: " << counter.countStudents(students5, sandwiches5) << " (Expected: 0)" << endl;

    vector<int> students6 = {0, 1};
    vector<int> sandwiches6 = {};
    cout << "Test 6: " << counter.countStudents(students6, sandwiches6) << " (Expected: 2)" << endl;

    vector<int> students7 = {0, 0, 0, 0};
    vector<int> sandwiches7 = {0, 1, 1, 1};
    cout << "Test 7: " << counter.countStudents(students7, sandwiches7) << " (Expected: 3)" << endl;
    return 0;
}