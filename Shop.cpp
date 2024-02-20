#include "Shop.h"
#include "dirent.h"
Shop::Shop()
{
	type = false;
	DairyProductsNumber = 0;
	MeatProductsNumber = 0;
	idMax = 0;
	ifstream myfile("products.bin");
	std::ifstream infile("products.bin", ios::in | ios::binary);
	string t,s1, s2, s3, s4, s5;
	while (infile >>t>> s1 >> s2 >> s3 >> s4 >> s5)
	{
		if (t == "D")
		{
			DairyProducts d;
			d.setId(atoi(s1.c_str()));
			d.setName(s2);
			d.setPrice(atoi(s3.c_str()));
			d.setExpireDate(s4);
			d.setFatPercent(atoi(s5.c_str()));
			add_Dairy(d);
			idMax++;
		}
		if (t == "M")
		{
			MeatProducts m;
			m.setId(atoi(s1.c_str()));
			m.setName(s2);
			m.setPrice(atoi(s3.c_str()));
			m.setExpireDate(s4);
			m.setType(atoi(s5.c_str()));
			add_Meat(m);
			idMax++;
		}
	}
	infile.close();
	 

}

bool Shop::getType()
{
	return type;
}

int Shop::getIdMax()
{
	return this->idMax;
}

void Shop::printType()
{
	cout << "Shop" << endl;
}

void Shop::add_Dairy(DairyProducts product)
{
	DairyProducts x =  DairyProducts();
	x.setPrice(product.getPrice());
	x.setExpireDate(product.getExpireDate());
	x.setFatPercent(product.getFatPercent());
	x.setName(product.getName());
	x.setId(product.getId());
	 
	 
	 

	dairy.insert(dairy.begin() + DairyProductsNumber,x);
	DairyProductsNumber++;
	idMax++;
	
}

void Shop::add_Meat(MeatProducts product)
{

	MeatProducts x = MeatProducts();
	x.setPrice(product.getPrice());
	x.setExpireDate(product.getExpireDate());
	x.setType(product.getType());
	x.setName(product.getName());
	x.setId(product.getId());
 
	 

	meat.insert(meat.begin() + MeatProductsNumber, x);
	MeatProductsNumber++;
	idMax++;
	
}

void Shop::edit(int id)
{ 
	for(int i=0;i<DairyProductsNumber;i++)
		if (dairy[i].getId() == id)
		{
			cout << "Alege ce sa editezi la produsul  " <<dairy[i].getName()<< endl;
			int x;
			cout << "1.Nume " << endl;
			cout << "2.Pret " << endl;
			cout << "Optiune: ";
			cin >> x;
			if (x == 1)
			{
				string str;
				cout << "Noul nume :";
				cin >> str;
				
				dairy[i].setName(str.c_str());
			}
			else if (x == 2)
			{
				int pr;
				cout << "Noul pret :";
				cin >> pr;
				dairy[i].setPrice(pr);
			}
			else
				cout << "Alegere incorecta" << endl;
				 

		}
	
	 
	 
		for(int i=0;i<MeatProductsNumber;i++)
		if (meat[i].getId() == id)
		{
			cout << "Alege ce sa editezi la produsul " << meat[i].getName()<< endl;
			int x;
			cout << "1.Nume" << endl;
			cout << "2.Pret" << endl;
			cout << "Optiune: ";
			cin >> x;
			if (x == 1)
			{
				string str;
				cout << "Noul nume :";
				cin >> str;

				meat[i].setName(str.c_str());
			}
			else if (x == 2)
			{
				int pr;
				cout << "Noul pret :";
				cin >> pr;
				meat[i].setPrice(pr);
			}
			else
				cout << "Alegere gresita" << endl;

		}
	

}

Shop::~Shop()
{
}

void Shop::delete_product(int id)
{
	 for(int i=0;i<DairyProductsNumber;i++)
		if (dairy[i].getId() == id)
		{
			dairy.erase(dairy.begin() + i);
			DairyProductsNumber--;
			idMax--;

		}
	 
	 for (int i = 0; i < MeatProductsNumber; i++)
		if (meat[i].getId() == id)
		{
			meat.erase(meat.begin() + i);
			MeatProductsNumber--;
			idMax--;
		}
		 
		
}

void Shop::waitingCommands()
{ 
	 struct dirent *d;
    DIR *dr;
	int ctr = 0;
    dr = opendir("WaitingOrders/");
    if(dr!=NULL)
    {
         
        for(d=readdir(dr); d!=NULL; d=readdir(dr))
        {	
			ctr++;
			if(ctr>=3)
			{
				 
				string filename = "WaitingOrders/" + (string)d->d_name;
				 
				FILE* f = fopen(filename.c_str(), "r");
				fseek(f, 0, SEEK_END);
				int len = 0;
				len=ftell(f);
				rewind(f);
				char *str=(char*)malloc(len);
				 
				fread(str, 1, len, f);
				str[len] = '\0';
				cout << str <<endl;
				cout << "Comanda procesata" << endl;
				fclose(f);
				remove(filename.c_str());

				FILE* g = fopen("comenzi.bin", "ab");
				fprintf(g, "\n---\n");
				fwrite(str, 1, len, g);
				fprintf(g, "\n---\n");
				fclose(g);
			}
			 
		}
        closedir(dr);
    }
    else
        cout<<"\nEroare!";
    cout<<endl;

}

 

void Shop::saveProductsInFile()
{
	ofstream myfile("products.bin", ios::out | ios::binary);
	for (int i = 0; i < DairyProductsNumber; i++)
		myfile <<"D "<< dairy[i].getId() << " " << dairy[i].getName() << " " << dairy[i].getPrice() << " " << dairy[i].getExpireDate() << " " << dairy[i].getFatPercent() << endl;
	for (int i = 0; i < MeatProductsNumber; i++)
		myfile <<"M " << meat[i].getId() << " " << meat[i].getName() << " " << meat[i].getPrice() << " " << meat[i].getExpireDate() << " " << meat[i].getType() << endl;
	myfile.close();
}
