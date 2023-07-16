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

	long long int t0[8];
	initwindow(w,l);
	readimagefile("Key.bmp",0,0,w,l);

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
	readimagefile("Picture 1.bmp",0,0,w,l);

	for(long long int i = 0;i < w;i++)
		for(long long int j = 0;j < l;j++)
		{
			r = RED_VALUE(getpixel(i,j));
			g = GREEN_VALUE(getpixel(i,j));
			b = BLUE_VALUE(getpixel(i,j));
			f = (0.299*r)+(0.587*g)+(0.114*b);
			if(f >= 128)
			{
				putpixel(i,j,15);
				a[j][i] = 0;
			}
			else
			{
				putpixel(i,j,0);
				a[j][i] = 1;
			}
		}
	
	for(long long int i = 0;i < l/2;i++)
		for(long long int j = 0;j < w/4;j++)
		{	if((a[2*i][4*j] == 0)||(a[2*i][4*j+1]==0)||(a[2*i][4*j+2]==0)||(a[2*i][4*j+3]==0)||(a[2*i+1][4*j] == 0)||(a[2*i+1][4*j+1]==0)||(a[2*i+1][4*j+2]==0)||(a[2*i+1][4*j+3]==0)) 
			{
				c[i][j]=0;		
			}
			else
				c[i][j]=1;
		}	
       	
	long long int c0[4][8];
	long long int copyc0[4][8];
	long long int c1[4][8];
	long long int copyc1[4][8];
	long long int z,o;
	c0[0][0] = 1;c0[0][1] = 1;c0[0][2] = 1;c0[0][3] = 1;c0[0][4] = 0;c0[0][5] = 0;c0[0][6] = 0;c0[0][7] = 0;
	c0[1][0] = 1;c0[1][1] = 0;c0[1][2] = 0;c0[1][3] = 1;c0[1][4] = 1;c0[1][5] = 0;c0[1][6] = 1;c0[1][7] = 0;
	c0[2][0] = 0;c0[2][1] = 1;c0[2][2] = 0;c0[2][3] = 1;c0[2][4] = 0;c0[2][5] = 1;c0[2][6] = 1;c0[2][7] = 0;
	c0[3][0] = 0;c0[3][1] = 0;c0[3][2] = 1;c0[3][3] = 1;c0[3][4] = 1;c0[3][5] = 1;c0[3][6] = 0;c0[3][7] = 0;

    c1[0][0] = 0;c1[0][1] = 0;c1[0][2] = 0;c1[0][3] = 0;c1[0][4] = 1;c1[0][5] = 1;c1[0][6] = 1;c1[0][7] = 1;
	c1[1][0] = 1;c1[1][1] = 1;c1[1][2] = 0;c1[1][3] = 0;c1[1][4] = 1;c1[1][5] = 1;c1[1][6] = 0;c1[1][7] = 0;
	c1[2][0] = 1;c1[2][1] = 0;c1[2][2] = 1;c1[2][3] = 0;c1[2][4] = 1;c1[2][5] = 0;c1[2][6] = 1;c1[2][7] = 0;
	c1[3][0] = 1;c1[3][1] = 0;c1[3][2] = 0;c1[3][3] = 1;c1[3][4] = 0;c1[3][5] = 1;c1[3][6] = 1;c1[3][7] = 0;
	
	long long int randc0[8];
	long long int randc1[8];

	for(long long int i = 0; i < 4;i++)
		for(long long int j = 0; j < 8;j++)
			copyc0[i][j] = c0[i][j];

	for(long long int i = 0; i < 4;i++)
		for(long long int j = 0; j < 8;j++)
			copyc1[i][j] = c1[i][j]; 

	for(long long int i = 0;i < l/2;i++)
		{
			for(long long int j = 0;j < w/4;j++)
			{

//  construct 4 different random numbers between 0..3 and assign them to randc0[0..3]
				for(int q = 0;q < 4;q++)
				{
					int p = 0;
					randc0[q] = rand()%4;
					for(int t = 0;t < q;t++)
					{
						if(randc0[q] == randc0[t])
						{
							p = 1;
						}
					}
					if(p == 1)
					{
						q--;
					}
				}

//  construct 4 different random numbers between 4..7 and assign them to randc0[4..7]
				for(int q = 4;q < 8;q++)
				{
					int p = 0;
					randc0[q] = rand()%4;
					for(int t = 4;t < q;t++)
					{
						if(randc0[q] == randc0[t])
						{
							p = 1;
						}
					}
					if(p == 1)
					{
						q--;
					}
				}
				for(int q=4;q < 8; q++)
				    {    randc0[q]=randc0[q]+4;}

				z = 0;
				o = 4;


                if(c[i][j] == 0)
				{
					t0[0] = x[0][2*i][4*j];
					t0[1] = x[0][2*i][4*j+1];
					t0[2] = x[0][2*i][4*j+2];
					t0[3] = x[0][2*i][4*j+3];
					t0[4] = x[0][2*i+1][4*j];
					t0[5] = x[0][2*i+1][4*j+1];
					t0[6] = x[0][2*i+1][4*j+2];
					t0[7] = x[0][2*i+1][4*j+3];

					for(int m = 0; m < 8;m++)
					{
						if(t0[m] == 1)
						{
							c0[1][m] = copyc0[1][randc0[z]];
							c0[2][m] = copyc0[2][randc0[z]];
							c0[3][m] = copyc0[3][randc0[z]];
							z++;
						}
						else
						{
                            c0[1][m] = copyc0[1][randc0[o]];
							c0[2][m] = copyc0[2][randc0[o]];
							c0[3][m] = copyc0[3][randc0[o]];
							o++;
						}
					}
					for(int k = 1; k < 4;k++)
					{ 
							x[k][2*i][4*j] = c0[k][0];
							x[k][2*i][4*j+1] = c0[k][1];
							x[k][2*i][4*j+2] = c0[k][2];
							x[k][2*i][4*j+3] = c0[k][3];
							x[k][2*i+1][4*j] = c0[k][4];
							x[k][2*i+1][4*j+1] = c0[k][5];
							x[k][2*i+1][4*j+2] = c0[k][6];
							x[k][2*i+1][4*j+3] = c0[k][7];

					} 
				}
				
                if(c[i][j] == 1)
				{
					t0[0] = x[0][2*i][4*j];
					t0[1] = x[0][2*i][4*j+1];
					t0[2] = x[0][2*i+0][4*j+2];
					t0[3] = x[0][2*i+0][4*j+3];
					t0[4] = x[0][2*i+1][4*j];
					t0[5] = x[0][2*i+1][4*j+1];
					t0[6] = x[0][2*i+1][4*j+2];
					t0[7] = x[0][2*i+1][4*j+3];
					for(int m = 0; m < 8;m++)
					{
						if(t0[m] == 0)
						{
							c1[1][m] = copyc1[1][randc0[z]];
							c1[2][m] = copyc1[2][randc0[z]];
							c1[3][m] = copyc1[3][randc0[z]];
							z++;
						}
						else
						{
                            c1[1][m] = copyc1[1][randc0[o]];
							c1[2][m] = copyc1[2][randc0[o]];
							c1[3][m] = copyc1[3][randc0[o]];
							o++;
                        }
                    }

					for(int k = 1; k < 4;k++)
					{ 
							x[k][2*i][4*j] = c1[k][0];
							x[k][2*i][4*j+1] = c1[k][1];
							x[k][2*i][4*j+2] = c1[k][2];
							x[k][2*i][4*j+3] = c1[k][3];
							x[k][2*i+1][4*j] = c1[k][4];
							x[k][2*i+1][4*j+1] = c1[k][5];
							x[k][2*i+1][4*j+2] = c1[k][6];
							x[k][2*i+1][4*j+3] = c1[k][7];
					} 
				} // End of If
			} // End of For (j)
		} // End of For (i)

	initwindow(w,l);
	for(long long int i = 0;i < w;i++)
	{
		for(long long int j = 0; j < l;j++)
		{
			if(x[1][j][i] == 1)	
  		    putpixel(i,j,0); 
			else 
			putpixel(i,j,15);
		}
	}
    writeimagefile("Trancparency 1 Picture 1.bmp");
	initwindow(w,l);
	for(long long int i = 0;i < w;i++)
	{
		for(long long int j = 0; j < l;j++)
		{
			if(x[2][j][i] == 1)	
			putpixel(i,j,0); 
			else 
			putpixel(i,j,15);
		}
	}
    writeimagefile("Trancparency 2 Picture 1.bmp");
	initwindow(w,l);
	for(long long int i = 0;i < w;i++)
	{
		for(long long int j = 0; j < l;j++)
		{
			if(x[3][j][i] == 1)	
  		    putpixel(i,j,0); 
			else 
			putpixel(i,j,15);
		}
	}	    
    writeimagefile("Trancparency 3 Picture 1.bmp");
    
// OR Picture
/*	initwindow(w,l);
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

	for(long long int i = 0;i < w;i++)
	{
		for(long long int j = 0; j < l;j++)
		{
			if(x[3][j][i] == 1)	
  		    putpixel(i,j,0); 
		}
	}
	writeimagefile("Stacked Images Picture 1.bmp");
*/	getch();
	return 0;
}

