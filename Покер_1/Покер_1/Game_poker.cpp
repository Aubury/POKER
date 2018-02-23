#include<iostream>
#include<time.h>
#include<string>
#include<vector>
#include<algorithm>
#include <iomanip>
#include <exception>
using namespace std;

const int RANKS[13] = { 2,3,4,5,6,7,8,9,10,11,12,13,14 };
const char SUITS[4] = { 3,4,5,6 };

//===========================================================================================================

class Deck_of_cards
{
	pair<int, char>tmp;
	vector < pair<int, char>>Deck;
	int size;
public:

	Deck_of_cards() { size = 0; }
	int get_size() { return size; }
	
	void _Deck()
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 13; j++)
			{
				tmp.first = RANKS[j];
				tmp.second = SUITS[i];
				Deck.push_back(tmp);
				size++;
			}
		}
	}
	int Find_card_first(int index)
	{
		if (index < Deck.size())
			return Deck[index].first;

	}
	char Find_card_second(int index)
	{
		if (index < Deck.size())
			return Deck[index].second;

	}
	void Delete_card(int index)
	{
		if (index < Deck.size())
			Deck.erase(Deck.begin() + index);
		size--;
	}

	void Show()
	{
		for (int i = 0; i <size; i++)
		{
			if (0 == (i % 13))
			{
				cout << "\n\n";
			}
			if (Deck[i].first > 10)
			{
				if (Deck[i].first == 11)cout << i + 1 << ")=J" << Deck[i].second << setw(5);
				if (Deck[i].first == 12)cout << i + 1 << ")=Q" << Deck[i].second << setw(5);
				if (Deck[i].first == 13)cout << i + 1 << ")=K" << Deck[i].second << setw(5);
				if (Deck[i].first == 14)cout << i + 1 << ")=A" << Deck[i].second << setw(5);
			}
			else
				
				cout << i + 1 << ")=" << Deck[i].first << Deck[i].second << setw(5);

		}
	}


};
//========================================================================================================

class Bet
{
	int bet;
public:
	Bet() { bet = 20; }
	Bet(int _bet) { bet = _bet; }
	void set_bet(int _bet)
	{
		bet = _bet;
	}
	int get_bet() { return bet; }
	void raise_bet(int _bet)
	{
		int sum = get_bet() + _bet;
		set_bet(sum);
	}
	void Show_bet() { cout << " Money is " << bet << "\n"; }


};
//========================================================================================================
class Player
{
	pair<int, char>tmp1;
	vector<pair<int, char >> player;
	int size;
	Bet obj;

public:
	Player() { size = 0; }
	Player(int _bet) : obj(_bet) {};
	int get_size() { return size; }
	int find_card_first(int index)
	{
		if (index < player.size())
			return player[index].first;
	}
	char find_card_second(int index)
	{
		if (index < player.size())
			return player[index].second;

	}
	void Give_card_to_player(Deck_of_cards &Deck)
	{
		int index = 1 + rand() % Deck.get_size() - 1;

		for (int i = 0; i <Deck.get_size(); i++)
		{
			tmp1.first = Deck.Find_card_first(index);
			tmp1.second = Deck.Find_card_second(index);
			break;
		}

		Deck.Delete_card(index);

		player.push_back(tmp1);
		size++;

	}


	void Show_cards()
	{
		sort(player.begin(), player.end());

		for (int i = 0; i <player.size(); i++)
		{
			if (player[i].first > 10)
			{
				if (player[i].first == 11) { cout << setw(2) << i + 1 << ")= J" << player[i].second << "\n"; }
				if (player[i].first == 12) { cout << setw(2) << i + 1 << ")= Q" << player[i].second << "\n"; }
				if (player[i].first == 13) { cout << setw(2) << i + 1 << ")= K" << player[i].second << "\n"; }
				if (player[i].first == 14) { cout << setw(2) << i + 1 << ")= A" << player[i].second << "\n"; }
			}

			else
			{
				cout <<i + 1 << ") = " << player[i].first << player[i].second << "\n ";
			}
		}
	}
	void Show_one_card()
	{
		sort(player.begin(), player.end());
for (int i = 0; i < player.size(); i++)
{
	if (player[i].first > 10)
	{
		if (player[i].first == 11)
		{
			cout << "============\n";
			cout << "|J" << player[i].second << setw(10) << "|\n";
			cout << "|" << setw(12) << "|\n";
			cout << "|" << setw(12) << "|\n";
			cout << "|" << setw(6) << player[i].second << setw(6) << "|\n";
			cout << "|" << setw(12) << "|\n";
			cout << "|" << setw(12) << "|\n";
			cout << "|" << setw(9) << "J" << player[i].second << "|\n";
			cout << "============\n";
		}
		if (player[i].first == 12)
		{
			cout << "============\n";
			cout << "|Q" << player[i].second << setw(10) << "|\n";
			cout << "|" << setw(12) << "|\n";
			cout << "|" << setw(12) << "|\n";
			cout << "|" << setw(6) << player[i].second << setw(6) << "|\n";
			cout << "|" << setw(12) << "|\n";
			cout << "|" << setw(12) << "|\n";
			cout << "|" << setw(9) << "Q" << player[i].second << "|\n";
			cout << "============\n";
		}
		if (player[i].first == 13)
		{
			cout << "============\n";
			cout << "|K" << player[i].second << setw(10) << "|\n";
			cout << "|" << setw(12) << "|\n";
			cout << "|" << setw(12) << "|\n";
			cout << "|" << setw(6) << player[i].second << setw(6) << "|\n";
			cout << "|" << setw(12) << "|\n";
			cout << "|" << setw(12) << "|\n";
			cout << "|" << setw(9) << "K" << player[i].second << "|\n";
			cout << "============\n";
		}
		if (player[i].first == 14)
		{
			cout << "============\n";
			cout << "|A" << player[i].second << setw(10) << "|\n";
			cout << "|" << setw(12) << "|\n";
			cout << "|" << setw(12) << "|\n";
			cout << "|" << setw(6) << player[i].second << setw(6) << "|\n";
			cout << "|" << setw(12) << "|\n";
			cout << "|" << setw(12) << "|\n";
			cout << "|" << setw(9) << "A" << player[i].second << "|\n";
			cout << "============\n";
		}
	}

	else
	{
		cout << "============\n";
		cout << "|" << player[i].first << player[i].second << setw(10) << "|\n";
		cout << "|" << setw(12) << "|\n";
		cout << "|" << setw(12) << "|\n";
		cout << "|" << setw(6) << player[i].second << setw(6) << "|\n";
		cout << "|" << setw(12) << "|\n";
		cout << "|" << setw(12) << "|\n";
		cout << "|" << setw(9) << player[i].first << player[i].second << "|\n";
		cout << "============\n";
	}
}

	}
	void set_Bet(int money)
	{
		obj.set_bet(money);
	}
	int get_Bet()
	{
		return obj.get_bet();
	}
	void show_Bet()
	{
		obj.Show_bet();
	}
	void Raise_bet(int _bet)
	{
		obj.raise_bet(_bet);
	}
	//=========================================================================================================================
	int High_card()
	{
		for (int i = player.size(); i > 0; i--)
		{
			return player[i].first;
		}
			
	}
//===============================================================================================================
	bool One_Pair()//одна пара
	{
		for (int i = 0; i < player.size(); ++i)
		{
			for (int j = i + 1; j < player.size(); ++j)
			{
				if (player[i].first == player[j].first)
				{
					return true;
				}
			}
		}
		return false;
	}
//--------------------------------------------------------------------------------------------------------------------------
	int _One_Pair()//одна пара
	{
		for (int i = 0; i < player.size(); ++i)
		{
			for (int j = i + 1; j < player.size(); ++j)
			{
				if (player[i].first == player[j].first)
				{
					return player[i].first;
				}
			}
		}
	}
//================================================================================================================
	bool Two_Pair()//две пары
	{
		int pair1 = 0;
		int pair2 = 0;
		int pos = 0;

		for (int i = 0; i < player.size(); ++i)
		{
			for (int j = i + 1; j < player.size(); ++j)
			{
				if (player[i].first == player[j].first && !pair1) { pair1 = 1; pos = i + 2; }
				else if (pair1 == 1)
					i = 4;
			}
		}
		if (pair1 == 1 && pos < player.size())
		{
			for (int i = pos; i < player.size(); ++i)
			{
				for (int j = i + 1; j < player.size(); ++j)
				{
					if (player[i].first == player[j].first) return true;
				}
			}
		}


		return false;
	}
//----------------------------------------------------------------------------------------------------------------------
	int _Two_Pair()//две пары
	{
		int pair1 = 0;
		int pair2 = 0;
		int pos = 0;

		for (int i = 0; i < player.size(); ++i)
		{
			for (int j = i + 1; j < player.size(); ++j)
			{
				if (player[i].first == player[j].first && !pair1) { pair1 = 1; pos = i + 2; }
				else if (pair1 == 1)
					i = 4;
			}
		}
		if (pair1 == 1 && pos < player.size())
		{
			for (int i = pos; i < player.size(); ++i)
			{
				for (int j = i + 1; j < player.size(); ++j)
				{
					if (player[i].first == player[j].first) return player[i].first;
				}
			}
		}
	}
//=========================================================================================================================
	bool Three_of_a_kind()//три карты одного ранга
	{
		int count = 0;
		for (int i = 0; i < player.size()-2; ++i)
		{
			if (count != 0)count = 0;
			for (int j = i + 1; j < player.size(); j++)
			{
				if (player[i].first == player[j].first)count++;
				if (count == 3)return true;
			}
		}
		return false;
	}
//--------------------------------------------------------------------------------------------------------------------------
	int _Three_of_a_kind()//три карты одного ранга
	{
		for (int i = 0; i < player.size()-2; i++)
		{
	        if (player[i].first == player[i + 1].first == player[i + 2].first) return player[i + 2].first;
		}
     }
//=========================================================================================================================
	bool Four_of_a_Kind()//четыре карты одного ранга
	{
		int count = 0;
		for (int i = 0; i < 2; ++i)
		{
			if (count != 0)count = 0;
			for (int j = i + 1; j < player.size(); j++)
			{
				if (player[i].first == player[j].first) count++;
				if (count == 4)return true;
			}

		}
		return false;
	}
//================================================================================================================================
	bool Straight()//5 карт подряд
	{
		int i = 0;
		if ((player[i].first + 1) == player[i + 1].first &&
			(player[i + 1].first + 1) == player[i + 2].first &&
			(player[i + 2].first + 1) == player[i + 3].first &&
			(player[i + 3].first + 1) == player[i + 4].first &&
			(player[i + 4].first + 1) == player[i + 5].first)return true;
		else
			return false;
	}
//------------------------------------------------------------------------------------------------------------------------------
	int  _Straight()//5 карт подряд
	{
		int i = 0;
		if ((player[i].first + 1) == player[i + 1].first &&
			(player[i + 1].first + 1) == player[i + 2].first &&
			(player[i + 2].first + 1) == player[i + 3].first &&
			(player[i + 3].first + 1) == player[i + 4].first &&
			(player[i + 4].first + 1) == player[i + 5].first)return player[i + 5].first;
		
	}
//==============================================================================================================================
	bool Flush()//все карты одной масти
	{
		int i = 0;
		if (player[i].second == player[i + 1].second ==
			player[i + 2].second == player[i + 3].second ==
			player[i + 4].second)return true;
		else
			return false;
	}
//===============================================================================================================================
	bool Full_House()//три карты одной ранга + две карты другой ранга
	{
		int i = 0;
		if (player[i].first == player[i + 1].first == player[i + 2].first
			&& player[i + 3].first == player[i + 4].first)return true;
		if (player[i].first == player[i + 1].first 
			&& player[i + 2].first==player[i + 3].first == player[i + 4].first)return true;
		else
			return false;

	}
//========================================================================================================================	
	bool Straight_flush()
	{
		if (Flush() == true && Straight() == true)return true;
		else return false;
	}
//=========================================================================================================================
	bool Royal_Flush()
	{
		int i = 0;
			if (player[i].first == 10 &&player[i + 1].first == 11 &&
				player[i + 2].first == 12 &&player[i + 3].first == 13&&
				player[i].first == 14 && Flush() == true)return true;

		else
		return false;
	}
//==========================================================================================================================
	string Find_winner()
	{
		int count = 0;
		count++; if (Royal_Flush() == 1) return "<Royal_Flush>";
		count++; if (Straight_flush() == 1) return "<Straight Flush>";
		count++; if (Four_of_a_Kind() == 1) return "<Four of a Kind>";
		count++; if (Full_House() == 1) return "<Full House>";
		count++; if (Flush() == 1) return "<Flush>";
		count++; if (Straight() == 1) return "<Straight>";
		count++; if (Three_of_a_kind() == 1) return "<Three of a kind>";
		count++; if (Two_Pair() != 0) return "<Two pair>";
		count++; if (One_Pair() != 0)return "<One pair>";
		else
			return "<Is not a winning set of cards>";

	}
//-----------------------------------------------------------------------------------------------------------------------
	int Find_winner_int()
	{
		int count = 0;
	    count++; if (Royal_Flush() == 1) return count;
		count++; if (Straight_flush() == 1) return count;
		count++; if (Four_of_a_Kind() == 1) return count;
		count++; if (Full_House() == 1) return count;
		count++; if (Flush() == 1) return count;
		count++; if (Straight() == 1) return count;
		count++; if (Three_of_a_kind() == 1)return count;
		count++; if (Two_Pair() != 0) return count;
		count++; if (One_Pair() != 0)return count;
		else
		return 10;
	}
//------------------------------------------------------------------------------------------------------------------------
	int Who_did_win(Player &comp)
	{
		if (this->Find_winner_int() == 10 && comp.Find_winner_int() == 10)//если нет выигрышной комбинации смотким старшую карту
		{
			if (this->find_card_first(5) == comp.find_card_first(5))
			{
				if (this->find_card_first(4) == comp.find_card_first(4))
				{
					if (this->find_card_first(3) == comp.find_card_first(3))
					{
						if (this->find_card_first(2) == comp.find_card_first(2))
						{
							if (this->find_card_first(1) > comp.find_card_first(1))
							{
								cout << "I won!";
								cout << "My money = " << this->get_Bet() + comp.get_Bet() << "$\n";
								return this->find_card_first(1);
							}
							else
							{
								cout << "Comp won!";
								cout << "Comp money = " << this->get_Bet() + comp.get_Bet() << "$\n";
								return comp.find_card_first(1);
							}
						}
						if (this->find_card_first(2) > comp.find_card_first(2))
						{
							cout << "I won!";
							cout << "My money = " << this->get_Bet() + comp.get_Bet() << "$\n";
							return this->find_card_first(2);
						}
						else
						{
							cout << "Comp won!";
							cout << "Comp money = " << this->get_Bet() + comp.get_Bet() << "$\n";
							return comp.find_card_first(2);
						}
					}
					if (this->find_card_first(3) > comp.find_card_first(3))
					{
						cout << "I won!";
						cout << "My money = " << this->get_Bet() + comp.get_Bet() << "$\n";
						return this->find_card_first(3);
					}
					else
					{
						cout << "Comp won!";
						cout << "Comp money = " << this->get_Bet() + comp.get_Bet() << "$\n";
						return comp.find_card_first(3);
					}
				}
				if (this->find_card_first(4) > comp.find_card_first(4))
				{
					cout << "I won!";
					cout << "My money = " << this->get_Bet() + comp.get_Bet() << "$\n";
					return this->find_card_first(4);
				}
				else
				{
					cout << "Comp won!";
					cout << "Comp money = " << this->get_Bet() + comp.get_Bet() << "$\n";
					return comp.find_card_first(4);
				}
		    }
			if (this->find_card_first(5) > comp.find_card_first(5))
			{
				cout << "I won!";
				cout << "My money = " << this->get_Bet() + comp.get_Bet() << "$\n";
				return this->find_card_first(5);
			}
			else
			{
				cout << "Comp won!";
				cout << "Comp money = " << this->get_Bet() + comp.get_Bet() << "$\n";
				return comp.find_card_first(5);
			}
		}
		else
		if (this->One_Pair()==1 && comp.One_Pair() ==1)//если по одной паре 
		{
			if (this->_One_Pair() > comp._One_Pair())
			{
				cout << "I won!";
				cout << "My money = " << this->get_Bet() + comp.get_Bet() << "$\n";
				return this->_One_Pair();
			}
			else
			{
				cout << "Comp won!";
				cout << "Comp money = " << this->get_Bet() + comp.get_Bet() << "$\n";
				return comp._One_Pair();
			}
		}
		else
			if (this->Two_Pair()==1 && comp.Two_Pair() ==1)//если по две пары
			{
				if (this->_Two_Pair() > comp._Two_Pair())
				{
					cout << "I won!";
					cout << "My money = " << this->get_Bet() + comp.get_Bet() << "$\n";
					return this->Two_Pair();
				}
				else
				{
					cout << "Comp won!";
					cout << "Comp money = " << this->get_Bet() + comp.get_Bet() << "$\n";
					return comp.Two_Pair();
				}
			}
			else
				if (this->Three_of_a_kind() == 1 && comp.Three_of_a_kind() == 1)//если по три одинаковые ранга
				{
					if (this->_Three_of_a_kind() > comp._Three_of_a_kind())
					{
						cout << "I won!";
						cout << "My money = " << this->get_Bet() + comp.get_Bet() << "$\n";
						return this->_Three_of_a_kind();
					}
					else
					{
						cout << "Comp won!";
						cout << "Comp money = " << this->get_Bet() + comp.get_Bet() << "$\n";
						return comp._Three_of_a_kind();
					}
				}
			else
				if (this->Straight() == 1 && comp.Straight() == 1)
				{
					if (this->_Straight() > comp._Straight())
					{
						cout << "I won!";
						cout << "My money = " << this->get_Bet() + comp.get_Bet() << "$\n";
						return this->_Straight();
					}
					else
					{
						cout << "Comp won!";
						cout << "Comp money = " << this->get_Bet() + comp.get_Bet() << "$\n";
						return comp._Straight();
					}
				}
		
				
	}

};


//====================================================================================================================
void main()
{
	srand(time(0));
	Deck_of_cards obj;
	obj._Deck();
	cout << "\n";
	cout << "\t\t\tDECK OF CARD.\n";
	obj.Show();
	cout << "\n";
	cout << "=============================================================================================================\n\n";

	char answer;
	char n, y;
	cout << "\t\tDo you want to play poker?\n\n";
	cout << "Press 'y' if 'yes' or 'n' if 'no'.\n"; cin >> answer;

	if (answer == 'n') cout << "Bye!Bye!\n";
	else
		do
		{
			system("cls");
			Player my;
			Player comp;
			int money = 0;
			cout << "\n";
			cout << "You are bets: "; cin >> money;

			my.set_Bet(money);
			comp.set_Bet(money);

			for (int i = 1; i <= 2; i++)
			{
				my.Give_card_to_player(obj);
			}
			for (int i = 1; i <= 2; i++)
			{
				comp.Give_card_to_player(obj);
			}

			cout << "\n\n";
			cout << "\tMy cards.\n";
			my.Show_cards();
			//my.Show_one_card();
			cout << "\n";
			cout << "---------------------------------------------------------------------------------------------------------------\n\n";
			cout << "\tComp cards.\n";
			comp.Show_cards();
			cout << "\n";
			cout << "================================================================================================================\n\n";
			//--------------------------------------------------------------------------------------------------------------				
			int check;
			cout << " Do you want to continue the game? "; cin >> answer;
			if (answer == 'n')
			{
				cout << "Comp won!\n";
				cout << "Comp money = " << my.get_Bet() + comp.get_Bet() << "$\n";
				cout << "Bye!Bye!\n";
			}
			else
			{
				cout << "If you want to skip bet, press : 1\n";
				cout << "If you want to raise your bet, press : 2\n";
				cin >> check;
				switch (check)
				{
				case 1: {
					my.Raise_bet(0);
					comp.Raise_bet(0);
				}break;
				case 2: {
					int new_bet = 0;
					cout << "Input new bet "; cin >> new_bet;
					my.Raise_bet(new_bet);
					comp.Raise_bet(new_bet);
				}break;
				}

			}

			//-----------------------------------------------------------------------------------------------------------------
			for (int i = 1; i <= 3; i++)
			{
				my.Give_card_to_player(obj);
			}
			for (int i = 1; i <= 3; i++)
			{
				comp.Give_card_to_player(obj);
			}
			cout << "================================================================================================================\n\n";
			cout << "\tMy cards.\n";
			my.Show_cards();
			//my.Show_one_card();
			cout << "\n\n";
			cout << "My set of cards :" << my.Find_winner() << "\n";
			cout << "-----------------------------------------------------------------------------------------------------------------\n\n";
			cout << "\tComp cards.\n";
			comp.Show_cards();
			//comp.Show_one_card();
			cout << "\n\n";
			cout << "Comp set of cards :" << comp.Find_winner() << "\n";
			cout << "================================================================================================================\n\n";

			if (my.Find_winner_int() == comp.Find_winner_int())
			{
				cout<<my.Who_did_win(comp);
			}
				

			if (my.Find_winner_int() < comp.Find_winner_int())
			{

				cout << "I won!";
				cout << "My money = " << my.get_Bet() + comp.get_Bet() << "$\n";
			}
            else
			if (my.Find_winner_int() > comp.Find_winner_int())
			
			{
				cout << "Comp won!";
				cout << "Comp money = " << my.get_Bet() + comp.get_Bet() << "$\n";
			}

			cout << "\n\n";
			cout << "Do you want to play again?"; cin >> answer;

		} while (answer == 'y');
}


