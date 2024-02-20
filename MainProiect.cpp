#include <iostream>
using namespace std;
#include "Client.h"
#include "IPerson.h"
#include "DairyProducts.h"
#include "Shop.h"

int main()
{
     
    int x;
   
    cout << "1.Client"<<endl;
    cout << "2.Magazin" << endl;
    cout << "Optiune: " << endl;
    cin >> x;
    if (x == 1)
    {
        system("cls");
        x = 0;
        Client client = Client();
        while (x != 6) {
            
            cout << "1.Vizualizeaza produse " << endl;
            cout << "2.Pune in cos" << endl;
            cout << "3.Scoate din cos" << endl;
            cout << "4.Vizualizeaza comanda" << endl;
            cout << "5.Trimite comanda" << endl;
            cout << "6.Iesi" << endl;
            cin >> x;
            system("cls");
            if (x == 1)
                client.printProducts();
            else if (x == 2) {
                int id, number;
                cout << "ID-ul produsului ";
                cin >> id;
                cout << "Cantitatea ";
                cin >> number;
                client.addToBasket(id, number);

            }
            else if (x == 3)
            {
                int e;
                cout << "Numarul elementului";
                cin >> e;
                client.removeFromBasket(e);
            }
            else if (x == 4)
            {
                client.preview();
            }
            else if (x == 5)
            {
                client.sendOrder();
                x = 6;
                cout << "Multumim pentru comanda!" << endl;
            }
            
        }

       }
    else if (x == 2)
    {
        system("cls");
        Shop shop = Shop();
        x = 0;
        while (x != 6)
        {
            cout << "1.Adauga produs" << endl;
            cout << "2.Editeaza produs" << endl;
            cout << "3.Sterge produs" << endl;
            cout << "4.Comenzi in asteptare" << endl;
            cout << "5.Salveaza modificarile" << endl;
            cout << "6.Iesi" << endl;

            cin >> x;
            system("cls");
            if (x == 1)
            {
                int y;
                cout << "1.Lactate"<<endl;
                cout << "2.Carne"<<endl;
                cin >> y;
                if (y == 1) {
                    system("cls");
                    DairyProducts d;
                    string str;
                    d.setId(shop.getIdMax());
                    cout << "Numele produsului ";
                    cin >> str;
                    d.setName(str);
                    cout << "Pret ";
                    cin >> str;
                    d.setPrice(atoi(str.c_str()));
                    cout << "Data expirare ";
                    cin >> str;
                    d.setExpireDate(str);
                    cout << "Procent grasime ";
                    cin >> str;
                    d.setFatPercent(atoi(str.c_str()));
                    shop.add_Dairy(d);
                    system("cls");

                }
                else if(y==2)
                {
                    system("cls");
                    MeatProducts d;
                    string str;
                    d.setId(shop.getIdMax());
                    cout << "Nume produs ";
                    cin >> str;
                    d.setName(str);
                    cout << "Pret ";
                    cin >> str;
                    d.setPrice(atoi(str.c_str()));
                    cout << "Data expirare ";
                    cin >> str;
                    d.setExpireDate(str);
                    cout << "Tip 0-Pui 1-Vita 2-Porc ";
                    cin >> str;
                    d.setType(atoi(str.c_str()));
                    shop.add_Meat(d);
                    system("cls");

                }
              }
            if (x == 2)
            {
                int y;
                cout << "ID de modificat ";
                cin >> y;
                shop.edit(y);
            }
            if (x == 3)
            {
                int y;
                cout << "ID de sters ";
                cin >> y;
                shop.delete_product(y);
            }
            if (x == 4)
            {
                shop.waitingCommands();
            }
            if (x == 6)
            {
                cout << "La revedere!";
            }
            if (x == 5)
            {
                shop.saveProductsInFile();
            }
               

        }
    }
    else
    {
        cout << "Alegere gresite"<<endl;
    }
}
 
