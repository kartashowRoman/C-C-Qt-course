#include <iostream>
#include <string>
#include <cstdlib>

#define PLAYER2 2 





class Board {
	public:
	Board():board {" -"," -"," -"," -"," -"," -"," -"," -"," -",}{}
	~Board(){}
	std::string board[9]; 
};
//отображение игрового поля
class Display : public Board {
	public:
		Display(): mode(0){}
		int ChooseGameMode(){
		std::cout<<"Режим игры: \n1.С компьютером\n2.С игроком\n";
		std::cin>>this->mode;
		return this->mode;
	}
		int DrawBoard();
		
		~Display(){}
		int mode;
};
//
Display board;

//результат игры
class Result{
	public:
		Result(){}
		int Tie();
		int Win(std::string slot);
		~Result(){}

		
};
Result result;

//игрок1

class PlayerX {
	public:
		PlayerX():move(" X"),move_count_x(0){}
		int Check(int line, int column);

		 int Move(){
			std::cout<<"\nХодит игрок 1\n";
			int line = 0;
			int column = 0;
			std::cout<<"Номер строки \n";
			std::cin>>line;
			std::cout<<"Номер столбца \n";
			std::cin>>column;
			
			switch (line){
				case 1:
					Check(line,column);
					board.board[column-1] = move;
					break;
				case 2:
					Check(line,column);
					board.board[2+column] = move;	
					break;
				case 3:	
					Check(line,column);
					board.board[5+column] = move;
					break;
			}
			move_count_x++;
			result.Tie();
			result.Win(move);
			return board.DrawBoard();
				
		}
		

		~PlayerX(){}

		std::string move;
		int move_count_x;

};
//игрок2
class PlayerO{
	public:
		PlayerO():move(" O"), move_count_o(0){}
		int Check(int line, int column);
		int Move(){
			std::cout<<"\nХодит игрок 2\n";
			int line = 0;
			int column = 0;
			std::cout<<"Номер строки \n";
			std::cin>>line;
			std::cout<<"Номер столбца \n";
			std::cin>>column;
			
			switch (line){
				case 1:
					Check(line,column);
					board.board[column-1] = move;
					break;
				case 2:
					Check(line,column);
					board.board[2+column] = move;	
					break;
				case 3:	
					Check(line,column);
					board.board[5+column] = move;
					break;
			}	
			move_count_o++;	
			result.Win(move);
			return board.DrawBoard();	
		}

		~PlayerO(){}

		std::string move;
		int move_count_o;

};
int Again();

class Computer{
	public:
	Computer():move_count_o(0){}
	
	int Move(){
		std::cout<<"\nХодит АльфаСтар\n";
		
		int slot = rand() % 9;
		if(board.board[slot] == " -")
		{
			board.board[slot] = " O";
		} else
			return Again();
		
		move_count_o++;
		return board.DrawBoard();	
	}
	


	
	~Computer(){}
	int move_count_o;
};

PlayerX Player1;
PlayerO Player2;
Computer computer;

// возвращение для компьютера 
int Again(){
	srand (1);
	return computer.Move();

}
//Прорисовка игрового поля
int Display::DrawBoard(){
	std::cout<<"\nИГРА КРЕСТИКИ-НОЛИКИ\n\n\n";
			std::cout<<' ';

			for(int i = 0; i < 3; i++)
				std::cout<<" "<<i+1;	
			std::cout<<std::endl;	
			std::cout<<1;
			for(int i = 0; i < 3; i++)
			{
				std::cout<<board[i];
			}
			std::cout<<std::endl;
			std::cout<<2;
			for(int i = 3; i < 6; i++)
				std::cout<<board[i];
			std::cout<<std::endl;
			std::cout<<3;
			for(int i = 6; i < 9; i++)
				std::cout<<board[i];
			std::cout<<std::endl;
			switch(mode){
				case 2:
					if(Player1.move_count_x <= Player2.move_count_o)
						return Player1.Move();
					else
						return Player2.Move();
					break;
				case 1:
					if(Player1.move_count_x <= computer.move_count_o)
						return Player1.Move();
					else
						return computer.Move();
					break;
			}
}
 
//Проверка для игрока 1
int PlayerX::Check(int line, int column){
	
	switch (line){
			case 1:
				if(board.board[column-1] == " X" || board.board[column-1] == " O")
					return Player1.Move();
				break;
			case 2:
				if(board.board[2+column] == " X" || board.board[2+column] == " O")
					return Player1.Move();	
				break;
			case 3:	
				if(board.board[5+column] == " X" || board.board[5+column] == " O")
					return Player1.Move();
				break;
	}

}
//Проверка для игрока 2
int PlayerO::Check(int line, int column){
	
	switch (line){
			case 1:
				if( board.board[column-1] == " X"|| board.board[column-1] == " O")
					return Player2.Move();
				break;
			case 2:
				if( board.board[2+column] == " X"|| board.board[2+column] == " O")
					return Player2.Move();	
				break;
			case 3:	
				if(board.board[5+column] == " X"|| board.board[5+column] == " O")
					return Player2.Move();
				break;
	}

}

// обнуление поля 
int Null(){
	for(int i = 0; i < 9; i++)
		board.board[i]=" -";
	Player1.move_count_x = 0;
	Player2.move_count_o = 0;
	computer.move_count_o = 0;
	return board.ChooseGameMode();

}
//////////// проверка на ничью
int Result::Tie(){
			if(Player1.move_count_x == 5)
			{
				std::cout<<"////////////Ничья////////////\n";
				for(int i = 0; i < 9; i++)
					board.board[i]=" -";
				Player1.move_count_x = 0;
				Player2.move_count_o = 0;
				computer.move_count_o = 0;
				return board.ChooseGameMode();
			}
}
// неукляюжая проверка на победу 
int Result::Win(std::string slot){
	int x = 0;
	for(int i = 0; i < 9; i+=4)
	{
		if(board.board[i] == slot)
		{
			x++;
		}
	}
	if(x == 3)
		{
			std::cout<<"////////////Победил"<<slot<<"////////////\n";
			return Null();
		}
	x = 0;
	for(int i = 2; i < 7; i+=2)
	{
		if(board.board[i] == slot)
		{
			x++;	
		}
	}
	if(x == 3)
		{
			std::cout<<"////////////Победил"<<slot<<"////////////\n";
			return Null();
		}
	x = 0;
	for(int i = 0; i < 3; i++)
	{
		if(board.board[i] == slot)
		{
			x++;	
		}
	}
	if(x == 3)
		{
			std::cout<<"////////////Победил"<<slot<<"////////////\n";
			return Null();
		}
	x = 0;

	for(int i = 3; i < 6; i++)
	{
		if(board.board[i] == slot)
		{
			x++;	
		}
	}
	if(x == 3)
		{
			std::cout<<"////////////Победил"<<slot<<"////////////\n";
			return Null();
		}
	x = 0;
	
	for(int i = 6; i < 9; i++)
	{
		if(board.board[i] == slot)
		{
			x++;	
		}
	}
	if(x == 3)
		{
			std::cout<<"////////////Победил"<<slot<<"////////////\n";
			return Null();
		}
	x = 0;
	
	for(int i = 0; i < 7; i+=3)
	{
		if(board.board[i] == slot)
		{
			x++;	
		}
	}
	if(x == 3)
		{
			std::cout<<"////////////Победил"<<slot<<"////////////\n";
			return Null();
		}
	x = 0;
	
	for(int i = 1; i < 8; i+=3)
	{
		if(board.board[i] == slot)
		{
			x++;	
		}
	}
	if(x == 3)
		{
			std::cout<<"////////////Победил"<<slot<<"////////////\n";
			return Null();
		}
	x = 0;

	for(int i = 2; i < 9; i+=3)
	{
		if(board.board[i] == slot)
		{
			x++;	
		}
	}
	if(x == 3)
		{
			std::cout<<"////////////Победил"<<slot<<"////////////\n";
			return Null();
		}
	x = 0;
}


int main()
{
	srand( time(NULL) );
	board.ChooseGameMode();
	board.DrawBoard();
	Player1.Move();
	if(board.mode == PLAYER2)
	{
		Player2.Move();
	} else {
		return computer.Move();
	}
	
	return 0;
}

