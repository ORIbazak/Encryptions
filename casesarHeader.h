#pragma once
#include <iostream>
#include <vector>
#include<string>
using std::string;
using std::vector;

//arr of letters, used for swapping letters via index
static vector<char> letters = { 'A','B','C','D','E','F','G','H','i','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };


//get index of char in letters arr
int getIndexOf(char& c);


//map the encryption key so it can be used per index 
vector<int> key_arr(string key);


//main encrypting function
void encrypt(string str);

