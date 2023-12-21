#include <conio.h>
#include "Vector.h"

int main() {
	Vector::Vector<char> vec, last_word, no_last_words, help_vec, word, ending, ov, ova, ev, eva, in, ina, idze;
	Vector::Vector<char>::fill_vectors(ov, ova, in, ina, ev, eva, idze);
	char character;
	unsigned flag{};
   
	//Считываем строку
	do {
		character = _getch();
		if (!(((97 <= character) and (character <= 122)) or (character == ' ') or (character == '\b') or (character == '.')))
			continue;
		else if (character == ' ' and (vec.getSize() == 0 or vec[vec.getSize() - 1] == ' ')) {
			_putch(character);
			help_vec.pushBack(character);
			continue;
		}
		else if (character == '\b') {
			if (help_vec.getSize() == 0)
				continue;
			if (vec.getSize() > 1 and vec[vec.getSize() - 1] == ' ')
				vec.popBack();
			if (help_vec[help_vec.getSize() - 1] != ' ')
				vec.popBack();
			help_vec.popBack();
			_putch(character);
			_putch(' ');
			_putch(character);
			continue;
		}
		else if (character == '.') {
			_putch(character);
			continue;
		}
		_putch(character);
		help_vec.pushBack(character);
		vec.pushBack(character);
	} while (character != '.');

	//Если ничего значащего не ввели
	if (vec.getSize() == 0) {
		vec.print();
		exit(0);
	}

	//Приводим строку к виду с пробелом в конце
	if (vec[vec.getSize() - 1] != ' ')
		vec.pushBack(' ');


	vec.getLastWord(last_word);                //   Получаем последнее слово строки
	help_vec.clear();						   //   Очищаем help_vec, чтобы скопировать туда vec
	vec.copy(help_vec);                        //   Копируем вектор vec в help_vec
	help_vec.popBack(last_word.getSize() + 1); //   Удаляем из вектора help_vec последнее слово


	//Записываем в вектор no_last_words слова, отличающиеся от последнего
	while (help_vec.getSize() > 1) {
		help_vec.getLastWord(word);
		if (!(last_word.isEqual(word))) {
			no_last_words.pushBack(word);
			no_last_words.pushBack(' ');
		}
		help_vec.popBack(word.getSize() + 1);
		word.clear();
	}


	//Записываем слова в том порядке, в котором их вводил пользователь, параллельно проверяя окончания
	while (no_last_words.getSize() > 1) {
		no_last_words.getLastWord(word);
		switch (word.getSize()) {
		case 1:
			flag = 1;
			help_vec.pushBack(word);
			help_vec.pushBack(' ');
		case 2:
			if (flag != 1) {
				flag = 2;
				if (word.isEqual(ov) or word.isEqual(in) or word.isEqual(ev))
					help_vec.pushBack(idze);
				else
					help_vec.pushBack(word);
				help_vec.pushBack(' ');
			}
		default:
			if (flag != 1 and flag != 2) {
				word.slice(ending, word.getSize() - 3, word.getSize());
				if (ending.isEqual(ova) or ending.isEqual(ina) or ending.isEqual(eva)) {
					ending.clear();
					word.slice(ending, 0, word.getSize() - 3);
					help_vec.pushBack(ending);
					help_vec.pushBack(idze);
					help_vec.pushBack(' ');
				}
				else {
					ending.clear();
					word.slice(ending, word.getSize() - 2, word.getSize());
					if (ending.isEqual(ov) or ending.isEqual(in) or ending.isEqual(ev)) {
						ending.clear();
						word.slice(ending, 0, word.getSize() - 2);
						help_vec.pushBack(ending);
						help_vec.pushBack(idze);
					}
					else
						help_vec.pushBack(word);
					help_vec.pushBack(' ');
				}
			}
			no_last_words.popBack(word.getSize() + 1);
			word.clear();
			ending.clear();
			flag = 0;
			break;
		}
	}

	std::cout << std::endl;
	help_vec.print();

	return 0;
}








/*
//#include <cstdio>



	//Считываем строку
	do
	{
		character = getchar();
		if (character == ' ' and (vec.getSize() == 0 or vec[vec.getSize() - 1] == ' '))
			continue;
		vec.pushBack(character);
	} while (character != '.');

	//Приводим строку к виду с пробелом в конце
	if (vec[vec.getSize() - 2] == ' ')
		vec.popBack();
	else {
		vec.popBack();
		vec.pushBack(' ');
	}

*/


//const size_t array_size = 6;
//Vector::Vector<char>* endings = new Vector::Vector<char>[array_size] {ov, ova, in, ina, ev, eva};


//size_t space_counter{};

   /* int x = _getch();
	printf("%d", x);*/


	//puts("Введите символ, символ точки - выход('.'):");

 /* Vector::Vector<char> endings[6]{ ov, ova, in, ina, ev, eva };
	for (const auto& w : endings) {
		w.print();
	}*/
	/*
		Сделать считывание слов через рекурсию
		Сделать, чтобы popBack() и pushBack() возвращал значения
	*/


	/* vec.print();
		std::cout << vec.getSize() << ' ' << vec.getCapasity();
		last_word.reverse();
		std::cout << std::endl;
		last_word.print();*/
	/*std::cout << std::endl;
		no_last_words.print();
		std::cout << no_last_words.getSize();
		no_last_words.reset();
		std::cout << std::endl;
		help_vec.pushBack(last_word);
		help_vec.print();
		std::cout << help_vec.getSize();
		std::cout << std::endl;
		help_vec = last_word;
		help_vec.print();
		std::cout << help_vec.getSize();
		std::cout << std::endl;
		last_word.print();
		std::cout << last_word[5] << last_word[4] << last_word[3];
		last_word[5] = '$';
		std::cout << std::endl;
		last_word.print();
		std::cout << last_word.getSize();
		test = last_word.popBack(3);
		std::cout << std::endl;
		test.print();
		std::cout << test.getSize();
		std::cout << std::endl;
		test.clear();
		vec.getLastWord(test);
		test.print();
		std::cout << test.getSize();
		std::cout << std::endl;
		vec.print();*/

		/*ov.reset();
		ova.reset();
		in.reset();
		ina.reset();
		ev.reset();
		eva.reset();*/
		//delete [] endings;