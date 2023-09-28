#include<iostream>
using namespace std;

int main()
{
    bool once = true;

    while (true)
    {
        if (!once){
            cout<<"continue next F: (1-continue, 0-over)";
            bool exist;
            cin>>exist;
            if (!exist) break;
        }

        once = false;

        cout<<"input F face: (1-OK, 0-NG)";
        bool yz;
        cin>>yz;
        if (yz)
        {
            cout<<"upgrade OK\n";
            continue;
        }

        cout<<"input F body: (1-OK, 0-NG)";
        bool sc;
        cin>>sc;
        if (sc) cout << "upgrade OK\n";
    }

    return 0;
}