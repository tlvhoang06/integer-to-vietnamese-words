#include <iostream>
#include <string>
using namespace std;

string intToVietnamese(long num)
{
    if (num == 0)
        return "khong";

    const string digitToText[10] = {
        "khong", "mot", "hai", "ba", "bon",
        "nam", "sau", "bay", "tam", "chin"
    };

    const string units[5] = {
        "", "nghin", "trieu", "ti", "nghin ti"
    }; // can add more

    string result = "";
    int unitCnt = 0;

    while (num > 0)
    {
        int block = num % 1000;
        num /= 1000;

        if (block != 0)
        {
            int donvi = block % 10;
            int chuc  = (block % 100) / 10;
            int tram  = block / 100;

            string part = "";

            // Tram
            if (tram == 0) {
                if (num > 0) 
                    part += "khong tram";
            } else {
                part += digitToText[tram] + string(" tram");
            }

            // Chuc
            if (chuc > 1) {
                part += " " + digitToText[chuc] + " muoi";
            }
            else if (chuc == 1) {
                part += " muoi";
            }
            else if (donvi > 0) {
                part += " le";
            }

            // Donvi
            if (donvi > 0) {
                if (donvi == 5 && chuc != 0) 
                    part += " lam";
                else
                    part += " " + digitToText[donvi];
            }
            if (unitCnt > 0)
                result = units[unitCnt] + " " + result;

            result = part + " " + result;
        }
        unitCnt++;
    }
    
    if (!result.empty() && result.back() == ' ')
        result.pop_back();
    if (!result.empty() && result.front() == ' ')
        result.erase(0, 1);

    return result;
}

int main()
{
    long num;
    cin >> num;
    cout << intToVietnamese(num);
    return 0;
}
