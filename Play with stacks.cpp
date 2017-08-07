#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
static int solve(int [],int [],int,int,int);
int main()
{
    int g;
    cin>>g;
    while(g-->0)
    {
      int s1,s2,z;
        cin>>s1>>s2>>z;
        int p1[100000],p2[100000];
        for(int i=0;i<s1;i++)
        {
            int e1;
            cin>>e1;
            p1[i]=e1;
        }
        for(int i=0;i<s2;i++)
        {
            int e2;
            cin>>e2;
            p2[i]=e2;
        }
        int value=solve(p1,p2,z,s1,s2);
        cout<<value<<endl;
        
        
    }
    return 0;
}
        
        
        static int solve(int a[],int b[],int x,int x1,int x2){
		int lengthB = 0;
		int sum = 0;
		while (lengthB < x2 && sum + b[lengthB] <= x) {
			sum += b[lengthB];
			lengthB++;
		}

		int maxScore = lengthB;
		for (int lengthA = 1; lengthA <= x1; lengthA++) 
        {
			sum += a[lengthA - 1];

			while (sum > x && lengthB > 0) 
            {
				lengthB--;
				sum -= b[lengthB];
			}

			if (sum > x)
            {
				break;
			}

			maxScore = max(maxScore, lengthA + lengthB);
		}
		return maxScore;
    }
