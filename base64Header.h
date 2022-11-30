#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
#define BIT_8 8
#define BIT_6 6
using std::string;
using std::vector;

//Base 64 table, as it cant be imported
static vector<char> base64Table = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/' };

//side function, convert from ascii to binary
string a_2_b(int asc);

//convert from binary to Base64 index
int b_Base64(string& str);

//side function, convert input to binary
string str_to_bin(string& str);
 
//main encrypting function
string base64(string& exp);
