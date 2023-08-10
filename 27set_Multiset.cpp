#include<bits/stdc++.h>
using namespace std;

int32_t main()
{
    // No duplicate element(SET)
    // set<int> s;
    // s.insert(1);
    // s.insert(2);
    // s.insert(2);
    // s.insert(3);

    // // print n reverse
    // for(auto i = s.rbegin(); i != s.rend(); i++)
    //     cout<<*i<< " ";
    // cout<<"\n";

    // cout<<s.size()<<endl;

    // set<int, greater<int>> s;
    // s.insert(1);
    // s.insert(2);
    // s.insert(2);
    // s.insert(3);
    // for(auto i: s){
    //     cout<<i<<" ";
    // }

    set<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(2);
    s.insert(4);
    s.insert(5);

    //lower_bound = returns an iterator pointing to the first element in the set that is not less than a specified value. If the specified value is already present in the set, the iterator will point to that element.

    //upper_bound = returns an iterator pointing to the first element in the set that is greater than a specified value. If no element is greater than the specified value, it returns an iterator to the end of the set
    // cout<<*s.lower_bound(2)<<endl;
    // cout<<*s.lower_bound(3)<<endl;
    // cout<<*s.upper_bound(3)<<endl;
    // cout<<(s.upper_bound(5)==s.end())<<endl;

    // s.erase(2);
    // s.erase(s.begin());
    // for(auto i : s)
    //     cout<<i<<' ';

    //duplicate element(MULTISET)
    multiset<int> ms;
    ms.insert(1);
    ms.insert(3);
    ms.insert(3);
    ms.insert(3);
    ms.insert(4);

    // ms.erase(3);//it will remove all 3
    ms.erase(ms.find(3));
    for(auto i: ms){
        cout<<i<<" ";
    }

    return 0;
}