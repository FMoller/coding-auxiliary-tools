// TextBoxingCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

std::string boxing(std::string text) {
    int text_len = text.size();
    std::string new_string = "\xBA", top_row = "\xC9", down_row = "\xC8";
    int max_len = 0, act_len = 0;
    for (int i = 0; i < text_len; i++) {
        if (text[i] == '\t') {
            act_len += 8-( act_len % 8);
        }
        else {
            if (text[i] == '\n') {
                if (act_len > max_len) {
                    max_len = act_len;
                }
                act_len = 0;
            }
            else {
                act_len += 1;
            }
        }
    }
    if (act_len > max_len) max_len = act_len;
    act_len = 1;
    for (int i = 0; i < text_len; i++) {
        if (text[i] == '\n') {
            while (act_len <= max_len) {
                new_string += ' ';
                act_len++;
            }
            new_string += "\xBA\n\xBA";
            act_len = 1;
        }
        else {
            if (text[i] == '\t') {
                act_len += 8 - (act_len % 8);
                new_string += '\t';
            }
            else {
                new_string = new_string + text[i];
                act_len++;
            }
        }
        
    }
    while (act_len <= max_len) {
        new_string += ' ';
        act_len++;
    }
    new_string += "\xBA";
    for (int i = 0; i < max_len; i++) {
        top_row += '\xCD';
        down_row += '\xCD';
    }
    top_row += '\xBB';
    down_row += '\xBC';

    return top_row+'\n'+new_string+'\n'+down_row;
}

int main()
{
    std::string text, text2, text3;
    text = "This is some text to be boxed. \n \t\t we expect the boxing box the thing to be boxed.\n I hope it works.\n\n But I do not believe it";
    text2 = "oito";
    text3 = "0123456789012345678901234567890123456789\n0\t1\n00\t1";
    std::cout << boxing(text3);
    //std::cout << text3;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
