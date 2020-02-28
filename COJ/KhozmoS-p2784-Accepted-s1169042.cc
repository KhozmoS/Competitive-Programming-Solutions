#include <bits/stdc++.h>


using namespace std;

#define x first
#define y second
typedef unsigned long long ll;
typedef pair <ll , ll> Point;

bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}

vector <Point> v;
int orientation(Point p, Point q, Point r)
{
    v.push_back(p);
    v.push_back(q);
    v.push_back(r);

    sort(v.begin() , v.end());

    // See http://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    long long val = ll(q.y - p.y) * ll(r.x - q.x) -
              ll(q.x - p.x) * ll(r.y - q.y);

    if (val == 0) return 0ll;  // colinear

    return (val > 0)? 1ll: 2ll; // clock or counterclock wise
}
bool intersects(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    ll o1 = orientation(p1, q1, p2);
    ll o2 = orientation(p1, q1, q2);
    ll o3 = orientation(p2, q2, p1);
    ll o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}
int ar[10000000];
int main()
{
    int n;
    cin>>n;
    for(int i = 1 ; i <= n ; i++)
        cin>>ar[i];
    sort(ar+ 1 , ar+1+n);
    cout<<ar[n]<<" ";
    for(int i = 1; i < n ; i++)
        cout<<ar[i]<<" ";
}
