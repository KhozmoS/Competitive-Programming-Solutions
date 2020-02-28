#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e4 + 5;
//7 3 2 2 3 2

int w , h , sx , sy , ex , ey;
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>w>>h>>sx>>sy>>ex>>ey;

    int asx , asy , aex , aey;

    if(sx != ex)
    {
      asy = 0;
      asx = sx;
      aey = h - 1;
      aex = ex;
    }
    else
    {
      asy = sy;
      asx = 0;
      aex = w - 1;
      aey = ey;
    }

    cout<<asx<<" "<<asy<<" "<<aex<<" "<<aey<<"\n";

    return 0;
}
