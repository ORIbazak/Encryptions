#include "base64Header.h"


string a_2_b(int asc)
{
    string str;
    while (asc > 0)
    {
        if (asc % 2 == 0)
        {
            str += '0';
        }
        else
        {
            str += '1';
        }
        asc /= 2;
    }
    while (str.size() != BIT_8)
    {
        str += '0';
    }
    return str;
}
int b_Base64(string& str)
{
    int asc = 0;
    std::reverse(str.begin(), str.end());
    for (int i = 0; i < str.size(); i++)
    {
        int val = str[i] - '0';
        int pow = val * std::pow(2, i);
        asc += pow;
    }

    return asc;
}
string str_to_bin(string& str)
{

    string longstr;
    for (int i = 0; i < str.size(); i++)
        
    {
        int val = str[i];
        string bin = a_2_b(val);
        std::reverse(bin.begin(), bin.end());
        longstr += bin;



    }

    return longstr;
}
string base64(string& exp)
{
    string merge = str_to_bin(exp);

    vector<string> v;
    int len = merge.size();
    for (int i = 0; i < len / BIT_6; i++)
    {
        string str;
        int k = (i) * 6;
        for (int j = k; j < k + 6; j++)
        {
            str += merge[j];
        }
        v.push_back(str);
    }

    if (len % 6 != 0)
    {
        string s;
        for (int i = len - len % BIT_6; i < len; i++)
        {
            s += merge[i];
        }
        while (s.size() != BIT_6)
        {
            s += '0';
        }
        v.push_back(s);
    }




    string crypted;
    for (string str : v)
    {
        int base_val = b_Base64(str);
        char c = base64Table[base_val];
        crypted += c;
    }
    while (crypted.size() % 4 != 0)
    {
        crypted += '=';
    }
    return crypted;

}
