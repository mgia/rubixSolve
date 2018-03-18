/***************************************************************************** #
#                                                                              #
#                                                       		       #
#    Rubics                                           			       #
#                                                    			       #
#    By: Marc G Tan <findmarcg@gmail.com>                   		       #
#                                            				       #
#    Created: 2017/12/27 21:40:00 by mtan             			       #
#    Updated: 2017/12/27 22:40:00 by mtan             			       #
#                                                                              #
# *****************************************************************************/

#include <iostream>
#include <string>

using namespace std;

string presteps[1000];
string actualsteps[1000];

int countstep;
int num;

struct corner
{
	char cor[8][3];
};

struct edge
{
	char ed[12][2];
};

void turn_clockwise(char rubic[6][10],char RUB[6][10],int opnum)
{
	//swap sides clockwise
	rubic[opnum][8]=RUB[opnum][2];
	rubic[opnum][7]=RUB[opnum][5];
	rubic[opnum][6]=RUB[opnum][8];
	rubic[opnum][3]=RUB[opnum][7];
	rubic[opnum][0]=RUB[opnum][6];
	rubic[opnum][1]=RUB[opnum][3];
	rubic[opnum][2]=RUB[opnum][0];
	rubic[opnum][5]=RUB[opnum][1];
}

// check_moves
void U(char rubic[6][10])
{
	presteps[countstep]="U";
	countstep++;
	char RUB[6][10];
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<10;j++)
		{
			RUB[i][j]=rubic[i][j];
		}
	}
	turn_clockwise(rubic,RUB,4);
	for(int i=0;i<3;i++)
	{
		rubic[0][i]=RUB[3][i];
		rubic[2][i]=RUB[0][i];
		rubic[1][i]=RUB[2][i];
		rubic[3][i]=RUB[1][i];
	}
}

void Ui(char rubic[6][10])
{
	U(rubic);
	U(rubic);
	U(rubic);
}

void D(char rubic[6][10])
{
	presteps[countstep]="D";
	countstep++;
	char RUB[6][10];
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<10;j++)
		{
			RUB[i][j]=rubic[i][j];
		}
	}
	turn_clockwise(rubic,RUB,5);
	for(int i=6;i<9;i++)
	{
		rubic[0][i]=RUB[2][i];
		rubic[2][i]=RUB[1][i];
		rubic[1][i]=RUB[3][i];
		rubic[3][i]=RUB[0][i];
	}
}

void Di(char rubic[6][10])
{

	D(rubic);
	D(rubic);
	D(rubic);
}

void F(char rubic[6][10])
{
	presteps[countstep]="F";
	countstep++;
	char RUB[6][10];
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<10;j++)
		{
			RUB[i][j]=rubic[i][j];
		}
	}
	turn_clockwise(rubic,RUB,0);

	rubic[4][6]=RUB[2][8];
	rubic[4][7]=RUB[2][5];
	rubic[4][8]=RUB[2][2];

	rubic[5][0]=RUB[3][6];
	rubic[5][1]=RUB[3][3];
	rubic[5][2]=RUB[3][0];

	rubic[2][2]=RUB[5][0];
	rubic[2][5]=RUB[5][1];
	rubic[2][8]=RUB[5][2];

	rubic[3][0]=RUB[4][6];
	rubic[3][3]=RUB[4][7];
	rubic[3][6]=RUB[4][8];

}

void Fi(char rubic[6][10])
{
	F(rubic);
	F(rubic);
	F(rubic);
}

void B(char rubic[6][10])
{
	presteps[countstep]="B";
	countstep++;
	char RUB[6][10];
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<10;j++)
		{
			RUB[i][j]=rubic[i][j];
		}
	}
	turn_clockwise(rubic,RUB,1);

	rubic[4][0]=RUB[3][2];
	rubic[4][1]=RUB[3][5];
	rubic[4][2]=RUB[3][8];

	rubic[5][8]=RUB[2][6];
	rubic[5][7]=RUB[2][3];
	rubic[5][6]=RUB[2][0];

	rubic[2][6]=RUB[4][0];
	rubic[2][3]=RUB[4][1];
	rubic[2][0]=RUB[4][2];

	rubic[3][2]=RUB[5][8];
	rubic[3][5]=RUB[5][7];
	rubic[3][8]=RUB[5][6];
}

void Bi(char rubic[6][10])
{

	B(rubic);
	B(rubic);
	B(rubic);
}

void L(char rubic[6][10])
{
	presteps[countstep]="L";
	countstep++;
	char RUB[6][10];
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<10;j++)
		{
			RUB[i][j]=rubic[i][j];
		}
	}
	turn_clockwise(rubic,RUB,2);
	rubic[0][0]=RUB[4][0];
	rubic[0][3]=RUB[4][3];
	rubic[0][6]=RUB[4][6];

	rubic[5][0]=RUB[0][0];
	rubic[5][3]=RUB[0][3];
	rubic[5][6]=RUB[0][6];

	rubic[4][0]=RUB[1][8];
	rubic[4][3]=RUB[1][5];
	rubic[4][6]=RUB[1][2];

	rubic[1][8]=RUB[5][0];
	rubic[1][5]=RUB[5][3];
	rubic[1][2]=RUB[5][6];
}

void Li(char rubic[6][10])
{
	L(rubic);
	L(rubic);
	L(rubic);
}

void R(char rubic[6][10])
{
	presteps[countstep]="R";
	countstep++;
	char RUB[6][10];
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<10;j++)
		{
			RUB[i][j]=rubic[i][j];
		}
	}
	turn_clockwise(rubic,RUB,3);
	rubic[0][2]=RUB[5][2];
	rubic[0][5]=RUB[5][5];
	rubic[0][8]=RUB[5][8];

	rubic[5][2]=RUB[1][6];
	rubic[5][5]=RUB[1][3];
	rubic[5][8]=RUB[1][0];

	rubic[4][2]=RUB[0][2];
	rubic[4][5]=RUB[0][5];
	rubic[4][8]=RUB[0][8];

	rubic[1][6]=RUB[4][2];
	rubic[1][3]=RUB[4][5];
	rubic[1][0]=RUB[4][8];
}

void Ri(char rubic[6][10])
{
	R(rubic);
	R(rubic);
	R(rubic);
}

corner getcorner(char rubic[6][10])
{
	corner ans;
	//front right top
	ans.cor[0][0]=rubic[0][2];
	ans.cor[0][1]=rubic[3][0];
	ans.cor[0][2]=rubic[4][8];
	//right back top
	ans.cor[1][0]=rubic[3][2];
	ans.cor[1][1]=rubic[1][0];
	ans.cor[1][2]=rubic[4][2];
	//back left top
	ans.cor[2][0]=rubic[1][2];
	ans.cor[2][1]=rubic[2][0];
	ans.cor[2][2]=rubic[4][0];
	//left front top
	ans.cor[3][0]=rubic[2][2];
	ans.cor[3][1]=rubic[0][0];
	ans.cor[3][2]=rubic[4][6];
	//front right down
	ans.cor[4][0]=rubic[0][8];
	ans.cor[4][1]=rubic[3][6];
	ans.cor[4][2]=rubic[5][2];
	//right back down
	ans.cor[5][0]=rubic[3][8];
	ans.cor[5][1]=rubic[1][6];
	ans.cor[5][2]=rubic[5][8];
	//back left down
	ans.cor[6][0]=rubic[1][8];
	ans.cor[6][1]=rubic[2][6];
	ans.cor[6][2]=rubic[5][6];
	//left front down
	ans.cor[7][0]=rubic[2][8];
	ans.cor[7][1]=rubic[0][6];
	ans.cor[7][2]=rubic[5][0];
	return ans;
}
edge getedge (char rubic[6][10])
{
	edge ans;
	//front top
	ans.ed[0][0]=rubic[0][1];
	ans.ed[0][1]=rubic[4][7];
	//right top
	ans.ed[1][0]=rubic[3][1];
	ans.ed[1][1]=rubic[4][5];
	//back top
	ans.ed[2][0]=rubic[1][1];
	ans.ed[2][1]=rubic[4][1];
	//right top
	ans.ed[3][0]=rubic[2][1];
	ans.ed[3][1]=rubic[4][3];
	//front right
	ans.ed[4][0]=rubic[0][5];
	ans.ed[4][1]=rubic[3][3];
	//right back
	ans.ed[5][0]=rubic[3][5];
	ans.ed[5][1]=rubic[1][3];
	//back left
	ans.ed[6][0]=rubic[1][5];
	ans.ed[6][1]=rubic[2][3];
	//left front
	ans.ed[7][0]=rubic[2][5];
	ans.ed[7][1]=rubic[0][3];
	//front down
	ans.ed[8][0]=rubic[0][7];
	ans.ed[8][1]=rubic[5][1];
	//right down
	ans.ed[9][0]=rubic[3][7];
	ans.ed[9][1]=rubic[5][5];
	// back down
	ans.ed[10][0]=rubic[1][7];
	ans.ed[10][1]=rubic[5][7];
	// left down
	ans.ed[11][0]=rubic[2][7];
	ans.ed[11][1]=rubic[5][3];
	return ans;
}

void print_corners(char rubic[6][10])
{
	// check corner
	corner temp = getcorner(rubic);
	for (int i=0;i<8;i++)
	{
		if (i==0)
		cout<<"top corners"<<endl;
		if (i==4)
		cout<<"bottom corners"<<endl;
		for(int j=0;j<3;j++)
		{
			cout<<temp.cor[i][j]<<" ";
		}
		cout<<endl;
	}
}
void print_edges(char rubic[6][10])
{
	// check edge
	edge temp = getedge(rubic);
	for (int i=0;i<12;i++)
	{
		if (i==0)
		cout<<"top edges"<<endl;
		if (i==4)
		cout<<"middle edges"<<endl;
		if (i==8)
		cout<<"bottom edges"<<endl;
		for(int j=0;j<2;j++)
		{
			cout<<temp.ed[i][j]<<" ";
		}
		cout<<endl;
	}
}

void move (int number, char rubic[6][10])
{
	switch(number)
	{
		case 4:U(rubic);break;
		case 5:D(rubic);break;
		case 0:F(rubic);break;
		case 2:B(rubic);break;
		case 3:L(rubic);break;
		case 1:R(rubic);break;
		case 10:Ui(rubic);break;
		case 11:Di(rubic);break;
		case 6:Fi(rubic);break;
		case 8:Bi(rubic);break;
		case 9:Li(rubic);break;
		case 7:Ri(rubic);break;
		default:break;
	}
}

// step 1a: top cross
void step0(char rubic[6][10])
{
	bool solve = 0;
	edge temp = getedge(rubic);
	if ((temp.ed[0][1]=='W') && (temp.ed[1][1]=='W')
	&&(temp.ed[2][1]=='W') && (temp.ed[3][1]=='W'))
	solve = 1;

	while (solve == 0)
	{
		// add from top layer
		for (int i = 0; i < 4; i++)
		{
			if (temp.ed[i][0] == 'W')
			{
				move(i, rubic);
				temp = getedge(rubic);
				while (temp.ed[(i+1)%4][1] == 'W')
				{
					move(4, rubic);
					temp = getedge(rubic);
				}
				move((i+1)%4, rubic);
				temp = getedge(rubic);
			}
		}
		// add from middle layer
		for(int i = 4; i < 8; i++)
		{
			if (temp.ed[i][0] == 'W')
			{
				while(temp.ed[(i+1)%4][1]=='W')
				{
					move(4, rubic);
					temp = getedge(rubic);
				}
				move((i+1)%4, rubic);
				temp = getedge(rubic);
			}
			if (temp.ed[i][1] == 'W')
			{
				while(temp.ed[(i-1)%4][1] == 'W')
				{
					move(4, rubic);
					temp = getedge(rubic);
				}
				move((i%4)+6, rubic);
				temp = getedge(rubic);
			}
		}
		// add from bottom layer
		for (int i = 8; i < 12; i++)
		{
			if (temp.ed[i][0]=='W')
			{
				while (temp.ed[i%4][1] == 'W')
				{
					move(4,rubic);
					temp = getedge(rubic);
				}
				move((i%4)+6, rubic);
				temp = getedge(rubic);
				while (temp.ed[(i+1)%4][1] == 'W')
				{
					move(4, rubic);
					temp = getedge(rubic);
				}
				move((i+1)%4, rubic);
				temp = getedge(rubic);
			}

			if (temp.ed[i][1] == 'W')
			{
				while (temp.ed[i%4][1] == 'W')
				{
					move(4,rubic);
					temp = getedge(rubic);
				}
				move((i%4), rubic);
				temp = getedge(rubic);
				move((i%4), rubic);
				temp = getedge(rubic);
			}
		}
		if ((temp.ed[0][1]=='W') && (temp.ed[1][1]=='W')
		&& (temp.ed[2][1]=='W') && (temp.ed[3][1]=='W'))
		solve = 1;
	}
	return;
}

// step 1b：correct top cross edges
void step1(char rubic[6][10])
{
	bool solve = 0;

	edge temp = getedge(rubic);

	char side[4]={'G','R','B','O'};
	if ((temp.ed[0][0]=='G') && (temp.ed[1][0]=='R')
		&& (temp.ed[2][0]=='B') && (temp.ed[3][0]=='O'))
		solve = 1;

	if (solve == 0)
	{
		int i;
		for (i = 0; i < 4; i++)
		{
			while ((temp.ed[i][1] != 'W') || (temp.ed[i][0] != side[i]))
			{
				move(4, rubic);
				temp = getedge(rubic);
			}
			move(i, rubic);
			move(i, rubic);
			temp = getedge(rubic);
		}
		move(0, rubic);
		move(0, rubic);
		move(1, rubic);
		move(1, rubic);
		move(2, rubic);
		move(2, rubic);
		move(3, rubic);
		move(3, rubic);
	}
	return;
}

// step 2：white corners
void step2 (char rubic[6][10])
{
	bool solve = 1;

	corner temp1 = getcorner(rubic);

	char side[4] = {'G','R','B','O'};

	int ops = 0;
	for (int i = 0; i < 4; i++)
	{
		if ((temp1.cor[i][0]!=side[i]) || (temp1.cor[i][1]!=side[(i+1)%4])
		|| (temp1.cor[i][2]!='W'))
		{
			solve = 0;
			break;
		}

	}
	while (solve == 0)
	{
		// add to top
		for (int i = 0; i < 4; i++)
		{
			if (temp1.cor[i+4][0] == 'W')
			{
				int j;
				for (j = 0; j < 4; j++)
				{
					if (side[j] == temp1.cor[i+4][1])
					{
						ops = (j - i + 3) % 4;
						break;
					}
				}
				for (int k = 0; k < ops; k++)
				move(5, rubic);
				move((j+3)%4, rubic);
				move(5, rubic);
				move((j+3)%4+6, rubic);
				temp1 = getcorner(rubic);
			}
			else if (temp1.cor[i+4][1] == 'W')
			{
				ops = 0;

				int j;
				for (j = 0; j < 4; j++)
				{
					if (side[j] == temp1.cor[i+4][0])
					{
						ops = (j - i + 4) % 4;
						break;
					}
				}
				for (int k = 0; k < ops; k++)
				move(5, rubic);
				move((j+1)%4+6, rubic);
				move(11, rubic);
				move((j+1)%4, rubic);
				temp1 = getcorner(rubic);
			}
			else if (temp1.cor[i+4][2] == 'W')
			{
				ops = 0;

				int j;
				for (j = 0; j < 4; j++)
				{
					if (side[j] == temp1.cor[i+4][0])
					{
						ops = (j - i + 3) % 4;
						break;
					}
				}
				for (int k = 0; k < ops; k++)
				move(5, rubic);
				move((j+3)%4, rubic);
				move(5, rubic);
				move(5, rubic);
				move((j+3)%4+6, rubic);
				move(11, rubic);
				move((j+3)%4, rubic);
				move(5, rubic);
				move((j+3)%4+6, rubic);
				temp1 = getcorner(rubic);
			}
		}
		// fix wrong corners from top
		for (int i = 0; i < 4; i++)
		{
			if (temp1.cor[i][0]=='W')
			{
				while ((temp1.cor[i+4][0]=='W')
				||(temp1.cor[i+4][1]=='W')||(temp1.cor[i+4][2]=='W'))
				move(5,rubic);
				move(i,rubic);
				move(5,rubic);
				move(i+6,rubic);
				temp1 = getcorner(rubic);
				ops = 0;
				int j;
				for (j = 0; j < 4; j++)
				{
					if (side[j] == temp1.cor[(i+1)%4+4][1])
					{
						ops = (j - i + 2) % 4;
						break;
					}
				}
				for (int k = 0; k < ops; k++)
				move(5, rubic);
				move((j+3)%4, rubic);
				move(5, rubic);
				move((j+3)%4+6, rubic);
				temp1 = getcorner(rubic);
			}

			if (temp1.cor[i][1]=='W')
			{
				while ((temp1.cor[i+4][0]=='W')
				||(temp1.cor[i+4][1]=='W')||(temp1.cor[i+4][2]=='W'))
				move(5,rubic);
				move((i+1)%4+6,rubic);
				move(11,rubic);
				move((i+1)%4,rubic);
				temp1 = getcorner(rubic);
				ops = 0;
				int j;
				for (j = 0; j < 4; j++)
				{
					if (side[j] == temp1.cor[(i+3)%4+4][0])
					{
						ops = (j - i + 3) % 4;
						break;
					}
				}
				for (int k = 0; k < ops; k++)
				move(5, rubic);
				move((j+1)%4+6, rubic);
				move(11, rubic);
				move((j+1)%4, rubic);
				temp1 = getcorner(rubic);
			}

			if ((temp1.cor[i][2]=='W') && (temp1.cor[i][0]!=side[i]))
			{
				move(i,rubic);
				move(5,rubic);
				move(i+6,rubic);
				temp1 = getcorner(rubic);
				ops = 0;
				int j;
				for (j = 0; j < 4; j++)
				{
					if (side[j] == temp1.cor[(i+1)%4+4][0])
					{
						ops = (j - i + 3) % 4;
						break;
					}
				}
				for (int k = 0; k < ops; k++)
				move(5, rubic);
				move((j+1)%4+6, rubic);
				move(11, rubic);
				move((j+1)%4, rubic);
				temp1 = getcorner(rubic);
			}
		}

		solve = 1;
		for (int i = 0; i < 4; i++)
		{
			if ((temp1.cor[i][2]!='W') || (temp1.cor[i][0]!=side[i]))
			{
				solve = 0;
				break;
			}
		}
	}
}
// step 3: second layer
void step3(char rubic[6][10])
{
	bool solve = 1;

	edge temp1 = getedge(rubic);

	char side[4]={'G','R','B','O'};
	for (int i = 0; i < 4; i++)
	{
		if ((temp1.ed[i+4][0]!=side[i])||(temp1.ed[i+4][1]!=side[(i+1)%4]))
		{
			solve = 0;
			break;
		}
	}
	while (solve == 0)
	{
		for (int i = 0; i < 4; i++)
		{
			if ((temp1.ed[i+8][0]!='Y')&&(temp1.ed[i+8][1]!='Y'))
			{
				// set edge above sides
				int ops = 0;
				int j = 0;
				for(j=0;j<4;j++)
				{
					if(temp1.ed[i+8][0]==side[j])
					{
						ops = (j - i + 4) % 4;
						break;
					}
				}
				for(int m=0;m<ops;m++)
				move(5,rubic);
				// go left
				if (temp1.ed[i+8][1]==side[(j+3)%4])
				{
					move(5,rubic);
					move((j+3)%4,rubic);
					move(11,rubic);
					move((j+3)%4+6,rubic);
					move(11,rubic);
					move(j+6, rubic);
					move(5,rubic);
					move(j, rubic);
					temp1=getedge(rubic);
				}
				// go right
				else
				{
					move(11,rubic);
					move((j+1)%4+6,rubic);
					move(5,rubic);
					move((j+1)%4,rubic);
					move(5,rubic);
					move(j, rubic);
					move(11,rubic);
					move(j+6, rubic);
					temp1=getedge(rubic);
				}
			}
		}
		for (int i = 0; i < 4; i++)
		{
			if (temp1.ed[i+4][0]==side[i]&&temp1.ed[i+4][1]==side[(i+1)%4])
			continue;
			else if((temp1.ed[i+4][0]!='Y')&&(temp1.ed[i+4][1]!='Y'))
			{
				// while(temp1.ed[i+8][0]!='Y'&&temp1.ed[i+8][1]!='Y')
				// 	move(5,rubic);
				move((i+1)%4+6,rubic);
				move(5,rubic);
				move((i+1)%4,rubic);
				move(5,rubic);
				move(i, rubic);
				move(11,rubic);
				move(i+6, rubic);
				temp1=getedge(rubic);
			}
		}
		solve = 1;
		for (int i = 0; i < 4; i++)
		{
			if ((temp1.ed[i+4][0]!=side[i])||(temp1.ed[i+4][1]!=side[(i+1)%4]))
			{
				solve = 0;
				break;
			}
		}
	}

}

// step 4：bottom cross
void step4(char rubic[6][10])
{
	int solve = 1;

	edge temp1 = getedge(rubic);
	for (int i=0;i<4;i++)
	{
		if(temp1.ed[i+8][1]!='Y')
		{
			solve = 0;
			break;
		}
	}
	while (solve == 0)
	{
		for(int i=0;i<4;i++)
		{
			if (temp1.ed[i+8][1]!='Y')
			{
				move(i+6,rubic);
				move((i+1)%4+6,rubic);
				move(11,rubic);
				move((i+1)%4,rubic);
				move(5,rubic);
				move(i,rubic);
				temp1=getedge(rubic);
				break;
			}
		}
		solve = 1;
		for (int i=0;i<4;i++)
		{
			if(temp1.ed[i+8][1]!='Y')
			{
				solve = 0;
				break;
			}
		}
	}
	return ;
}

// step 5：bottom face
void step5(char rubic[6][10])
{
	int count = 0;

	corner temp1 = getcorner(rubic);

	for(int i=0;i<4;i++)
	{
		if(temp1.cor[i+4][2]!='Y')
		{
			count++;
		}
	}

	while(count>0)
	{
		while(temp1.cor[4][2]=='Y')
		{
			move(11,rubic);
			temp1 = getcorner(rubic);
		}
		while(temp1.cor[4][2]!='Y')
		{
			move(1,rubic);
			move(4,rubic);
			move(7,rubic);
			move(10,rubic);
			move(1,rubic);
			move(4,rubic);
			move(7,rubic);
			move(10,rubic);
			temp1 = getcorner(rubic);
		}
		count--;
	}
	return ;
}

// step 6：yellow corners
void step6(char rubic[6][10])
{
	bool solve = 1;

	corner temp1 = getcorner(rubic);

	char side[4] = {'G','R','B','O'};

	for(int i=0;i<4;i++)
	{
		if(temp1.cor[i+4][1]!=temp1.cor[(i+1)%4+4][0])
		{
			solve = 0;
			break;
		}
	}
	// if 4 sides are G G, R R, B B, O O, but on the wrong face
	if (solve == 1 && temp1.cor[4][0]!='G')
	{
		int i;
		for(i=0;i<4;i++)
			if(temp1.cor[4][0]==side[i])
				break;
		for(int p=0;p<i;p++)
			move(5,rubic);
		return ;
	}

	while (solve == 0)
	{
		int j = 0;
		for(int i=0;i<4;i++)
		{
			if (temp1.cor[i+4][1]==temp1.cor[(i+1)%4+4][0])
			{
				int ops;
				for(j=0;j<4;j++)
				{
					if (side[j]==temp1.cor[i+4][1])
					{
						ops=(j-i+7)%4;
						break;
					}
				}
				for(int p=0;p<ops;p++)
					move(5,rubic);
				break;
			}
		}
		move((j+1)%4+6,rubic);
		move((j+2)%4,rubic);
		move((j+1)%4+6,rubic);
		move(j,rubic);
		move(j,rubic);
		move((j+1)%4,rubic);
		move((j+2)%4+6,rubic);
		move((j+1)%4+6,rubic);
		move(j,rubic);
		move(j,rubic);
		move((j+1)%4,rubic);
		move((j+1)%4,rubic);
		move(11,rubic);
		temp1 = getcorner(rubic);

		solve = 1;
		for(int i=0;i<4;i++)
		{
			if((temp1.cor[i+4][1]!=temp1.cor[(i+1)%4+4][0]))
			{
				solve = 0;
				break;
			}
		}
	}
	return ;
}


// step 7：yellow edges
void step7(char rubic[6][10])
{
	int count = 0;

	edge temp1 = getedge(rubic);

	char side[4] = {'G','R','B','O'};

	for(int i=0;i<4;i++)
	{
		if(temp1.ed[i+8][0]==side[i])
			count++;
	}
	while (count != 4)
	{
		int number = 0;
		int j = 0;
		if (count == 1)
		{
			// decide which direction to go
			for(j=0;j<4;j++)
				if(temp1.ed[j+8][0]==side[j])
					break;
			if(temp1.ed[(j+1)%4+8][0]!=side[(j+2)%4])
				number=1;
		}
		switch(number)
		{
			// clockwise
			case 0:
			{
				move((j+2)%4,rubic);
				move((j+2)%4,rubic);
				move(5,rubic);
				move((j+3)%4,rubic);
				move((j+1)%4+6,rubic);
				move((j+2)%4,rubic);
				move((j+2)%4,rubic);
				move((j+3)%4+6,rubic);
				move((j+1)%4,rubic);
				move(5,rubic);
				move((j+2)%4,rubic);
				move((j+2)%4,rubic);
				temp1=getedge(rubic);
				break;
			}
			// anticlockwise
			case 1:
			{
				move((j+2)%4,rubic);
				move((j+2)%4,rubic);
				move(11,rubic);
				move((j+3)%4,rubic);
				move((j+1)%4+6,rubic);
				move((j+2)%4,rubic);
				move((j+2)%4,rubic);
				move((j+3)%4+6,rubic);
				move((j+1)%4,rubic);
				move(11,rubic);
				move((j+2)%4,rubic);
				move((j+2)%4,rubic);
				temp1=getedge(rubic);
				break;
			}
		}
		count = 0;
		for(int i=0;i<4;i++)
		{
			if(temp1.ed[i+8][0]==side[i])
				count++;
		}
	}
	return ;
}

void solve(char rubic[6][10])
{
	// main_solve
	step0(rubic);
	step1(rubic);
	step2(rubic);
	step3(rubic);
	step4(rubic);
	step5(rubic);
	step6(rubic);
	step7(rubic);
}

void print_moves(char rubic[6][10])
{
	countstep = 0;
	solve(rubic);

	if(countstep < 3)
	{
		cout<<presteps[0]<<" "<<presteps[1]<<endl;
		return ;
	}

	// Display presteps
	// cout<<"presteps"<<endl;
	// for(int i=0;i<countstep;i++)
	// {
	// 	cout<<presteps[i];
	// 	if((i+1)<countstep)
	// 		cout<<" ";
	// }
	// cout<<endl<<"actualsteps"<<endl;

	// Display actualsteps
	int i;
	num = 0;

	for(i=0;i<countstep-2;i++)
	{
		string window[3];
		bool flag = 0;
		for(int j=0;j<3;j++)
			window[j]=presteps[i+j];
		if(window[0]==window[1]&&window[1]==window[2])
			flag = 1;
		if(flag)
		{
			string temp=presteps[i];
			temp.append("i");
			actualsteps[num]=temp;
			num++;
			i+=2;
		}
		else
		{
			actualsteps[num] = presteps[i];
			num++;
		}
	}
	actualsteps[num]=presteps[i];
	num++;
	actualsteps[num]=presteps[i+1];
	num++;

	for(int i=0;i<num;i++)
	{
		cout<<actualsteps[i];
		if((i+1)<num)
			cout<<" ";
	}
	cout<<endl;
	return ;
}

void test_moves(char rubic[6][10])
{
	for(int i=0;i<num;i++)
	{
		if (actualsteps[i] == "U")
			U(rubic);
		else if (actualsteps[i] == "D")
			D(rubic);
		else if (actualsteps[i] == "F")
			F(rubic);
		else if (actualsteps[i] == "B")
			B(rubic);
		else if (actualsteps[i] == "L")
			L(rubic);
		else if (actualsteps[i] == "R")
			R(rubic);
		else if (actualsteps[i] == "Ui")
			Ui(rubic);
		else if (actualsteps[i] == "Di")
			Di(rubic);
		else if (actualsteps[i] == "Fi")
			Fi(rubic);
		else if (actualsteps[i] == "Bi")
			Bi(rubic);
		else if (actualsteps[i] == "Li")
			Li(rubic);
		else if (actualsteps[i] == "Ri")
			Ri(rubic);
	}
	print_edges(rubic);
	print_corners(rubic);
}

int main()
{
	char rubic[6][10];
	for(int i=0;i<6;i++)
	{
		for(int j=0;j<9;j++)
			cin>>rubic[i][j];
	}

	// Duplicate original cube to test
	// char test[6][10];
	// for(int i=0;i<6;i++)
	// {
	// 	for(int j=0;j<9;j++)
	// 		test[i][j]=rubic[i][j];
	// }

	print_moves(rubic);
	// test_moves(test);
}
