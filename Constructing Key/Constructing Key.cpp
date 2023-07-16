#include<iostream>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<cstdlib>
using namespace std;


int main()
{
 	long long int l=150; //number of rows
	long long int w=2*l; // number of columns
 	long long int r,g,b,a[l][w];
 	long long int c[l/2][w/4];
 	double f = 0;


	long long int x[4][l][w];

	long long int randt[8];
	long long int t0[8];
	for(long long int i = 0;i < l/2;i++)
	{
		for(long long int j = 0;j < w/4;j++)
		{
			for(long long int h = 0;h < 4;h++)
			{
				int p = 0;
				randt[h] = rand()%8;
				for(int g = 0;g < h;g++)
				{
					if(randt[h] == randt[g])
					{
						p = 1;
					}
				}
				if(p == 1)
				{
					h--;
				}
			}
			for(long long int e = 0;e < 8;e++)
			{
				if(e == randt[0] or e == randt[1] or e == randt[2] or e == randt[3])
				t0[e] = 1;
				else
				t0[e] = 0;
			}
			x[0][2*i][4*j] = t0[0];
			x[0][2*i][4*j+1] = t0[1];
			x[0][2*i][4*j+2] = t0[2];
			x[0][2*i][4*j+3] = t0[3];
			x[0][2*i+1][4*j] = t0[4];
			x[0][2*i+1][4*j+1] = t0[5];
			x[0][2*i+1][4*j+2] = t0[6];
			x[0][2*i+1][4*j+3] = t0[7];

		}
	}
	initwindow(w,l);
	for(long long int i = 0;i < w;i++)
	{
		for(long long int j = 0; j < l;j++)
		{
			if(x[0][j][i] == 1)	
			putpixel(i,j,0); 
			else 
			putpixel(i,j,15);
		}
	}
	writeimagefile("Key.bmp");
    getch();
    return 0;
}
