#include <iostream>
#include <conio.h>
#include <windows.h>


using namespace std;

class Logic
{
private:
	int hp = 100;
	int dm = 10;
	int lv = 1;
	int width = 50;
	int height = 20;
	int x;
	int y;
	int fruitX = rand() % width;
	int fruitY = rand() % height;
	bool gameOver = false;
	int score=0;
	int healx=rand()%width;
	int healy=rand()%height;
	int maxhp=100;
	int maxlevel=5;
	int kill=0;
	int mx=rand()%width;
	int my=rand()%height;
	int mrandgo;
	int mhp = 20;
	int limit;
	
	

public:
	void setrandgo() {
		mrandgo = rand() % 5;
		if (mrandgo = 1) {
			mx++;
		}
		if (mrandgo = 2) {
			mx--;
		}
		if (mrandgo = 3) {
			my--;
		}
		if (mrandgo = 4) {
			my++;
		}
	}
	int getmx() {
		return mx;
	}
	int getmy() {
		return my;
	}
	void sethp(){
		if (hp < maxhp) {
			hp = maxhp;
		}
	}
	void sethealing() {
		if (x == healx && y == healy) {
			hp = +10;
			healx = rand() % width;
			healy = rand() % height;
		}
	}
	void setdm() {
		if (x == mx && y == my) {

			x--;
			hp = -10;
			mhp = -dm;
		}
	}
	void setkill() {
		if (mhp < 1) {
			kill++;
			mhp = 20;
			mx = rand() % width;
			my = rand() % height;
		}
	}
	void setlevelstat() {
		if (lv == 1) {
		
			int dm = 10;
			int limit=5;
			int maxhp = 100;

		}
		if (lv == 2) {
		
			int dm = 15;
			int limit=10;
			int maxhp = 120;
		}
		if (lv == 3) {
		
			int dm = 20;
			int limit=15;
			int maxhp = 140;
		}
		if (lv == 4) {
		
			int dm = 30;
			int limit=20;
			int maxhp = 160;
		}
		if (lv == 5) {
			int dm = 40;
			int maxhp = 200;
		}
	}
	void setxy(int dir ){
		
			switch (dir)
			{
			case 2:
				x--;
			case 3:
				x++;
				break;
			case 4:
					y--;
				break;
			case 5:
					y++;
				break;
			default:
				break;
			}

			if (x >= width)
				x = 0;
			else if (x < 0)
				x = width-1;
			if (y >= height)
				y = 0;
			else if (y < 0)
				y = height-1;


		

	}
	void setgameover() {
		if (hp == 0) {
			gameOver = true;
		}
	}
	void setfruit() {
		if (x == fruitX && y == fruitY)
		{
			score += 10;
			fruitX = rand() % width;
			fruitY = rand() % height;
		}
	}
	void setlevel() {
		if (lv > maxlevel) {
			lv = maxlevel;
		}
		if (kill = limit) {
			lv++;
			kill = 0;
			hp = maxhp;
		}
		
	}
	int getscore() {
		return score;
	}
	int getgameover() {
		return gameOver;
	}
	int getx() {
		return x;
	}

	int gety() {
		return y;
	}
	int getfruitx() {
		return fruitX;
	}
	int getfruity() {
		return fruitY;
	}
	int gethealx() {
		return healx;
	}
	int gethealy() {
		return healy;
	}
	int getkill() {
		return kill;
	}
	int getlv() {
		return lv;
	}
	int gethp(){
		return hp;
	}
};
//////////////////////////////////////////////////////////////////
	class input
	{
	private:
		int dir=0;
		bool gameOver = false;
	public:
		void setdir() {
			if (_kbhit())
			{
				switch (_getch())
				{
				case 97:
					dir = 2;//left
					break;
				case 100:
					dir = 3;//right
					break;
				case 119:
					dir = 4;//up
					break;
				case 115:
					dir = 5;//down
					break;
				case 'x':
					gameOver = true;
					break;
				}
			}

		}
		int getdir() {
			return dir;
		}


	};
	/////////////////////////////////////////////////////////////////////////////////
	class draw
	{
	public:
	

		void ddraw(int width,int height , int  fruitX , int fruitY ,  int score,int x, int y, int hp,int lw, int healx, int  healy,int mx,int my,int kill) {
			system("cls");
			for (int i = 0; i < width + 2; i++)
				cout << "#";
			cout << endl;

			for (int i = 0; i < height; i++)
			{
				for (int j = 0; j < width; j++)
				{
					if (j == 0)
						cout << "#";
					if (i == y && j == x)
						cout << "O";
					else if (i == fruitY && j == fruitX)
						cout << "G";
					else
					{
						bool print = false;
					 if (i == healy && j == healx)
						cout << "H";
					 print = true;
					if (i == my && j == mx)
						cout << "M";
					print = true;
					if (print = true) {
						cout << " ";
					}
					}

					if (j == width - 1)
						cout << "#";
					else if (i == healy && j == healx)
						cout << "H";
					if (i == my && j == mx)
						cout << "M";
				}
				cout << endl;
			}

			for (int i = 0; i < width + 2; i++)
				cout << "#";
			cout << endl;
			cout << "Gold:" << score <<"  "<< "level"<<lw<<"  "<<"hp"<<hp<<"  "<<"kills" << kill<< endl;
		}
	};
	//////////////////////////////////////////////////////////////////////////////
	int main()
	{
		bool gameOver;
        int width = 50;
	    int height = 20;
		int x, y, fruitX, fruitY, score;

		int sleep = 0;
		int speed;
		int dir;
		int hp ;
		int dm ;
		int lw ;
		int healx;
		int healy;
		int kill;
		int mx;
		int my;


		Logic logic;
		gameOver = false;
		score = 0;

		while (!gameOver)
		{
			input input;
			input.setdir();
			dir = input.getdir();

			logic.setxy(dir);
			x = logic.getx();
			y = logic.gety();

			logic.setfruit();
			gameOver = logic.getgameover();
			logic.setrandgo();
			logic.setlevelstat();
			logic.setlevel();
			logic.sethp();
			mx = logic.getmx();
			my = logic.getmy();
			healx = logic.gethealx();
			healy = logic.gethealy();
			kill = logic.getkill();
			logic.setdm();
			logic.sethealing();
			logic.setgameover();
			logic.setkill();
			logic.setrandgo();
			lw = logic.getlv();
			hp = logic.gethp();
			fruitX = logic.getfruitx();
			fruitY = logic.getfruity();
			

			draw draw;
			draw.ddraw(width, height, fruitX , fruitY ,score,x,y ,hp,lw,healx,healy,mx,my,kill);

			Sleep(sleep);
		}

		system("cls");
		cout << "GameOver";

		return 0;
	}
