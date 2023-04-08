#include <bits/stdc++.h>
using namespace std;

void removeSpecialCharacter(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] < 'A' || s[i] > 'Z' && s[i] < 'a' || s[i] > 'z')
        {
            // cout << i << " ";
            s.erase(i, 1);
            i--;
        }
    }
    cout<<s<<endl;
    string s1 = "";
    for (int i = 0; i <= s.size(); i++)
    {
        s1 = s1 + s[s.size()-i];
    }
    cout<<s1<<endl;

    if(s.compare(s1)==0){
        cout<<"T"<<endl;
    }
    else{
        cout<<"F"<<endl;
    }
}

int main()
{
    string s = "race a car";
    // string s = "A man, a plan, a canal: Panama";
    removeSpecialCharacter(s);
    // string str = "Journal Dev reverse example";
    // reverse(str.begin(), str.end());
    // cout<<"\n"<<str;
    return 0;
}
