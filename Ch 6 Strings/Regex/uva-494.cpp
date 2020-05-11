//UVa 494 - Kindergarten Counting Game
//Count no. of words in a sentence using regex iterator

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    string sentence;                //For taking input each sentence

    //Define the pattern we need to match
    regex word{ "[a-zA-Z]+" }; 

    //Get input line by line
    while( getline( cin, sentence ) )
    {
        //Valid regex_iterator
        auto words_begin = sregex_iterator( sentence.begin(), sentence.end(), word );

        //Default-constructed regex_iterator is end-of-sequence iterator
        auto words_end   = sregex_iterator();

        //Valid regex_iterator becomes equal to end-of-sequence iterator
        //when it is incremented after reaching the last match
        cout << distance(words_begin, words_end) << '\n';
    }
}