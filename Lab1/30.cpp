/*Write a program that takes three things as input from the user, n (n is always even), which is the number of containers, “l” and “u”. Now form an array of n size with lowest value as l and upper value as u with equal difference between any 2 consecutive elements of the array. The array formed when taken in pairs from index 0 to n-1 form a container, with radius being the first element of the pair and height being the second. Now, perform the following tasks,
Calculate the volume of all containers
Calculate the sum of all volumes
Print the maximum volume
Print the minimum volume
Take value of pi = 3.14.
For Example,
Input is 
n  = 10
l = 10
u = 28
 
Output is
[10,12,14,16,18,20,22,24,26,28]  // array of size n = 10 with l = 10 and u = 28 and equal difference between consecutive elements
[[10 12]
 [14 16]
 [18 20]
 [22 24]
 [26 28]]   // Formed containers
Volume of every container (pi*(r*r)*h)
[3768.000000   9847.041016   20347.199219   36474.242188 
59433.917969]
Sum Volume of every container: 129870.400392
Maximum volume: 59433.920000
Minimum volume: 3768.000000

Output format (print everything to 2 decimal places):
3768.00   9847.04   20347.20   36474.24  59433.91
129870.40
59433.92
3768.00*/



#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define FOR(i, n) for (int i = 0; i < n; i++)

int main(){
    int size1; cin>>size1;
    int lowerValue; cin>>lowerValue;
    int upperValue; cin>>upperValue;
	

    //write your code here
    
    int diff = (upperValue - lowerValue) / (size1 - 1);
    
    // vi elems(size1);
    vi radius;
    vi height;
    
    int num = lowerValue;
	
	FOR(i, size1)
	{
	   // elems[i] = num;
	    
	    if (i % 2 == 0)
	    {
	        radius.emplace_back(num);
	    }
	    else
	    {
	        height.emplace_back(num);
	    }
	    
	    num += diff;
	    
	   // cout << radius[i] << " " << height[i] << endl;
	}
	

	double pi = 3.14;
	
	double min = FLT_MAX;
	double max = FLT_MIN;
	double sum = 0.0;
	
	FOR(i, radius.size())
	{
	    double ans = pi*radius[i]*radius[i]*height[i];
	    cout << fixed << setprecision(2) <<  ans << " ";
	    
	    if (max < ans)
	    {
	        max = ans;
	    }
	    
	    if (min > ans)
	    {
	        min = ans;
	    }
	    
	    sum += ans;
	}
	
	cout << fixed << setprecision(2) << endl << sum << endl << min << endl << max;
	
    
    return 0;
}