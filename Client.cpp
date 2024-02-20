#include "Client.h"
#include <regex>
 
Client::Client()
{
	type=true;
	basketProducts = 0;
	finalPrice = 0;
}
 
bool Client::getType()
{
	return type;
}

void Client::printType()
{
 
		cout << "Client"<<endl;
	 
}

void Client::printProducts()
{
	 
	std::ifstream infile("products.bin" ,ios::in | ios::binary);
	string m,s1, s2, s3, s4, s5;
	while (infile >>m>> s1 >> s2 >> s3 >> s4 >> s5)
	{
		cout << s1 << "   " << s2<< "   " << s3<< "    " <<s4<< "   " << s5<< endl;
	}
	cout << endl;
	infile.close();

}

void Client::addToBasket(int id,int number)
{

	std::ifstream infile("products.bin", ios::in | ios::binary);
	string m,s1, s2, s3, s4, s5;
	string prod;
	
	while (infile >>m>> s1 >> s2 >> s3 >> s4 >> s5)
	{
		if (atoi(s1.c_str()) == id) {
			 
			prod = to_string(number) + "x" + s2 + "   " + to_string(number * atoi(s3.c_str())) + " RON";
		 
			basket.insert(basket.begin() + basketProducts, prod);
			basketProducts++;
			finalPrice += number*atoi(s3.c_str());
		}
		}
	infile.close();
}

void Client::removeFromBasket(int elem)
{
	if (elem > basketProducts)
	{
		cout << "Element inexistent"<<endl;
		return;
	}
	 
	string input = basket[elem - 1].substr(basket[elem - 1].length() - 10);
	 
	 
	std::string output = std::regex_replace(
		input,
		std::regex("[^0-9]*([0-9]+).*"),
		std::string("$1")
	);
	basket.erase(basket.begin() + elem-1);
	basketProducts--;
	finalPrice -= atoi(output.c_str());
		
}

void Client::sendOrder()
{
	string nume,adresa,telefon;
	cout << "Pentru a finaliza comanda introduceti" << endl;
	cout << "Numele ";
	cin >> nume;
	cout << "Adresa ";
	cin >> adresa;
	cout << "Telefon ";
	cin >> telefon;
	ifstream nrfile("nr.txt", ios::in);
	string nr;
	nrfile >> nr;
	nrfile.close();
	ofstream myfile("WaitingOrders/"+nr+".txt", ios::out | ios::trunc | ios::binary);
	myfile <<"Nume: " << nume << " Adresa: " << adresa << " Telefon: " << telefon<<endl;
	for (int i = 0; i < basketProducts; i++)
		myfile << basket[i].c_str()<<endl;
	
	myfile << "Total " << finalPrice << endl<<endl;
	int next = atoi(nr.c_str());
	next++;
	ofstream nextfile("nr.txt", ios::out | ios::trunc);
	nextfile << next;
	nextfile.close();

}

void Client::preview()
{
	for (int i = 0; i < basketProducts; i++)
		cout<< basket[i].c_str()<< endl;

	cout << "Total " << finalPrice << endl<<endl;
}

Client::~Client()
{
}
