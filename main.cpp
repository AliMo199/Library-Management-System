#include <iostream>
#include <string>
#include <unistd.h>
#include <conio.h>
#include "Container.h"
#include "Book.h"
#include "LibraryManagementSystem.h"
using namespace std;

int main(){
    LibraryManagementSystem library;
    char ch,ch1;
    Book b;
    string btitle;
    do{
        cout<<"\n\n\n\t\t\t\t\tLibrary Management System"
        <<"\n\n\t\t\t\t---------------------------------------"
        <<"\n\t\t\t\t1.Add a book."
        <<"\n\t\t\t\t2.Remove a book."
        <<"\n\t\t\t\t3.Book Catalog."
        <<"\n\t\t\t\t4.Search for a book."
        <<"\n\t\t\t\t5.Borrow a book."
        <<"\n\t\t\t\t6.Return a book."
        <<"\n\t\t\t\t7.Books statistics."
        <<"\n\t\t\t\t8.Exit."
        <<"\n\t\t\t\t---------------------------------------"
        <<"\n\t\t\t\tService no.?:";
        cin>>ch;
        switch(ch){
        case '1':
            system("cls");
            cout<<"\n\t\tAdd a book";
            cout<<"\n\n Enter book title: ";
            cin.ignore();
            getline(cin,b.title);
            cout<<"\n Enter book author: ";
            getline(cin,b.author);
            cout<<"\n Enter book ISBN no.: ";
            getline(cin,b.isbn);
            cout<<"\n Enter book genre: ";
            getline(cin,b.genre);
            b.available= true;
            library.AddBook(b);
            cout<<"\n\n\t ADDED TO CATALOG SUCCESSFULLY!...";
            sleep(2);
            system("cls");
            break;
        case '2':
            system("cls");
            cout<<"\n\t\tRemove a book\n";
            cout<<"\n\n Enter book title: ";
            cin.ignore();
            getline(cin,btitle);
            if(library.CheckSize()==-1){
                cout<<"\n\n\t ADD BOOKS TO CATALOG FIRST!...";
                sleep(2);
                system("cls");
                break;
            }else{
                if(library.FindByTitle(btitle)!=-1){
                    library.RemoveBook(btitle);
                    cout<<"\n\n\t REMOVED FROM CATALOG SUCCESSFULLY!...";
                    sleep(2);
                    system("cls");
                    break;
                }else{
                    cout<<"\n\n\t\t NO SUCH TITLE!...";
                    sleep(2);
                    system("cls");
                    break;
                }
            }
        case '3':
            system("cls");
            if(library.CheckSize()==-1){
                cout<<"\n\n\t ADD BOOKS TO CATALOG FIRST!...";
                sleep(2);
                system("cls");
                break;
            }else{
                cout<<"\n\t\tBook Catalog\n";
                library.PrintAllBooks();
                cout<<"\n\n\tPress any key when you are finished...";
                getch();
                system("cls");
                break;
            }
        case '4':
            do{
                system("cls");
                cout<<"\n\t\tSearch for a book\n";
                cout<<"\n\n\n 1.Search by title."
                <<"\n 2.Sort catalog Alphabetically by title."
                <<"\n 3.Return."
                <<"\n --------------------------------------"
                <<"\n Service no.:";
                cin>>ch1;
                switch(ch1){
                case '1':
                    system("cls");
                    cout<<"\n\t\tSearch by title\n"
                    <<"\n\n Enter book title: ";
                    cin.ignore();
                    getline(cin,btitle);
                    if(library.CheckSize()==-1){
                        cout<<"\n\n\t ADD BOOKS TO CATALOG FIRST!...";
                        sleep(2);
                        system("cls");
                        break;
                    }else{
                        if(library.FindByTitle(btitle)!=-1){
                            system("cls");
                            library.PrintIndex(library.FindByTitle(btitle));
                            cout<<"\n\n\tPress any key when you are finished...";
                            getch();
                            system("cls");
                        }else{
                            cout<<"\n\n\t\t NO SUCH TITLE!...";
                            sleep(2);
                        }
                        break;
                    }
                case '2':
                    system("cls");
                    if(library.CheckSize()==-1){
                        cout<<"\n\n\t ADD BOOKS TO CATALOG FIRST!...";
                        sleep(2);
                        system("cls");
                        break;
                    }else{
                        cout<<"\n\t\tTitle sorted catalog\n\n";
                        library.DisplaySorted();
                        cout<<"\n\n\tPress any key when you are finished...";
                        getch();
                        system("cls");
                        break;
                    }
                case '3':
                    break;
                default:
                    cout<<"\n\n\t\t No such service!...\n";
                    sleep(1);
                    break;
                }
            }while(ch1!='3');
            system("cls");
            break;
        case '5':
            system("cls");
            cout<<"\n\t\tBorrow a book\n";
            cout<<"\n\n Enter book title: ";
            cin.ignore();
            getline(cin,btitle);
            if(library.CheckSize()==-1){
                cout<<"\n\n\t ADD BOOKS TO CATALOG FIRST!...";
                sleep(2);
                system("cls");
                break;
            }else{
                if(library.FindByTitle(btitle)!=-1){
                    library.BorrowBook(btitle);
                    cout<<"\n\n\t BOOK BORROWED SUCCESSFULLY!...";
                    sleep(2);
                    system("cls");
                    break;
                }else{
                    cout<<"\n\n\t\t NO SUCH TITLE!...";
                    sleep(2);
                    system("cls");
                    break;
                }
            }
        case '6':
            system("cls");
            cout<<"\n\t\tReturn a book\n";
            cout<<"\n\n Enter book title: ";
            cin.ignore();
            getline(cin,btitle);
            if(library.CheckSize()==-1){
                cout<<"\n\n\t ADD BOOKS TO CATALOG FIRST!...";
                sleep(2);
                system("cls");
                break;
            }else{
                if(library.FindByTitle(btitle)!=-1){
                    library.ReturnBook(btitle);
                    cout<<"\n\n\t BOOK RETURNED SUCCESSFULLY!...";
                    sleep(2);
                    system("cls");
                    break;
                }else{
                    cout<<"\n\n\t\t NO SUCH TITLE!...";
                    sleep(2);
                    system("cls");
                    break;
                }
            }
        case '7':
            system("cls");
            cout<<"\n\t\tBooks Statistics\n"
            <<"\n\n TOTAL NUMBER OF BOOKS IN CATATLOG: "<<library.Totalbooks()
            <<"\n NUMBER OF AVAILABLE BOOKS: "<<library.AvailBooks()
            <<"\n NUMBER OF BORROWED BOOKS: "<<library.BorrBooks();
            cout<<"\n\n\n\tPress any key when you are finished...";
            getch();
            system("cls");
            break;
        case '8':
            break;
        default:
            cout<<"\n\n\t\t\t\t\t  No such service!...";
            sleep(2);
            system("cls");
            break;
        }
    }while(ch!='8');
    system("cls");
    cout<<"\n\n\n\t\t\t\t\t Thank you!...\n\n\n";
    return 0;
}

