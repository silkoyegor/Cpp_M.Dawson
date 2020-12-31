// Игра Guess My Number
// Классическая игра в угадывание чисел
// Вы загадываете число, а компьютер угадывает

/* УСТАНОВКА ИГРОВЫХ ПАРАМЕТРОВ */
#include <iostream>
#include <cstdlib> // rand()
#include <ctime> // time()
using namespace std;

int main()
{
  int secretNumber; // число, вводимое пользователем в диапазоне от 1 до 100
  int tries = 0;
  int min_guess = 1;
  int max_guess = 100;
  int guess;
  cout << "\tWelcome to Guess Your Number\n\n";
  
  cout << "Choose number from 0 to 100: ";
  cin >> secretNumber;

  /* СОЗДАНИЕ ИГРОВОГО ЦИКЛА */
  do {
      
    guess = ( (max_guess - min_guess) / 2 ) + min_guess;
    cout << "Computer entered:  " << guess << "\n";
    ++tries;

    if (guess > secretNumber) { 
      max_guess = guess;
      cout << "Too high!\n\n";
    } else if (guess < secretNumber) { 
      min_guess = guess; 
      cout << "Too low!\n\n"; 
    } else {
      cout << "\nThat's it! Computer did it in " << tries << " guesses!\n";
    } 

  } while( guess != secretNumber);
  
  /* ЗАВЕРШЕНИЕ ИГРЫ */
  return 0;
}
