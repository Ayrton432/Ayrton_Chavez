#include <iostream>
#include <string>

using namespace std;

int main() {
    int n1 = 232168;
    double n2 = 0.0000000000000000000001;
    double n3 = 4.5353546;

    string num_str1(to_string(n1));
    string num_str2(to_string(n2));
    string num_str3(to_string(n3));

    cout << num_str1 << endl;
    cout << num_str2 << endl;
    cout << num_str3 << endl;

    return 0;
}
