#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() 
{

  /* ВЫБОР СЛОВА ДЛЯ ПЕРЕМЕШИВАНИЯ */
  enum fields {WORD, HINT, NUM_FIELDS};
  const int NUM_WORDS = 5;
  const string WORDS[NUM_WORDS][NUM_FIELDS] = {
    {"wall", "Album of Pink Floyd: \"The ...\""},
    {"glasses", "Lets drink!"},
    {"butterfly", "Caterpillar, then cocoon, then this beauty :)"},
    {"student", "Study at the university"},
    {"jumble", "It's what the game is all about"}
  };

  srand(static_cast<unsigned int>(time(0)));
  int choice = (rand() % NUM_WORDS);
  string theWord = WORDS[choice][WORD]; // слово, которое нужно угадать
  string theHint = WORDS[choice][HINT]; // подсказка для слова

  /* ПЕРЕМЕШИВАНИЕ СЛОВА */
  string jumble = theWord; // перемешанный вариант слова
  int length = jumble.size();
  for (int i = 0; i < length; ++i)
  {
    int index1 = (rand() % length);
    int index2 = (rand() % length);
    char temp = jumble[index1];
    jumble[index1] = jumble[index2];
    jumble[index2] = temp;
  }

  /* ПРИГЛАШЕНИЕ ИГРОКА */
  cout << "\t\tWelcome to Word Jumble!\n\n";
  cout << "Unscramle the letters to make a word.\n";
  cout << "Enter 'hint' for a hint.\n";
  cout << "Enter 'quit' to quit the game.\n\n";
  cout << "The jumble is: " << jumble;
  string guess;
  cout << "\n\nYour guess: ";
  cin >> guess;

  /* НАЧАЛО ИГРОВОГО ПРОЦЕССА */
  while ((guess != theWord) && (guess != "quit"))
  {
    if (guess == "hint") {
      cout << theHint;
    } else {
      cout << "Sorry, that's not it.";
    }
    cout << "\n\nYour guess: ";
    cin >> guess;
  }
  
  /* КОНЕЦ ИГРЫ */
  if (guess == theWord) {
    cout << "\nThat's it! You guessed it!\n";
  }
  cout << "\nThanks for playing.\n";
  
  return 0;
}
