// Игра Guess My Number
// Классическая игра в угадывание чисел

/* УСТАНОВКА ИГРОВЫХ ПАРАМЕТРОВ */
#include <iostream>
#include <cstdlib> // rand()
#include <ctime> // time()
using namespace std;

int main()
{
  srand(static_cast<unsigned int>(time(0))); // запускаем генератор случайных чисел
  int secretNumber = rand() % 100 + 1; // случайное число в диапазоне от 1 до 100
  int tries = 0;
  int guess;
  cout << "\tWelcome to Guess My Number\n\n";


  /* СОЗДАНИЕ ИГРОВОГО ЦИКЛА */
  do {
    cout << "Enter a guess: ";
    cin >> guess;
    ++tries;
    
    if (guess > secretNumber) { 
      cout << "Too high!\n\n";
    } else if (guess < secretNumber) { 
      cout << "Too low!\n\n"; 
    } else {
      cout << "\nThat's it! You got it in " << tries << " guesses!\n";
    }
    
  } while( guess != secretNumber);
  
  /* ЗАВЕРШЕНИЕ ИГРЫ */
  return 0;
}
