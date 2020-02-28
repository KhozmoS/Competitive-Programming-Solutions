#include <bits/stdc++.h>


using namespace std;

#define EPS 1e-8
#define PI acos(-1)
#define Vector Point
#define all(a) a.begin() , a.end()

struct Point {
  long long x, y;
  Point(long long a , long long b){
        x = a;
        y = b;
  }
  Point(){}
};

//### FUNCIONES BASICAS
//#############################################################


// Heron triangulo y cuadrilatero ciclico
// http://mathworld.wolfram.com/CyclicQuadrilateral.html
// http://www.spoj.pl/problems/QUADAREA/

//### DETERMINA SI P PERTENECE AL SEGMENTO AB
//###########################################

bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;

    return false;
}


int orientation(Point p, Point q, Point r)
{
    // See http://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    long long val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear

    return (val > 0)? 1: 2; // clock or counterclock wise
}
bool intersects(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

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

int main()
{
    int t;
    cin>>t;
    Point a , b , top_left , bottom_right , c , d;
    long long _1 , _2 , _3 , _4 , _5 , _6 , _7 , _8;
   // cin>>a.x>>a.y>>b.x>>b.y;
    //cin>>c.x>>c.y>>d.x>>d.y;
    //cout<<intersects(a , b , c , d);
    while(t--){
    cin>>_1 >> _2 >> _3 >> _4 >> _5 >> _6 >> _7 >> _8;

    a = Point(_1 , _2);
    b = Point(_3 , _4);
    top_left = Point(_5 , _6);
    bottom_right = Point(_7 , _8);
    
    if(top_left.x > bottom_right.x)
        swap(top_left , bottom_right);
    if(top_left.y < bottom_right.y)
        swap(top_left , bottom_right);
    if(top_left.y >= bottom_right.y && top_left.x <= bottom_right.x){    
        if(a.x >= top_left.x && a.x <= bottom_right.x && a.y <= top_left.y && a.y >= bottom_right.y)
        {
            cout<<"T\n";
            continue;
        }
    }
    else{
        if(top_left.x > bottom_right.x)
            swap(top_left , bottom_right);
        if(top_left.y > bottom_right.y)
            swap(top_left , bottom_right);
        if(a.x >= top_left.x && a.x <= bottom_right.x && a.y >= top_left.y && a.y <= bottom_right.y)
        {
            cout<<"T\n";
            continue;
        }    
    }
    if(intersects(a , b , top_left , Point(bottom_right.x , top_left.y)))
        cout<<"T\n";
    else if(intersects(a , b , top_left , Point(top_left.x , bottom_right.y)))
        cout<<"T\n";
    else if(intersects(a , b , bottom_right , Point(top_left.x , bottom_right.y)))
        cout<<"T\n";
    else if(intersects(a , b , bottom_right , Point(bottom_right.x , top_left.y)))
        cout<<"T\n";
    else
        cout<<"F\n";
    }

}
