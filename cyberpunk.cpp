#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

int a;
int x = 1; 						//Передвижение x
int y = 1; 						//Передвижение y
int health = 100;				//Здоровье
int experience = 0;				//Опыт
//int z = 0; 					//Передвижение по z
int field[50][50]; 				//Игровое поле
char input; 					//Переменная ввода
int linesize = 50; 				//Размер линни отрисовки интерфейса
char line[50];					//Строка и размер строки в интерфейсе
int descsize = 30;				//Размер описания
char desc[30];					//Описание местности

//Класс предмета
class Item {
    public:
        std::string name;
        int value;

        Item(std::string name, int value) {
            this->name = name;
            this->value = value;
        }
};

//Класс инвентаря
class Inventory {
    public:
        std::vector<Item> items;

        void addItem(Item item) {
            items.push_back(item);
        }

        void removeItem(std::string name) {
            for (int i = 0; i < items.size(); i++) {
                if (items[i].name == name) {
                    items.erase(items.begin() + i);
                    break;
                }
            }
        }

        void displayInventory() {
            std::cout << "Inventory: " << std::endl;
            for (int i = 0; i < items.size(); i++) {
                std::cout << items[i].name << " - " << items[i].value << std::endl;
            }
        }
};

//Костыль для отображения инвентаря
void invdis(Inventory &inventory) {
  inventory.displayInventory();
}

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
		invdis(inventory);

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
