#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string extract_substring(const string& sentence, int start_index, int end_index){
//Best case: if the start index is greater than the end index, return an emoty string
if (start_index > end_index){
    return "";
}
//Create a string stream to split the sentence into words
istringstream iss(sentence);
vector<string>words;
string word;
while (iss >> word){
    words.push_back(word);
}

//if the start index is 0, return the words from start to end
if (start_index == 0){
    string result;
    for (int i = 0; i <= end_index; i++){
        result += words[i] + "";
    }
    return result.substr(0, result.length() - 1);
}

//Recursive case: Skip the first word and recurse with the remaining sentence
string remaining_sentence;
for (int i = 1; i < words.size(); i++){
    remaining_sentence += words[i] + "";
}
return extract_substring(remaining_sentence, start_index - 1, end_index - 1);
}

int main()
{
    string original_sentence = "The quick brown fox jumps over the lazy dog.";
    int start_index = 3;
    int end_index = 5;
    string new_sentence = extract_substring(original_sentence, start_index, end_index);
    cout << new_sentence << endl;
    return 0;
}
