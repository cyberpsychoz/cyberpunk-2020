#include <iostream>
#include <cstdlib>
using namespace std;

int a;
int x = 1; 					//Передвижение x
int y = 1; 					//Передвижение y
//int z = 0; 					//Передвижение по z
int field[50][50]; 				//Игровое поле
char input; 					//Переменная ввода
int linesize = 50; 				//Размер линни отрисовки интерфейса
char line[50];					//Строка и размер строки в интерфейсе
int descsize = 30;				//Размер описания
char desc[30];					//Описание местности

//Управление персонажем
void control() {
	cin >> input;
		if(input == 'w')
			y++;
		if(input == 'a')
			x--;
		if(input == 's')
			y--;
		if(input == 'd')
			x++;
}

//Остановка игрока если он выходит за поле игры
void playerstop() {

	if(x <= 0) {
		x = 1;
	}

  if(y <= 0) {
    y = 1;
   }

	if(x >= 50) {
		x = 49;
	}

	if(y >= 50) {
		y = 49;
	}

}

//Параметры игрока на кнопку С
void charlist() {

	for(a = 0; a < linesize; a++) //Присваивание символа линии отрисовки
		line[a] = '_';

	for(a = 0; a < linesize; a++)
		cout << line[a];

	cout << endl <<"Melee attack:  | ";
	cout << "Shooting:  | ";
	cout << "FireWall: " << endl;

  for(a = 0; a < linesize; a++)
		cout << line[linesize];

}

//Отрисовка интерфейса
void interface() {

	for(a = 0; a < linesize; a++) //Присваивание символа линии отрисовки
			line[a] = '=';

	for(a = 0; a < linesize; a++)
			cout << line[a];

	cout << endl;
	cout << "[I] Inventory | [C] Character | [Q] Quit" << endl; //Клавиши доп меню
	
	if(input == 'i')
		cout << "Your inventory is empty." << endl;

	if(input == 'c')
		charlist();

	for(a = 0; a < linesize; a++)
		cout << line[a];
	
	cout << endl << "Character location [X: " << x << "]" << " [Y: " << y << "]" << endl;
	
	for(a = 0; a < linesize; a++)
		cout << line[a];
	
	cout << endl <<"Description: " << endl;

//	for(a = 0; a < descsize; a++) {
//		cout << desc[a/2] << endl;
//	}

	for(a = 0; a < linesize; a++)
		cout << line[a];

	cout << endl;
	cout << "INPUT - - - ";
	control(); //Ввод в управление
}

//Обновление экрана
void screen_update() {
	while(input != 'q') {
		
		playerstop();
		cout << "CYBERPUNK 2020" << endl;
		interface();
//	text_update();
		system("clear");
		
	}
}

//Обновление текстового поля
//void text_update() {
//	for(int a = 0; a < 100; a++;) {
//		cout << textfield[a];
//	}
//}

int main() {
	system("clear");
	screen_update();
return 0;
}
