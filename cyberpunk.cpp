#include <iostream>
#include <cstdlib>
using namespace std;

int x = 0; 					//Передвижение x
int y = 0; 					//Передвижение y
//int z = 0; 				//Передвижение по z
int field[50][50]; 	//Игровое поле
char input; 				//Переменная ввода
int linesize = 50; 	//Размер линни отрисовки интерфейса
int descsize = 3;	//Ращмер описания
char desc[descsize] = {"Bob"};			//Описание местности

//Управление
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

//Отрисовка интерфейса
void interface() {

	int a;
	char line[linesize]; //Строка и размер строки в интерфейсе

	for(a = 0; a < linesize; a++)
			line[a] = '=';

	for(a = 0; a < linesize; a++)
			cout << line[a];

	cout << endl;
	cout << "[I] Inventory | [C] Character | [Q] Quit" << endl;
	
	for(a = 0; a < linesize; a++)
		cout << line[a];
	
	cout << endl << "Character location [X: " << x << "]" << " [Y: " << y << "]" << endl;
	
	for(a = 0; a < linesize; a++)
		cout << line[a];
	
	cout << "Description: ";

	for(a = 0; a < linesize; a++) {
		cout << desc[a/2] << endl;
	}

	for(a = 0; a < linesize; a++)
		cout << line[a];

	cout << endl;
	cout << "INPUT - - - ";
	control();
}

//Обновление экрана
void screen_update() {
	while(input != 'q') {
		
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
	screen_update();
return 0;
}
