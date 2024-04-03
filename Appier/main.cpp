#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
#include <set>
#include <cctype>
#include <type_traits>

using namespace std;

template <typename T>
string mostFrequentWord(T text)
{
    // Convert the input to a string if it's a vector of characters
    string str = (is_same<T, vector<char>>::value) ? string(text.begin(), text.end()) : text;

    // convert str to lowercase
    for (int i = 0; i < str.size(); i++)
    {
        str[i] = tolower(str[i]);
    }

    // check if the str is empty or does not contain any of the characters in 'appier'
    if (str.empty() || str.find_first_of("appier") == string::npos)
    {
        return "No word found or does not contain any of the characters in 'appier'";
    }

    // split the str into words using stringstream
    stringstream ss(str);
    string word;
    set<string> uniqueWords;
    while (ss >> word)
    {
        uniqueWords.insert(word);
    }

    // create a map to store the frequency of each word using the uniqueWords set and the count STL algorithm
    map<string, int> wordFrequency;
    for (const auto &uniqueWord : uniqueWords)
    {
        stringstream ss(str);
        string word;
        int count = 0;
        while (ss >> word)
        {
            if (word == uniqueWord)
            {
                count++;
            }
        }
        wordFrequency[uniqueWord] = count;
    }

    // find the most frequent word using the max_element STL algorithm
    auto mostFrequent = max_element(wordFrequency.begin(), wordFrequency.end(), [](const pair<string, int> &a, const pair<string, int> &b)
                                    { return a.second < b.second; });

    return mostFrequent->first;
}

// main function to test the mostFrequentWord function
int main()
{
    string text = "This text should pass because it contains the character 'a, i, e, r & p' from the word 'appier'. The most frequent word is the and it should be returned.";
    string text2 = "not found";
    string text3 = "";

    cout << mostFrequentWord(text) << endl;
    cout << mostFrequentWord(text2) << endl;
    cout << mostFrequentWord(text3) << endl;

    return 0;
}

string mostFrequentWord(string text)
{
    // convert text to lowercase
    for (int i = 0; i < text.size(); i++)
    {
        text[i] = tolower(text[i]);
    }

    // check if the text is empty or does not contain any of the characters in 'appier'
    if (text.empty() || text.find_first_of("apier") == string::npos)
    {
        return "No word found or does not contain any of the characters in 'appier'";
    }

    // split the text into words using stringstream and saving the unique ones in a set
    stringstream ss(text);
    string word;
    set<string> uniqueWords;
    while (ss >> word)
    {
        uniqueWords.insert(word);
    }

    // create a map to store the frequency of each word using the uniqueWords set and a counter
    map<string, int> wordFrequency;
    for (const auto &uniqueWord : uniqueWords)
    {
        stringstream ss(text);
        string word;
        int count = 0;
        while (ss >> word)
        {
            if (word == uniqueWord)
            {
                count++;
            }
        }
        wordFrequency[uniqueWord] = count;
    }

    // find the most frequent word using the max_element STL algorithm
    auto mostFrequent = max_element(wordFrequency.begin(), wordFrequency.end(), [](const pair<string, int> &a, const pair<string, int> &b)
                                    { return a.second < b.second; });

    return mostFrequent->first;
}

string mostFrequentWord(vector<char> textArray)
{
    // Convert the array of characters to a string
    string text(textArray.begin(), textArray.end());

    // convert text to lowercase
    for (int i = 0; i < text.size(); i++)
    {
        text[i] = tolower(text[i]);
    }

    // check if the text is empty or does not contain any of the characters in 'appier'
    if (text.empty() || text.find_first_of("apier") == string::npos)
    {
        return "No word found or does not contain any of the characters in 'appier'";
    }

    // split the text into words using stringstream and saving the unique ones in a set
    stringstream ss(text);
    string word;
    set<string> uniqueWords;
    while (ss >> word)
    {
        uniqueWords.insert(word);
    }

    // create a map to store the frequency of each word using the uniqueWords set and a counter
    map<string, int> wordFrequency;
    for (const auto &uniqueWord : uniqueWords)
    {
        stringstream ss(text);
        string word;
        int count = 0;
        while (ss >> word)
        {
            if (word == uniqueWord)
            {
                count++;
            }
        }
        wordFrequency[uniqueWord] = count;
    }

    // find the most frequent word using the max_element STL algorithm
    auto mostFrequent = max_element(wordFrequency.begin(), wordFrequency.end(), [](const pair<string, int> &a, const pair<string, int> &b)
                                    { return a.second < b.second; });

    return mostFrequent->first;
}