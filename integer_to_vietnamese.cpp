#include <iostream>
using namespace std;

string intToVietnamese(long num)
{
    if (num == 0)
        return "khong";
    string digitToText[10] = {"không", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};
    string units[5] = {"", "nghin", "trieu", "ti", "nghin ti"}; // can add more
    string text = "";
    int unitCnt = 0;
    while (num > 0)
    {
        string threeDigits = "";
        int block = num % 1000;
        int temp = num;
        num /= 1000;
        if (block != 0)
        {
            int donvi = block % 10;
            int chuc = (block % 100) / 10;
            int tram = block / 100;
            // hang tram
            if (tram == 0)
            {
                if (temp >= 1000)
                    threeDigits += "khong tram";
            }
            else
                threeDigits += digitToText[tram] + " tram";

            // hang chuc
            if (chuc > 1)
                threeDigits += (" " + digitToText[chuc] + " muoi");
            else if (chuc == 1)
                threeDigits += " muoi";
            else if (donvi > 0)
            {
                if (tram == 0)
                {
                    if (temp >= 1000)
                        threeDigits += " le";
                }
                else
                    threeDigits += " le";
            } // (chuc = 0)

            // don vi
            if (donvi > 0)
            {
                threeDigits += (donvi == 5 && chuc != 0) ? " lam" : (" " + digitToText[donvi]);
            }
            if (unitCnt > 0)
            {
                text = units[unitCnt] + " " + text;
            }
            text = threeDigits + " " + text;
        }
        unitCnt++;
    }
    if (text.back() == ' ')
        text.pop_back();
    if (text.front() == ' ')
        text.erase(0, 1);

    return text;
}

int main()
{
    long num;
    cin >> num;
    cout << intToVietnamese(num);
}