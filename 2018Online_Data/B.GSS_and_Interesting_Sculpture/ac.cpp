#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const double PI = acos(-1.0);
int main(){
	double R,r,L,x,y,ans;
    while(~scanf("%lf%lf%lf",&R,&r,&L)){
		ans=0;
        x = (R*R - r*r + L*L)/2/L;
        y = sqrt(R*R - x*x);
        ans += (PI-atan2(y,x))*4*R*R;
        ans += atan2(y,x-L)*4*r*r;
        printf("%.12lf\n",ans);
//cout<<x<<' '<<y<<' '<<y/x<<' '<<atan2(y,x)<<' '<<alpha<<endl;
    }
}