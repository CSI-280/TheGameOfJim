#include "roomOne.h"

int main()
{
	start();
	string choice;
	bool test = false;
	while (test != true)
	{
		choice = getChoice();
		if (choice == "Walk")
		{

		}
		else if (choice == "Stay")
		{
		}
		else
		{
			cout << "I am sorry there was an error please try again." << endl;
		}
	}

}

void start()
{
	cout << "You wake up!" << endl;
	cout << "You find yourself alone in a dark room./nScared you get up and look around." << endl;
	cout << "It is so dark you can barely see 5 feet in front of you but you think from the breeze on your face you are outside." << endl;
	cout << "How you got here and where you go next is what you must find out." << endl;
}

string getChoice()
{
	string choice, choiceTranslated;
	int counter = 0;
	bool test = false;
	cout << "You realize you must now make a choice; you can stay here and wait until morning, or you can try to navigate your way through the dark." << endl;
	while (test != true)
	{
		cout << "Would you like to walk around trying to find your way through the dark? (y/n): ";
		cin >> choice;
		cout << endl;
		counter++;
		if (choice == "y" || choice == "Y" || choice == "yes" || choice == "Yes")
		{
			choiceTranslated = "Walk";
			test = true;
		}
		else if (choice == "n" || choice == "N" || choice == "no" || choice == "No")
		{
			cout << "So you would like to sit and wait here? (y/n)";
			cin >> choice;
			cout << endl;

			if (choice == "y" || choice == "Y" || choice == "yes" || choice == "Yes")
			{
				choiceTranslated = "Stay";
				test = true;
			}
			else if (choice == "n" || choice == "N" || choice == "no" || choice == "No")
			{
				if (counter == 1)
				{
					cout << "Indecisive huh? I'll ask again." << endl;
				}
				else if (counter == 2 || counter == 3)
				{
					cout << "You are really rying to test my patience." << endl;
				}
				else if (counter == 4)
				{
					cout << "Thats it I am done, you are mean." << endl;
					system("pause");
				}		
			}
			else
			{
				cout << "Sorry, there must have been an error with your entry, I will ask again." << endl;
			}
		}
		else
		{
			cout << "Sorry, there must have been an error with your entry, I will ask again." << endl;
		}
	}

	return choiceTranslated;
}
