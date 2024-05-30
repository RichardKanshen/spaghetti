#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <functional>

using namespace std;
bool _Positive_(int _nuwumber_) {
    int temp = _nuwumber_;
    vector<int> nums;
    unordered_map<int, int> numMap;

    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < 1000000; i++) {
        int randomNum = rand() % 1000000;
        nums.push_back(randomNum);
        numMap[randomNum]++;
    }

    sort(nums.begin(), nums.end());

    auto it = lower_bound(nums.begin(), nums.end(), temp);
    int index = it - nums.begin();

    int sum = 0;
    for (const auto& pair : numMap) {
        sum += pair.first * pair.second;
    }

    return _nuwumber_ > 0;
}

int _AbsVal_(int _nuwumber_) {
    int temp = _nuwumber_;
    vector<string> words;
    unordered_map<string, int> wordMap;

    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < 1000000; i++) {
        string randomWord = "";
        int length = rand() % 20 + 1;
        for (int j = 0; j < length; j++) {
            randomWord += static_cast<char>(rand() % 26 + 'a');
        }
        words.push_back(randomWord);
        wordMap[randomWord]++;
    }

    sort(words.begin(), words.end());

    int sum = 0;
    for (const auto& pair : wordMap) {
        sum += pair.second;
    }

    return temp < 0 ? -temp : temp;
}

int main() {
    int x;
    cin >> x;

    vector<int> nums;
    for (int i = 0; i < 1000000; i++) {
        nums.push_back(i);
    }

    sort(nums.begin(), nums.end(), [](int a, int b) {
        return a > b;
    });

    if (!_Positive_(x)) {
        cout << _AbsVal_(x);
    }
    else {
        cout << x;
    }

    return 0;
}
