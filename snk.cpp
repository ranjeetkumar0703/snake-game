#include <conio.h>
#include <stdio.h>
//#include <stdlib.h>
//#include <unistd.h>
#include<graphics.h>
int i, j, height = 25, width = 25;
int gameover, score;
int x, y, fruitx, fruity, flag;
int tailx[100],taily[100];
int countTail=0;

void setup()
{
	gameover = 0;

	
	x = height / 4;
	y = width / 4;
label1:
	fruitx = rand() % 15;
	if (fruitx == 0)
		goto label1;
label2:
	fruity = rand() % 20;
	if (fruity == 0)
		goto label2;
	score = 0;
}

void draw()
{
	int i,j,k;
	system("cls");
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			if (i == 0 || i == width - 1 || j == 0 || j == height - 1)
			 {
				printf("#");
			}
			else {
				if (i == x && j == y)
					printf("O");
				else if (i == fruitx && j == fruity)
					printf("*");
				else
					{
						int ch=0;
						for(k=0;k<countTail;k++)
						{
							if(i==tailx[k] && j==taily[k])
							{
								printf("o");
								ch=1;
							}
						}
						if(ch==0)
						printf(" ");
					}
			}
		}
		printf("\n");
	}

	printf("score = %d", score);
	printf("\n");
	printf("press ENTER to quit the game");
}
void input()
{
	if (kbhit()) {
		switch (getch()) {
		case 75:
			flag = 1;
			break;
		case 80:
			flag = 2;
			break;
		case 77:
			flag = 3;
			break;
		case 72:
			flag = 4;
			break;
		case 13:
			gameover = 1;
			break;
		}
	}
}
void logic()
{
	int i;
	int prevx=tailx[0];
	int prevy=taily[0];
	int prev2x ,prev2y;
	tailx[0]=x;
	taily[0]=y;
	for(i=1;i<countTail;i++)
	{
		prev2x=tailx[i];
		prev2y=taily[i];
		tailx[i]=prevx;
		taily[i]=prevy;
		prevx=prev2x;
		prevy=prev2y;
	}
	switch (flag) {
	case 1:
		y--;
		break;
	case 2:
		x++;
		break;
	case 3:
		y++;
		break;
	case 4:
		x--;
		break;
	default:
		break;
	}

	if (x < 0 || x > height || y < 0 || y > width)
		gameover = 1;
		for(i=0;i<countTail;i++)
		{
			if(x==tailx[i] && y==taily[i])
			gameover=1;
		}
	
	if (x == fruitx && y == fruity) {
	label3:
		fruitx = rand() % 20;
		if (fruitx == 0)
			goto label3;
	label4:
		fruity = rand() % 15;
		if (fruity == 0)
			goto label4;
		score += 10;
		countTail++;
	}
}

int main()
{
	char c;
	int m, n;
	label5:
	setup();
	while (!gameover) {
		
		draw();
		input();
		logic();
		for(m=0;m<=1000;m++)
		{
		for(n=0;n<=10000;n++)
			{
				
			}
		}
		for(m=0;m<10000;m++)
		{
			for(n=0;n<10000;n++)
			{
			}
		}
	}
	printf("\npress Y to countinue again:");
	scanf("%c,&c");
	if(c=='y' || c=='Y')
	goto label5;
	return 0;
}

