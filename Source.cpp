#include <iostream>

using namespace std;
class Student {
private:
	char name[51];
	char surname[51];
	int hp;
	int energy;
	int work;
	int skip;
	int eat;
	int passed;
	int mood;
	float state;
	int day;
	int change_field(int field, int delta);
public:
	void start_game();
	bool is_alive();
	void show();
	void menu();
	void eating();
	void sleeping();
	void your_day();
	void deduction();
	void working();
	void game();
	void skiping();
	void check_stats();
	bool attestate();
	void dead();
	void instruction();
};



void Student::eating() {
	energy += 7;
	hp += 5;
	eat += 10;
	mood += 5;
	if (is_alive() == false) {
		dead();
	}
	check_stats();
};

void Student::working() {
	energy -= 10;
	hp -= 5;
	work += 1;
	mood -= 5;
	if (is_alive() == false) {
		dead();
	}
	check_stats();
};

void Student::skiping() {
	skip += 1;
	mood += 5;
	energy += 5;
	eat -= 5;
	if (is_alive() == false) {
		dead();
	}
	check_stats();
};

void Student::sleeping() {
	energy += 3;
	hp += 2;
	mood += 10;
	eat -= 5;
	if (is_alive() == false) {
		dead();
	}
	check_stats();
};

void Student::start_game() {
	cin >> name >> surname;
	hp = 100;
	energy = 100;
	mood = 100;
	eat = 100;
	work = 0;
	skip = 0;
	day = 1;

};

void Student::check_stats() {
	if (hp > 100) { hp = 100; }
	else if (hp < 0) { hp = 0; }
	if (energy > 100) { energy = 100; }
	else if (energy < 0) { energy = 0; }
	if (mood > 100) { mood = 100; }
	else if (mood < 0) { mood = 0; }
	if (eat > 100) { eat = 100; }
	else if (eat < 0) { eat = 0; }
};

bool Student::is_alive() {
	if ((hp <= 0) or (energy <= 0) or (mood <= 0) or (eat <= 0)) {
		return false;

	}
	else {
		return true;
	}
};

void Student::show() {
	setlocale(LC_CTYPE, "");
	cout << name << " " << surname << ": Жизни = " << hp << "," << "Энергия =" << energy << "," << "Сытость =" << eat << "," << "Настроение =" << mood << ".";


};

void Student::your_day() {
	int variant = 0;
	cout << "День " << day << ". Что делать?" << endl << "1. Сходить на пары" << endl << "2. Поспать" << endl << "3. Поесть" << endl << "4. Статистика" << endl << endl;
	while (variant != 1 && variant != 2 && variant != 3) {
		cin >> variant;
		if (variant == 4) {
			show();
			cout << endl;
			deduction();
		}
	}
	if (variant == 1) {
		working();
		cout << endl << "Ты сходил на пары" << endl;
	}
	else if (variant == 2) {
		sleeping();
		skiping();
		cout << endl << "Ты поспал" << endl;
	}
	else if (variant == 3) {
		eating();
		cout << endl << "Ты поел" << endl;
		cout << "Пойдёшь на учебу?" << endl << "1. Пойти на пары" << endl << "2. Забить" << endl << endl;
		while (variant != 1 && variant != 2) {
			cin >> variant;
		}
		if (variant == 1) {
			working();
		}
		else {
			skiping();
		}

	}
	day++;
	cout << endl;
	if (day % 10 == 0) {
		if (attestate()) {
			your_day();
		}
	}
	else your_day();


};

void Student::deduction() {
	if (work == 0) {
		if (skip > 0) {
			cout << "Еблан, тебя ни на одной паре еще не было, пиздуй в вуз" << endl << "Ну так что делать?" << endl;
		}
		else {
			cout << "Ты первый день в вузе, хули ты ноешь" << endl << "Ну так что делатЬ?" << endl;
		}
	}
	else {
		state = (float(skip) / float(skip + work));
		if (state > 0.5) {
			cout << "Мнение куратора: Пиздец будет, лучше сходи" << endl << endl << "Ну так что делать?" << endl << endl;
		}
		else {
			cout << "Мнение куратора: Да похуй, пока все ок" << endl << endl << "Ну так что делать?" << endl << endl;
		}
	}
};

bool Student::attestate() {
	float state = float(skip) / float(skip + work);
	if (state > 0.5) {
		cout << "Тебя отчислили, долбоеб." << endl << endl;
		cout << "Game Over" << endl << endl;
		return false;
	}
	else {
		cout << "Ты прошел аттестацию, красава!" << endl << endl;
		return true;
	}
};

void Student::dead() {
	if (hp <= 0) {
		cout << "Ты ложишься спать и на следующий день ты не проснулся. Старина ты дед" << endl << endl;
		cout << "Game Over" << endl << endl;
	}
	else if (energy <= 0) {
		cout << "Из за изнурительного дня ты падаешь на пол и умираешь от потери сил" << endl << endl;
		cout << "Game Over" << endl << endl;
	}
	else if (mood <= 0) {
		cout << "После дня ты понимаешь что жить тебе не за чем и ты вешаешься в своей комнате на шнурках" << endl << endl;
		cout << "Game Over" << endl << endl;
	}
	else if (eat <= 0) {
		cout << "Из за недоедания ты скрючиваешься и падаешь на пол. Глупая смерть." << endl << endl;
		cout << "Game Over" << endl << endl;
	}
	system("pause");
};

void Student::menu() {
	int variant = 0;
	cout << "Добро пожаловать в симулятор студента!" << endl << endl << "1. Начать игру" << endl << "2. Инструкция к игре" << endl << endl;
	while (variant != 1 && variant != 2) {
		cin >> variant;
	}
	if (variant == 1) {
		game();
	}
	else if (variant == 2) {
		instruction();
	}
};

void Student::instruction() {
	int variant = 0;
	cout << "Ваша цель каждый десятый день сдавать зачёты. Для понимая что ты сдашь тест хорошо тебе надо следить за мнение куратора." << endl << "И важно не забывать про другие нужды как сон , еда , здоровье, и настроение. Желаю тебе удачи в этом ужасном мире)" << endl << endl;
	cout << "Нажми 1 чтобы вернуться в меню." << endl << endl;
	while (variant != 1) {
		cin >> variant;
	}
	if (variant == 1) {
		menu();
	}
};

void Student::game() {
	cout << "Для начала введи фамилию и имя персонажа который будет учиться в университете мечты" << endl << endl;
	start_game();
	show();
	your_day();
};

int main()
{
	system("chcp 1251");
	Student caracter;
	caracter.menu();
	return 0;
}
