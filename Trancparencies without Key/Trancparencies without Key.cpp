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
	long long int x[3][l][w];	
	initwindow(w+1,l+1);
    readimagefile("Trancparency 1 Picture 1.bmp",0,0,w,l);
	for(long long int i = 0;i < w;i++)
		for(long long int j = 0;j < l;j++)
		{
			if(getpixel(i,j) == 15)
			{
				x[0][j][i] = 0;
			}
			else
			{
				x[0][j][i] = 1;
			}
		}
	initwindow(w+1,l+1);
	readimagefile("Trancparency 2 Picture 1.bmp",0,0,w,l);
	for(long long int i = 0;i < w;i++)
		for(long long int j = 0;j < l;j++)
		{
			if(getpixel(i,j) == 15)
			{
				x[1][j][i] = 0;
			}
			else
			{
				x[1][j][i] = 1;
			}
		}
	initwindow(w,l);
    readimagefile("Trancparency 3 Picture 1.bmp",0,0,w,l);
	for(long long int i = 0;i < w;i++)
		for(long long int j = 0;j < l;j++)
		{
			if(getpixel(i,j) == 15)
			{
				x[2][j][i] = 0;
			}
			else
			{
				x[2][j][i] = 1;
			}
		}

	initwindow(w+1,l+1);
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

	for(long long int i = 0;i < w;i++)
	{
		for(long long int j = 0; j < l;j++)
		{
			if(x[1][j][i] == 1)	
  		    putpixel(i,j,0); 
		}
	}

	for(long long int i = 0;i < w;i++)
	{
		for(long long int j = 0; j < l;j++)
		{
			if(x[2][j][i] == 1)	
			putpixel(i,j,0); 
		}
	}
	writeimagefile("Trancparencies without Key Picture 1.bmp");
   	getch();
	return 0;
}
