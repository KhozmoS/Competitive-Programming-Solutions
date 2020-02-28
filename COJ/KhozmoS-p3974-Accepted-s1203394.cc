#include <bits/stdc++.h>

const double PI = acos( -1.0 );

struct point
{
    double x, y;
};

 point O;

 double Get_Dist( point &a, point &b )
 {
     return sqrt( (a.x - b.x)*(a.x - b.x) + (a.y - b.y )*(a.y - b.y) );
 }

 double Get_Angle( double a, double b, double c )
 {
     return acos( (b*b + c*c - a*a) / (2*b*c) );
 }

 bool check( point &m, point &n, double x, double y )
 {
     double minx = m.x < n.x ? m.x : n.x;
     double maxx = m.x > n.x ? m.x : n.x;
     double miny = m.y < n.y ? m.y : n.y;
     double maxy = m.y > n.y ? m.y : n.y;
     return ( x > minx && x <= maxx && y >= miny && y <= maxy );
 }

 bool Judge( point &m, point &n, double &R )
 {
     if ( m.x == n.x )
     {
         if ( abs(m.x) >= R ) return true;
         else
         {
             if ( m.y * n.y > 0 ) return true;
             else return false;
         }
     }
     else if ( m.y == n.y )
     {
         if ( abs(m.y) >= R ) return true;
         else
         {
             if ( m.x * n.x > 0 ) return true;
             else return false;
         }
     }

     double A = n.y - m.y;
     double B = m.x - n.x;
     double C = (n.x - m.x) * m.y - (n.y - m.y) * m.x;
     double dis = abs(C)/ sqrt( A*A + B*B );
     if ( dis >= R ) return true;
     else
     {
         double kkk = (-A) / B;
         double bbb = (-C) / B;
         double xx = ( -bbb ) / ( kkk + 1.0 / kkk );
         double yy = ( (-1.0) / kkk ) * xx;
         if ( check( m, n, xx, yy ) ) return false;
         else return true;
     }
 }

 int main()
 {
     int T;
     double R;
     point A, B;
     O.x = 0;
     O.y = 0;
     scanf( "%d", &T );
     while ( T-- )
     {
         scanf( "%lf%lf%lf%lf%lf", &A.x, &A.y, &B.x, &B.y, &R );

         if ( Judge(A, B, R) )
             printf( "%.3f\n", Get_Dist(A, B) );
         else
         {
             double L1 = Get_Dist(A, O);
             double L2 = Get_Dist(B, O);
             double LL1 = sqrt( L1*L1 - R*R );
             double LL2 = sqrt( L2*L2 - R*R );
             double angle = Get_Angle( Get_Dist(A, B), L1, L2 ) - acos( R/L1 ) - acos( R/L2 );
             double ans = LL1 + LL2 + R * angle;
             printf( "%.3f\n", ans );
         }
     }
     return 0;
 }
